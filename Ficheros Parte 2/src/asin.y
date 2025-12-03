/*****************************************************************************/
/**                        Analizador Sintáctico                            **/
/*****************************************************************************/

%{
#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto
#include "libtds.h"
#include <string.h>

void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;

int ref;    // referencia para arrays
int tipoRetornoActual; //guardar el tipo de retorno de las funciones
int numMain;

%}

%union{
        char *ident;
        int cent;
        ATRIBUTO attr;
        STRUCFUNC stf;
}

/* --- DECLARACIÓN DE TOKENS --- */

/* Palabras Reservadas */
%token INT_ BOOL_ TRUE_ FALSE_ RETURN_
%token READ_ PRINT_ IF_ ELSE_ FOR_

/* Identificadores y Constantes */
%token <ident> ID_ 
%token <cent> CTE_

/* Operadores Aritméticos, Lógicos y Relacionales */
%token MAS_ MENOS_ POR_ DIV_
%token NOT_ AND_ OR_
%token ASIG_ IGUAL_ DISTINTO_
%token MAYOR_ MENOR_ MAYORIGUAL_ MENORIGUAL_

/* Puntuación y Símbolos de Agrupación */
%token PARA_ PARC_           /* ( ) */
%token CORA_ CORC_           /* [ ] */
%token LLAVEA_ LLAVEC_       /* { } */
%token PUNTOCOMA_ COMA_     /* ; , */

//tipos para no terminales
%type <cent> tipoSimp
%type <cent> expre expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi expreOP paramForm listParamForm paramAct listParamAct
%type <cent> opLogic opIgual opRel opAd opMul opUna
%type <stf> declaFunc
%type <attr> const  


//verbose para errores
%define parse.error verbose

%%
/* --- REGLAS DE LA GRAMATICA --- */

programa:{niv = 0; cargaContexto(niv); dvar = 0; numMain = 0;/*doy valor a niv y dvar inicial para cuando lo usemos*/} listDecla{
                
                SIMB sim_main = obtTdS("main");
                if (sim_main.t == T_ERROR) {
                    yyerror("Debe existir una función 'main'");
                }
                if (numMain > 1){yyerror("El programa tiene más de un main");}
                //printf("Num mains %d \n", numMain);
                //mostrarTdS();   
        }
        ;

listDecla: decla
         | listDecla decla
         ;

decla:     declaVar
         | declaFunc
         ;

declaVar:  tipoSimp ID_ PUNTOCOMA_ 
        {
                int tipo = $1;
                int talla = 1;//como es un tipo simple = 1
                if (! insTdS($2, VARIABLE, tipo, niv, dvar, -1)){
                        yyerror("Identificador de variable repetido");
                } else{
                        dvar += talla;
                }
                
        }
         | tipoSimp ID_ ASIG_ const PUNTOCOMA_
        {
            // declaVar: tipoSimp ID_ ASIG_ const PUNTOCOMA_ (Variable Simple Inicializada)
            int tipo = $1;
            int talla = 1;

            if (tipo != $4.tipo) {
                yyerror("Incompatibilidad de tipos en la inicialización de variable");
            }
             if (! insTdS($2, VARIABLE, tipo, niv, dvar, -1)){
                yyerror("Identificador de variable repetido");
            } else{
                dvar += talla;
            }
        }
         | tipoSimp ID_ CORA_ CTE_ CORC_ PUNTOCOMA_ 
        {
            int tipo_elem = $1;
            int numelem = $4;//numero de elementos del array

            if (numelem <= 0) {
                yyerror("Talla inapropiada del array (debe ser positiva)");
                numelem = 0;
                //por si acaso
                ref = -1;
            }
            
            if (numelem > 0) {
                 ref = insTdA(tipo_elem, numelem); // Guarda info del array en TdA
            }
            
            if ( ! insTdS($2, VARIABLE, T_ARRAY, niv, dvar, ref)) { 
                yyerror ("Identificador de array repetido");
            } else{
                dvar += numelem;
            }
            
        }
         ;

const:     CTE_{$$.tipo = T_ENTERO; $$.cent = $1;}
         | TRUE_{$$.tipo = T_LOGICO; $$.cent = 1;}
         | FALSE_{$$.tipo = T_LOGICO; $$.cent = 0;}
         ;

tipoSimp:  INT_ {$$ = T_ENTERO;}
         | BOOL_ {$$ = T_LOGICO;}
         ;

declaFunc: tipoSimp ID_//creamos un struct para guardar tipo de retorno y desplazamiento anterior
    {
        tipoRetornoActual = $1;
        $<stf>$.tipoRetorno = $1;
        $<stf>$.despAnterior = dvar; // Usamos para guardar el dvar actual 
        niv++;     
        //dvar = 0;  
        dvar = TALLA_SEGENLACES + TALLA_ESTADO_MAQUINA; 
        cargaContexto(niv); 

    }
    PARA_ paramForm PARC_ 
    {
        //insertamos la función en el ámbito padre
        //printf("Entró en insertarfunción \n");
        if (strcmp($2, "main") == 0) { numMain += 1; }

        if (!insTdS($2, FUNCION, $1, niv - 1, -1, $5)) {
            yyerror("Identificación de función repetido");
            tipoRetornoActual = T_ERROR;
        }
    }
    {dvar = 0;}
    bloque
    {
        //mostrarTdS();
        descargaContexto(niv);
        niv--;
        /* Restauramos el dvar global */
        dvar = $<stf>3.despAnterior;
        // poner desplazamiento en bloque 
    }
         ;

paramForm: /* epsilon */
    { 
        /* Si no hay parámetros, creamos entrada vacía en TdD */
        $$ = insTdD(-1, T_VACIO); 
    }
        | listParamForm
    { 
        $$ = $1; 
    };

listParamForm: tipoSimp ID_
    {
        /* b04.c: Identificador de parametro repetido (en TDS local) */
        //printf("Entró en listaparámetros");

        // antes estaba en el else
        dvar += TALLA_TIPO_SIMPLE;
        if (!insTdS($2, PARAMETRO, $1, niv, -dvar, -1)) {
            yyerror("Identificador de parámetro repetido");
        } 
        /* Crear nueva entrada en TdD (final de la lista) */
        $$ = insTdD(-1, $1);
    }
            | tipoSimp ID_ COMA_ listParamForm
    {   
            // antes estaba en el else
            dvar += TALLA_TIPO_SIMPLE;

            if (!insTdS($2, PARAMETRO, $1, niv, -dvar, -1)) {
                yyerror("Identificador de parámetro repetido");
            }
        /* Insertar al principio de la lista existente */
        $$ = insTdD($4, $1);
    }
             ;

bloque: LLAVEA_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ 
    {
        /* b04.c: Error de tipos en el "return" */
        //hay que detectar si es un array, para decirle que no es  un tipo que pueda devolver
        if (tipoRetornoActual == T_ERROR){
            yyerror("No se puede comprobar el tipo del return porque no se instació la función");
        }
        else if ($5 != T_ERROR) {
            if ($5 != tipoRetornoActual) {
                yyerror("Error de tipos en el 'return'");
            }
        }
        
    }LLAVEC_;

declaVarLocal: /* epsilon */
             | declaVarLocal declaVar
             ;

listInst:  /* epsilon */
         | listInst inst
         ;

inst:      LLAVEA_ listInst LLAVEC_
         | instExpre
         | instEntSal
         | instSelec
         | instIter
         ;

instExpre: expre PUNTOCOMA_
         | PUNTOCOMA_
         ;

instEntSal: READ_ PARA_ ID_ PARC_ PUNTOCOMA_
    {
        /* b03.c: El argumento del "read" debe ser "entero" */
        SIMB sim = obtTdS($3);
        if (sim.t == T_ERROR) {
            yyerror("Objeto no declarado");
        } else if (sim.t != T_ENTERO) {
            yyerror("El argumento del \"read\" debe ser \"entero\"");
        }
    }
    | PRINT_ PARA_ expre PARC_ PUNTOCOMA_
    {
        /* b03.c: La expresion del "print" debe ser "entera" */
        if ($3 != T_ERROR && $3 != T_ENTERO) {
            yyerror("La expresion del \"print\" debe ser \"entera\"");
        }
    };

instSelec: IF_ PARA_ expre {
        /* b04.c: La expresion del `if' debe ser 'logico' */
        if ($3 != T_ERROR && $3 != T_LOGICO) {
            yyerror("La expresion del \"if\" debe ser \"logica\"");
        }
    } PARC_ inst ELSE_ inst
    ;

instIter:  FOR_ PARA_ expreOP PUNTOCOMA_ expre
    {
        /* b03.c: La expresion del "for" debe ser "logica" (la del medio $5) */
        if ($5 != T_ERROR && $5 != T_LOGICO) {
            yyerror("La expresion del \"for\" debe ser \"logica\"");
        }
    } PUNTOCOMA_ expreOP PARC_ inst
    {
        /* b02.c: La `expreOp' del `for' debe ser de tipo simple */
        if ($3 == T_ARRAY || $8 == T_ARRAY || $3 == T_ERROR || $8 == T_ERROR) {
                yyerror("La `expreOp' del `for' debe ser de tipo simple");
        }
    
    };

/* --- EXPRESIONES --- */
expreOP: /* epsilon */ { $$ = T_VACIO; } | expre ;

expre: expreLogic
     | ID_ ASIG_ expre 
     {
         SIMB sim = obtTdS($1);
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             $$ = T_ERROR;
         } else if (sim.t == T_ARRAY || sim.ref >= 0) { 
             /* b03.c: i = x (x es array) -> Error variable debe ser simple */
             /* Usamos sim.ref >= 0 para detectar funciones y arrays */
             yyerror("La variable debe ser de tipo simple"); 
             $$ = T_ERROR;
         } else if ($3 != T_ERROR) {
             if ($3 == T_ARRAY) {
                 /* b03.c: "El variable debe ser de tipo simple" para RHS array */
                 yyerror("La variable debe ser de tipo simple");
                 $$ = T_ERROR;
             } else if (sim.t != $3) {
                 yyerror("Error de tipos en la \"asignacion\"");
                 $$ = T_ERROR;
             } else {
                 $$ = sim.t;
             }
         } else {
             $$ = T_ERROR;
         }
     }
     | ID_ CORA_ expre CORC_ ASIG_ expre 
     {
         SIMB sim = obtTdS($1);
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             $$ = T_ERROR;
         } else {
             if (sim.t != T_ARRAY) {
                 /* b01.c error 17 */
                 yyerror("La variable debe ser de tipo \"array\"");
                 $$ = T_ERROR;
             } else {
                 if ($3 != T_ENTERO && $3 != T_ERROR) {
                     yyerror("El indice del \"array\" debe ser entero");
                 }
                 
                 DIM dim = obtTdA(sim.ref);
                 if ($6 != T_ERROR && dim.telem != $6) {
                     /* b01.c error 14 y 17 */
                     yyerror("Error de tipos en la asignacion a un `array'");
                     $$ = T_ERROR;
                 } else {
                     $$ = dim.telem;
                 }
             }
         }
     }
     ;

expreLogic: expreIgual 
          | expreLogic opLogic expreIgual
          {
              if ($1 != T_ERROR && $3 != T_ERROR) {
                  if ($1 != T_LOGICO || $3 != T_LOGICO) {
                      yyerror("Error en \"expresion logica\"");
                      $$ = T_ERROR;
                  } else $$ = T_LOGICO;
              } else $$ = T_ERROR;
          }
          ;

expreIgual: expreRel 
          | expreIgual opIgual expreRel 
          {
              if ($1 != T_ERROR && $3 != T_ERROR) {
                  if ($1 != $3) {
                    //printf("Entro en operando igual \n");
                      yyerror("Error en \"expresion de igualdad\"");
                      $$ = T_ERROR;
                  } else $$ = T_LOGICO;
              } else $$ = T_ERROR;
          }
          ;

expreRel: expreAd 
        | expreRel opRel expreAd 
        {  
            if ($1 != T_ERROR && $3 != T_ERROR) {
                if ($1 != T_ENTERO || $3 != T_ENTERO) {
                    yyerror("Error en \"expresion de relacional\"");
                    $$ = T_ERROR;
                } else $$ = T_LOGICO;
            } else $$ = T_ERROR;
        }
        ;

expreAd: expreMul 
       | expreAd opAd expreMul 
       {
           if ($1 != T_ERROR && $3 != T_ERROR) {
               if ($1 != T_ENTERO || $3 != T_ENTERO) {
                   yyerror("Error de tipos en \"expresion aditiva\"");
                   $$ = T_ERROR;
               } else $$ = T_ENTERO;
           } else $$ = T_ERROR;
       }
       ;

expreMul: expreUna 
        | expreMul opMul expreUna 
        {
            if ($1 != T_ERROR && $3 != T_ERROR) {
                if ($1 != T_ENTERO || $3 != T_ENTERO) {
                    yyerror("Error de tipos en \"expresion multiplicativa\"");
                    $$ = T_ERROR;
                } else $$ = T_ENTERO;
            } else $$ = T_ERROR;
        }        
        ;

expreUna: expreSufi 
        | opUna expreUna 
        {
            if ($2 != T_ERROR) {
                if ($1 == NOT_) { 
                    if ($2 != T_LOGICO) {
                        yyerror("Error en \"expresion unaria\"");
                        $$ = T_ERROR;
                    } else $$ = T_LOGICO;
                } else { 
                    if ($2 != T_ENTERO) {
                        yyerror("Error en \"expresion unaria\"");
                        $$ = T_ERROR;
                    } else $$ = T_ENTERO;
                }
            } else $$ = T_ERROR;
        }
        ;

expreSufi: const { $$ = $1.tipo; }
         | PARA_ expre PARC_ { $$ = $2; }
         | ID_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 $$ = T_ERROR;
             } else {
                 if (sim.t == T_ARRAY) $$ = T_ARRAY;
                 else $$ = sim.t;
             }
         }
         | ID_ CORA_ expre CORC_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 $$ = T_ERROR;
             } else if (sim.t != T_ARRAY) {
                 yyerror("La variable debe ser de tipo \"array\"");
                 $$ = T_ERROR;
             } else {
                 if ($3 != T_ENTERO && $3 != T_ERROR) 
                     yyerror("El indice del \"array\" debe ser entero");
                 
                 DIM dim = obtTdA(sim.ref);
                 $$ = dim.telem;
             }
         }
         | ID_ PARA_ paramAct PARC_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Función no declarada");
                 $$ = T_ERROR;
             } else {
                 
                 if (sim.ref == -1 && sim.t != T_ARRAY) {//si no es array pero ref == -1
                     yyerror("El identificador no es una función");
                     $$ = T_ERROR;
                 } else if (sim.t == T_ARRAY) {
                     yyerror("El identificador no es una función");
                     $$ = T_ERROR;
                 } else {
                     /* Es una función válida */
                     if (!cmpDom(sim.ref, $3)) {
                         yyerror("Error en el dominio de los parametros actuales");
                     }
                     $$ = sim.t;
                 }
             }
         }
         ;

paramAct: /* epsilon */ { $$ = insTdD(-1, T_VACIO); }//no hay parámetros
        | listParamAct  { $$ = $1; }
        ;

listParamAct: expre                    { $$ = insTdD(-1, $1); }//el primero es el último
            | expre COMA_ listParamAct { $$ = insTdD($3, $1); }//tomo la referencia del anterior que está en dolar1
            ;

opLogic:   AND_ { $$ = AND_; }
         | OR_  { $$ = OR_; }
         ;

opIgual:   IGUAL_    { $$ = IGUAL_; }
         | DISTINTO_ { $$ = DISTINTO_; }
         ;

opRel:     MAYOR_      { $$ = MAYOR_; }
         | MENOR_      { $$ = MENOR_; }
         | MAYORIGUAL_ { $$ = MAYORIGUAL_; }
         | MENORIGUAL_ { $$ = MENORIGUAL_; }
         ;

opAd:      MAS_   { $$ = MAS_; }
         | MENOS_ { $$ = MENOS_; }
         ;

opMul:     POR_ { $$ = POR_; }
         | DIV_ { $$ = DIV_; }
         ;

opUna:     MAS_   { $$ = MAS_; }
         | MENOS_ { $$ = MENOS_; }
         | NOT_   { $$ = NOT_; }
         ;

%%
/* --- CÓDIGO DE USUARIO --- */
