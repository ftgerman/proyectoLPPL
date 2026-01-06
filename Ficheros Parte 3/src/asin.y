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
            //variables globales
            niv = 0;
            cargaContexto(niv);
            dvar = 0;
            numMain = 0;
            si=0;

            //reservamos espaio para globales
            //haríamos un crealans de si, pero como si vale 0, me lo salto
            emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));

            //saltamos a main
            $<cent>$ = creaLans(si);
            emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        } listDecla {
                
            SIMB sim_main = obtTdS("main");
            if (sim_main.t == T_ERROR) {
                yyerror("Debe existir una función 'main'");
            }else{
                //completamos dirección de main
                completaLans($<cent>1, crArgEtq(sim_main.d));

                //commpletamos reserva de espacio para variables globales
                int lista_globales = creaLans(0);
                completaLans(lista_globales, crArgEnt(dvar));

            }
            if (numMain > 1){yyerror("El programa tiene más de un main");}
            //printf("Num mains %d \n", numMain);
            //mostrarTdS();   


            if (numErrores == 0) {
            volcarCodigo("salida"); 
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

        //ahora en el desplazamiento de la función guardamos la instrucción en la que empieza
        if (!insTdS($2, FUNCION, $1, niv - 1, si, $5.cent)) {
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

bloque: LLAVEA_ 
    {
        //cargar enlaces de control
        emite(PUSHFP, crArgNul(), crArgNul(), crArgNul());
        emite(FPTOP, crArgNul(), crArgNul(), crArgNul());
        
        // Reservar espacio para variables locales y temporales
        $<cent>$ = creaLans(si);
        emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(-1));


    }
    declaVarLocal listInst RETURN_ expre PUNTOCOMA_ 
    {
        INF inf = obtTdD(-1); //información sobre función actual
        /* b04.c: Error de tipos en el "return" */
        if (tipoRetornoActual == T_ERROR){
            yyerror("No se puede comprobar el tipo del return porque no se instació la función");
        }
        else if ($6.tipo != T_ERROR) {
            if ($6.tipo != tipoRetornoActual) {
                yyerror("Error de tipos en el 'return'");
            }
            
            // Si la función devuelve algo, hay que ponerlo en el valor de retorno 
            // La dirección es: FP - (Enlaces + Parámetros + 1) 
            if ($6.tipo != T_VACIO) {
                int desp_retorno = -(TALLA_SEGENLACES + inf.tsp + 1);
                emite(EASIG, crArgPos(niv, $6.d), crArgNul(), crArgPos(niv, desp_retorno));
            }

            // Completar reserva espacio
            completaLans($<cent>2, crArgEnt(dvar));

            emite(TOPFP, crArgNul(), crArgNul(), crArgNul()); // SP = FP (Liberar locales)

            // Descargamos enlaces de control
            emite(FPPOP, crArgNul(), crArgNul(), crArgNul());

            // FIN si es main, RET sino.
            if (strcmp(inf.nom, "main") == 0) { 
                emite(FIN, crArgNul(), crArgNul(), crArgNul()); 
            } else {
                emite(RET, crArgNul(), crArgNul(), crArgNul()); 
            }

            /* G. Mostrar la información de la función en la TdS */
            if (verTdS) mostrarTdS();
        }

        


    }
    LLAVEC_
    ;

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

        //si todo correcto, genero código
        emite(EREAD, crArgNul(), crArgNul(), crArgPos(sim.n, sim.d));
    }
    | PRINT_ PARA_ expre PARC_ PUNTOCOMA_
    {
        /* b03.c: La expresion del "print" debe ser "entera" */
        if ($3.tipo != T_ERROR && $3.tipo != T_ENTERO) {
            yyerror("La expresion del \"print\" debe ser \"entera\"");
        }

        //si todo está correcto
        // usamos niv, pero si estamos imprimiendo el valor de una variable que esta en otro nivel (ej: desde funcion imprimimos var )
        emite(EWRITE, crArgNul(), crArgNul(), crArgPos(niv, $3.d));
    };

instSelec: IF_ PARA_ expre {
        /* b04.c: La expresion del `if' debe ser 'logico' */
        if ($3.tipo != T_ERROR && $3.tipo != T_LOGICO) {
            yyerror("La expresion del \"if\" debe ser \"logica\"");
        }
        //si la condición es falsa, debo saltar al else
        $<cent>$ = creaLans(si);
        emite(EIGUAL, crArgPos(niv, $3.d), crArgEnt(0), crArgEtq(-1));
    } PARC_ inst ELSE_ 
    {
        //despues de hacer el if, debe saltarse el else y terminar, pero como no sabemos donde termina aun
        $<cent>$ = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));

        //ahora sabemos donde empieza el else
        completaLans($<cent>4, crArgEtq(si));
    }inst
    {
        // completamos el esaldo de fin delif true
        completaLans($<cent>8, crArgEtq(si));
    }
    ;

instIter:  FOR_ PARA_ expreOP PUNTOCOMA_
    { 
        //guardamos posición de evaluar condición
        $<cent>$ = si; 
    }
    expre
    {
        /* b03.c: La expresion del "for" debe ser "logica" (la del medio $5) */
        if ($6.tipo != T_ERROR && $6.tipo != T_LOGICO) {
            yyerror("La expresion del \"for\" debe ser \"logica\"");
        }
        // si la condión es falsa, vamos al fin
        $<cent>$ = creaLans(si);
        emite(EIGUAL, crArgPos(niv, $6.d), crArgEnt(0), crArgEtq(-1));
        
        //salto al cuerpo
        $<cent>1 = creaLans(si);
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq(-1));
        
        // marco inicio del incremento
        $<cent>2 = si;
    } PUNTOCOMA_ expreOP PARC_
    {
        // despues de incrementar, evaluo condición
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>5));
        
        // Aquí empieza el CUERPO. Rellenar el salto a CUERPO ($7.dir)
        completaLans($<cent>1, crArgEtq(si));
    }
    inst
    {
        /* b02.c: La `expreOp' del `for' debe ser de tipo simple */
        if ($3.tipo == T_ARRAY || $9.tipo == T_ARRAY || $3.tipo == T_ERROR || $9.tipo == T_ERROR) {
                yyerror("La `expreOp' del `for' debe ser de tipo simple");
        }

        //vamos al incremento
        emite(GOTOS, crArgNul(), crArgNul(), crArgEtq($<cent>2));

        //completamos sabiendo el fin
        completaLans($<cent>7, crArgEtq(si));
    
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
         } else {
             $$.tipo = T_ERROR;
         }
     }
     | ID_ CORA_ expre CORC_ ASIG_ expre // vector[i] = valor
     {
         SIMB sim = obtTdS($1);
         if (sim.t == T_ERROR) {
             yyerror("Objeto no declarado");
             $$.tipo = T_ERROR;
         } else {
             if (sim.t != T_ARRAY) {
                 /* b01.c error en arrays */
                 yyerror("La variable debe ser de tipo \"array\"");
                 $$.tipo = T_ERROR;
             } else {
                 if ($3.tipo != T_ENTERO && $3.tipo != T_ERROR) {
                     yyerror("El indice del \"array\" debe ser entero");
                 }
                 DIM dim = obtTdA(sim.ref);
                 if ($6.tipo != T_ERROR && dim.telem != $6.tipo) {
                     /* b01.c comprobamos que el tipo del array es el mismo que el de expre */
                     yyerror("Error de tipos en la asignacion a un `array'");
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
                  } else {
                      $$.tipo = T_LOGICO;
                      $$.d = creaVarTemp();
                      if ($2 == AND_){
                        //AND implementado como multiplicación
                        emite(EMULT, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
                      }
                      else{
                        // OR como suma, revisando si es menor que 1 o no
                        emite(ESUM, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
                        //si el resultado es <=1, saltamos a fin, lo dejamos en 0
                        emite(EMENEQ, crArgPos(niv, $$.d), crArgEnt(1), crArgEtq(si + 2));
                        //si no, saltamos a si+2 y le ponemos valor 1
                        emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));

                      }
                  }
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
                  } else {
                    $$.tipo = T_LOGICO;
                    $$.d = creaVarTemp();
                    //asumiremos que la expresión se avalúa a verdadero
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));
                    //ahora, si se cumple, terminamos, saltando la asignación a 0
                    emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgEtq(si + 2));
                    //si no se cumplió, se ejetutará la asignación a 0 porque era falso
                    emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.d));
                  }
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
                } else {
                    $$.tipo = T_LOGICO;
                    $$.d = creaVarTemp();
                    //asumiremos que es true
                    emite(EASIG, crArgEnt(1), crArgNul(), crArgPos(niv, $$.d));
                    //evaluamos con el código de la operación que ha subido hasta dolar2
                    emite($2, crArgPos(niv, $1.d), crArgPos(niv, $3.d), crArgEtq(si + 2));
                    //si no saltó, asignamos a 0 porque era falso
                    emite(EASIG, crArgEnt(0), crArgNul(), crArgPos(niv, $$.d));
                }
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
                $$.tipo = sim.t;
                // --- MODIFICACIÓN: Gestión de Globales ---
                if (sim.n == 0 && niv > 0) { 
                    // Si es global (nivel 0) y estamos en una función (niv > 0):
                    // 1. Creamos una temporal local
                    int temp = creaVarTemp();
                    
                    // 2. Emitimos una instrucción para copiar el valor global a la local
                    //    Global: p(0, sim.d) -> Local: p(niv, temp)
                    emite(EASIG, crArgPos(sim.n, sim.d), crArgNul(), crArgPos(niv, temp));
                    
                    // 3. Devolvemos la temporal
                    $$.d = temp;
                } else {
                    // Si es local o estamos en el main (niv 0), se usa tal cual
                    // no hace falta crear una temporal en este caso
                    $$.d = sim.d;
                }

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

                 //creamos var temporal para emitir EAV
                 $$.d = creaVarTemp();
                 emite(EAV, crArgPos(sim.n, sim.d), crArgPos(niv, $3.d), crArgPos(niv, $$.d));
             }
         }
         | ID_ 
         {
            SIMB sim = obtTdS($1);
            // Reservar espacio para el retorno (si no es void)
            if (sim.t != T_VACIO && sim.t != T_ERROR) {
                emite(INCTOP, crArgNul(), crArgNul(), crArgEnt(1));//por talla simple
            }
            

         }
         PARA_ paramAct PARC_ 
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
                     if (!cmpDom(sim.ref, $4.cent)) {
                         yyerror("Error en el dominio de los parametros actuales");
                     }
                     $$.tipo = sim.t;

                     // Obtenemos la información de la función desde la TdD usando la referencia
                    INF inf = obtTdD(sim.ref); 

                    // --- GENERACIÓN DE CÓDIGO LLAMADA ---
                    // 1. Llamar a la función
                    emite(CALL, crArgNul(), crArgNul(), crArgEtq(sim.d));
                    
                    // 2. Limpiar argumentos de la pila (DECTOP)
                    // Usamos inf.tsp en lugar de sim.tsp
                    if (inf.tsp > 0) {
                        emite(DECTOP, crArgNul(), crArgNul(), crArgEnt(inf.tsp));
                    }

                    // 3. Recuperar el resultado
                    $$.tipo = sim.t;
                    if (sim.t != T_VACIO) {
                        // El resultado está en la cima. Lo pasamos a un temporal
                        $$.d = creaVarTemp();
                        emite(EPOP, crArgNul(), crArgNul(), crArgPos(niv, $$.d));
                    }
                 }
             }
         }
         ;

paramAct: /* epsilon */ { $$.cent = insTdD(-1, T_VACIO); }//no hay parámetros
        | listParamAct  { $$ = $1; }
        ;

listParamAct: expre 
    { 
        // Apilamos el parámetro
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.d));
    }
    COMA_ listParamAct 
    { 
        // Creamos lista con los tipos de los parámetros para comprobar más arriba si son los mismos que los definidos en la TDS
        $$.cent = insTdD($4.cent, $1.tipo);
    }
    | expre 
    { 
        // Último parámetro
        emite(EPUSH, crArgNul(), crArgNul(), crArgPos(niv, $1.d));
        
        $$.cent = insTdD(-1, $1.tipo);
    }
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
         | MENOS_ { $$ = ESIG; } // Aqui ponia EDIF
         | NOT_   { $$ = NOT_; }
         ;

%%
/* --- CÓDIGO DE USUARIO --- */
