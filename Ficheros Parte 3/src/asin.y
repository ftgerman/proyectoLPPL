/*****************************************************************************/
/**                        Analizador Sintáctico                            **/
/*****************************************************************************/

/*****************************************************************************/
/**                        Jorge Rodríguez González                         **/
/**                        Julián Cussianovich Porto                        **/
/**                        Germán Soria Bustos                              **/
/*****************************************************************************/

%{
#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto
#include "libtds.h"
#include "libgci.h"
#include <string.h> //añadido para contar cantidad de funciones main

void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;

int ref;    // referencia para arrays
int tipoRetornoActual; //guardar el tipo de retorno de las funciones para errores del return
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
//actualizamos algunos a atributos para la GCI
%type <cent> tipoSimp
%type <attr> expre expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi expreOP paramForm listParamForm paramAct listParamAct
%type <cent> opLogic opIgual opRel opAd opMul opUna
%type <attr> declaFunc
%type <attr> const  


//verbose para errores
%define parse.error verbose

%%
/* --- REGLAS DE LA GRAMATICA --- */

programa:{
            niv = 0;
            cargaContexto(niv);
            dvar = 0;
            numMain = 0;
            si=0;// damos valor a siguiente instruccion

            emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));//vamos al main, habrá que usar un crealans
        } listDecla {
                
            SIMB sim_main = obtTdS("main");
            if (sim_main.t == T_ERROR) {
                yyerror("Debe existir una función 'main'");
            }
            if (numMain > 1){yyerror("El programa tiene más de un main");}
            //printf("Num mains %d \n", numMain);
            //mostrarTdS();   

            //ahora deberíamos rellanar el salto inicial


            if (numErrores == 0) {
            volcarCodigo("salida"); // El nombre suele ser el del fichero de entrada
        }
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
                SIMB s = obtTdS($2);
                emite(EASIG, crArgEnt($4.cent), crArgNul(), crArgPos(s.n, s.d));//asignamos valor de dolar4 que es una constante a la variable ID_
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

declaFunc: tipoSimp ID_
    {
        tipoRetornoActual = $1;//var global
        $<cent>$ = dvar; // Usamos para guardar el dvar actual 
        niv++;     
        dvar = TALLA_SEGENLACES + TALLA_ESTADO_MAQUINA; 
        cargaContexto(niv); 

    }
    PARA_ paramForm PARC_ 
    {
        //insertamos la función en el ámbito padre
        //printf("Entró en insertarfunción \n");
        if (strcmp($2, "main") == 0) { numMain += 1; }//para contar funciones main, error de b04

        if (!insTdS($2, FUNCION, $1, niv - 1, -1, $5.cent)) {
            yyerror("Identificación de función repetido");
            tipoRetornoActual = T_ERROR;
        }
    }
    {dvar = 0;}
    bloque
    {
        mostrarTdS();
        descargaContexto(niv);
        niv--;
        /* Restauramos el dvar global */
        dvar = $<cent>3;
        // poner desplazamiento en bloque 
    }
         ;

paramForm: /* epsilon */
    { 
        /* Si no hay parámetros, creamos entrada vacía en TdD */
        $$.cent = insTdD(-1, T_VACIO); 
    }
        | listParamForm
    { 
        $$ = $1; 
    };

listParamForm: tipoSimp ID_
    {
        /* b04.c: Identificador de parametro repetido */
        //printf("Entró en listaparámetros");

        // antes estaba en el else
        dvar += TALLA_TIPO_SIMPLE;
        if (!insTdS($2, PARAMETRO, $1, niv, -dvar, -1)) {
            yyerror("Identificador de parámetro repetido");
        } 
        /* Crear nueva entrada en TdD (final de la lista) */
        $$.cent = insTdD(-1, $1);
    }
            | tipoSimp ID_ COMA_ listParamForm
    {   
            // antes estaba en el else
            dvar += TALLA_TIPO_SIMPLE;

            if (!insTdS($2, PARAMETRO, $1, niv, -dvar, -1)) {
                yyerror("Identificador de parámetro repetido");
            }
        /* Insertar al principio de la lista existente */
        $$.cent = insTdD($4.cent, $1);
    }
             ;

bloque: LLAVEA_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ 
    {
        /* b04.c: Error de tipos en el "return" */
        if (tipoRetornoActual == T_ERROR){
            yyerror("No se puede comprobar el tipo del return porque no se instació la función");
        }
        else if ($5.tipo != T_ERROR) {
            if ($5.tipo != tipoRetornoActual) {
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
        if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO) {
            yyerror("La expresion del \"print\" debe ser \"entera\"");
        }
    };

instSelec: IF_ PARA_ expre {
        /* b04.c: La expresion del `if' debe ser 'logico' */
        if ($3.tipo != T_ERROR && $3.tipo != T_LOGICO) {
            yyerror("La expresion del \"if\" debe ser \"logica\"");
        }
    } PARC_ inst ELSE_ inst
    ;

instIter:  FOR_ PARA_ expreOP PUNTOCOMA_ expre
    {
        /* b03.c: La expresion del "for" debe ser "logica" (la del medio $5) */
        if ($5.tipo != T_ERROR && $5.tipo != T_LOGICO) {
            yyerror("La expresion del \"for\" debe ser \"logica\"");
        }
    } PUNTOCOMA_ expreOP PARC_ inst
    {
        /* b02.c: La `expreOp' del `for' debe ser de tipo simple */
        if ($3.tipo == T_ARRAY || $8.tipo == T_ARRAY || $3.tipo == T_ERROR || $8.tipo == T_ERROR) {
                yyerror("La `expreOp' del `for' debe ser de tipo simple");
        }
    
    };

/* --- EXPRESIONES --- */
expreOP: /* epsilon */ { $$.tipo = T_VACIO; } | expre ;

expre: expreLogic
     | ID_ ASIG_ expre 
     {
         SIMB sim = obtTdS($1);
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             $$.tipo = T_ERROR;
         } else if (sim.t == T_ARRAY || sim.ref >= 0) { 
             /* b03.c: i = x (x es array) -> Error variable debe ser simple */
             /* Usamos ref >= 0 para detectar funciones y arrays */
             yyerror("La variable debe ser de tipo simple"); 
             $$.tipo = T_ERROR;
         } else if ($3.tipo != T_ERROR) {
             if ($3.tipo == T_ARRAY) {
                 /* b03.c: "El variable debe ser de tipo simple" para RHS array */
                 yyerror("La variable debe ser de tipo simple");
                 $$.tipo = T_ERROR;
             } else if (sim.t != $3.tipo) {
                 yyerror("Error de tipos en la \"asignacion\"");
                 $$.tipo = T_ERROR;
             } else {
                 $$.tipo = sim.t;
                 $$.d = sim.d;
                 emite(EASIG, crArgPos(niv, $3.d), crArgNul(), crArgPos(sim.n, sim.d));

             }
         } else { // si esta todo correcto
             $$.tipo = T_ERROR;
             $$.d = sim.d; // el resultado de la asignación es la propia variable
             emite(EASIG, crArgPos(niv, $3.d), crArgNul(), crArgPos(sim.n, sim.d));
         }
     }
     | ID_ CORA_ expre CORC_ ASIG_ expre 
     {
         SIMB sim = obtTdS($1);
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             $$.tipo = T_ERROR;
             $$.tipo = T_ERROR;
         } else {
             if (sim.t != T_ARRAY) {
                 /* b01.c error en arrays */
                 yyerror("La variable debe ser de tipo \"array\"");
                 $$.tipo = T_ERROR;
                 $$.tipo = T_ERROR;
             } else {
                 if ($3.tipo != T_ENTERO && $3.tipo != T_ERROR) {
                 if ($3.tipo != T_ENTERO && $3.tipo != T_ERROR) {
                     yyerror("El indice del \"array\" debe ser entero");
                 }
                 
                 DIM dim = obtTdA(sim.ref);
                 if ($6.tipo != T_ERROR && dim.telem != $6.tipo) {
                 if ($6.tipo != T_ERROR && dim.telem != $6.tipo) {
                     /* b01.c comprobamos que el tipo del array es el mismo que el de expre */
                     yyerror("Error de tipos en la asignacion a un `array'");
                     $$.tipo = T_ERROR;
                     $$.tipo = T_ERROR;
                 } else {
                     $$.tipo = dim.telem;
                     emite(EVA, crArgPos(sim.n, sim.d), crArgPos(niv, $3.d), crArgPos(niv, $6.d));
                 }
             }
         }
     }
     ;

expreLogic: expreIgual 
          | expreLogic opLogic expreIgual
          {
              if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
                  if ($1.tipo != T_LOGICO || $3.tipo != T_LOGICO) {
                      yyerror("Error en \"expresion logica\"");
                      $$.tipo = T_ERROR;
                  } else $$.tipo = T_LOGICO;
              } else $$.tipo = T_ERROR;
          }
          ;

expreIgual: expreRel 
          | expreIgual opIgual expreRel 
          {
              if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
                  if ($1.tipo != $3.tipo) {
                    //printf("Entro en operando igual \n");
                      yyerror("Error en \"expresion de igualdad\"");
                      $$.tipo = T_ERROR;
                  } else $$.tipo = T_LOGICO;
              } else $$.tipo = T_ERROR;
          }
          ;

expreRel: expreAd 
        | expreRel opRel expreAd 
        {  
            if ($1.tipo != T_ERROR && $3.tipo != T_ERROR) {
                if ($1.tipo != T_ENTERO || $3.tipo != T_ENTERO) {
                    yyerror("Error en \"expresion relacional\"");
                    $$.tipo = T_ERROR;
                } else $$.tipo = T_LOGICO;
            } else $$.tipo = T_ERROR;
        }
        ;

expreAd: expreMul 
       | expreAd opAd expreMul 
       {
        //ejemplo del enunciado
            $$.tipo = T_ERROR;
            if (($1.tipo == T_ENTERO) && ($3.tipo == T_ENTERO)) $$.tipo = T_ENTERO;
            else yyerror("Error de tipos en \"expresion aditiva\"");
            $$.d = creaVarTemp();
            /***************** Expresion a partir de operador arimetico */
            emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));

       }
       ;

expreMul: expreUna 
        | expreMul opMul expreUna 
        {
            $$.tipo = T_ERROR;
            if (($1.tipo == T_ENTERO) && ($3.tipo == T_ENTERO)) $$.tipo = T_ENTERO;
            else yyerror("Error de tipos en \"expresion multiplicativa\"");
            $$.d = creaVarTemp();
            /***************** Expresion a partir de operador arimetico */
            emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
        }        
        ;

expreUna: expreSufi 
        | opUna expreUna 
        {
            if ($2.tipo != T_ERROR) {
                if ($1 == NOT_) { 
                    if ($2.tipo != T_LOGICO) {
                        yyerror("Error en \"expresion unaria\"");
                        $$.tipo = T_ERROR;
                    } else {
                        $$.tipo = T_LOGICO;
                        $$.d = creaVarTemp();
                        
                        // Para negar x, hacemos 1-x
                        // si x = 1 (true) -> 1-1 = 0 (false)
                        // si x = 0 (false) -> 1-0 = 1 (true)
                        emite(EDIF, crArgEnt(1), crArgPos(niv, $2.d), crArgPos(niv, $$.d));
                    } 
                } else { // + o -
                    if ($2.tipo != T_ENTERO) {
                        yyerror("Error en \"expresion unaria\"");
                        $$.tipo = T_ERROR;
                    } else {
                        $$.tipo = T_ENTERO;

                        if ($1 == ESIG) {
                            // caso -x
                            $$.d = creaVarTemp();
                            emite(ESIG, crArgPos(niv, $2.d), crArgNul(), crArgPos(niv, $$.d));
                        } 
                        else {
                            // caso +x
                            $$.d = $2.d;
                        } 
                    }
                }
            } else $$.tipo = T_ERROR;
        }
        ;

expreSufi: const { $$.tipo = $1.tipo; 
                   $$.d = creaVarTemp();
                   emite(EASIG, crArgEnt($1.cent), crArgNul(), crArgPos(niv, $$.d));
                 }
         | PARA_ expre PARC_ { $$ = $2; }
         | ID_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                yyerror("Objeto no declarado");
                $$.tipo = T_ERROR;
             } else {
                //guardamos tipo y desplazamiento para subirlo GCI
                $$.tipo = sim.t;
                $$.d = sim.d;
             }
         }
         | ID_ CORA_ expre CORC_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Objeto no declarado");
                 $$.tipo = T_ERROR;
             } else if (sim.t != T_ARRAY) {
                 yyerror("La variable debe ser de tipo \"array\"");
                 $$.tipo = T_ERROR;
             } else {
                 if ($3.tipo != T_ENTERO && $3.tipo != T_ERROR) 
                     yyerror("El indice del \"array\" debe ser entero");
                 
                 DIM dim = obtTdA(sim.ref);
                 $$.tipo = dim.telem;
             }
         }
         | ID_ PARA_ paramAct PARC_ 
         {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Función no declarada");
                 $$.tipo = T_ERROR;
             } else {
                 
                 if (sim.ref == -1 && sim.t != T_ARRAY) {//si no es array pero ref == -1
                     yyerror("El identificador no es una función");
                     $$.tipo = T_ERROR;
                 } else if (sim.t == T_ARRAY) {
                     yyerror("El identificador no es una función");
                     $$.tipo = T_ERROR;
                 } else {
                     /* Es una función válida */
                     if (!cmpDom(sim.ref, $3.cent)) {
                         yyerror("Error en el dominio de los parametros actuales");
                     }
                     $$.tipo = sim.t;
                 }
             }
         }
         ;

paramAct: /* epsilon */ { $$.cent = insTdD(-1, T_VACIO); }//no hay parámetros
        | listParamAct  { $$ = $1; }
        ;

listParamAct: expre                    { $$.cent = insTdD(-1, $1.tipo); }//el primero es el último
            | expre COMA_ listParamAct { $$.cent = insTdD($3.cent, $1.tipo); }//tomo la referencia del anterior que está en dolar1
            ;

opLogic:   AND_ { $$ = AND_; }
         | OR_  { $$ = OR_; }
         ;

opIgual:   IGUAL_    { $$ = EIGUAL; }
         | DISTINTO_ { $$ = EDIST; }
         ;

opRel:     MAYOR_      { $$ = EMAY; }
         | MENOR_      { $$ = EMEN; }
         | MAYORIGUAL_ { $$ = EMAYEQ; }
         | MENORIGUAL_ { $$ = EMENEQ; }
         ;

opAd:      MAS_   { $$ = ESUM; }
         | MENOS_ { $$ = EDIF; }
         ;

opMul:     POR_ { $$ = EMULT; }
         | DIV_ { $$ = EDIVI; }
         ;

opUna:     MAS_   { $$ = ESUM; }
         | MENOS_ { $$ = EDIF; }
         | NOT_   { $$ = NOT_; }
         ;

%%
/* --- CÓDIGO DE USUARIO --- */
