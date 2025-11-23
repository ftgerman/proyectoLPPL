/*****************************************************************************/
/**                        Analizador Sintáctico                            **/
/*****************************************************************************/

%{
#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto
#include "libtds.h"

void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;

int ref;    // referencia para arrays


%}

%union{
        char *ident;
        int cent;
        ATRIBUTO attr;
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
%type <cent> expre expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi expreOP
%type <cent> opLogic opIgual opRel opAd opMul opUna
%type <cent> declaFunc
%type <attr> const  


//verbose para errores
%define parse.error verbose

%%
/* --- REGLAS DE LA GRAMATICA --- */

programa:{niv = 0; cargaContexto(niv); dvar = 0;/*doy valor a niv y dvar inicial para cuando lo usemos*/} listDecla{
                
                SIMB sim_main = obtTdS("main");
                if (sim_main.t == T_ERROR || sim_main.t != FUNCION) {
                    yyerror("Debe existir una función 'main'");
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
                        yyerror("Identificador repetido");
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
            } else if (! insTdS($2, VARIABLE, tipo, niv, dvar, -1)){
                yyerror("Identificador repetido");
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
            }
            
            if (numelem > 0) {
                 ref = insTdA(tipo_elem, numelem); // Guarda info del array en TdA
            }
            
            if ( ! insTdS($2, VARIABLE, T_ARRAY, niv, dvar, ref)) { 
                yyerror ("Identificador repetido");
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

declaFunc: tipoSimp ID_ PARA_ paramForm PARC_ bloque
         ;

paramForm: /* epsilon */
         | listParamForm
         ;

listParamForm: tipoSimp ID_
             | tipoSimp ID_ COMA_ listParamForm
             ;

bloque:    LLAVEA_ declaVarLocal listInst RETURN_ expre PUNTOCOMA_ LLAVEC_
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
          | PRINT_ PARA_ expre PARC_ PUNTOCOMA_
          ;

instSelec: IF_ PARA_ expre PARC_ inst ELSE_ inst
         ;

instIter:  FOR_ PARA_ expreOP PUNTOCOMA_ expre PUNTOCOMA_ expreOP PARC_ inst
         ;

expreOP:   /* epsilon */
         | expre
         ;

expre:     expreLogic
         | ID_ ASIG_ expre {
            SIMB sim = obtTdS($1);
            if (sim.t == T_ERROR) {
                yyerror("Objeto no declarado");
                $$ = T_ERROR; 
            } else if (sim.t != $3) {
                yyerror("Tipos incompatibles en la asignación");
                $$ = T_ERROR;
            } else {
                $$ = sim.t;
            }
        }
         | ID_ CORA_ expre CORC_ ASIG_ expre {
            SIMB sim = obtTdS($1);
            if (sim.t == T_ERROR) {
                yyerror("Objeto no declarado");
                $$ = T_ERROR;
            } else {
                // 1. Validar que el índice sea entero
                if ($3 != T_ENTERO) {
                    yyerror("El índice del array debe ser entero");
                }

                // 2. Obtener el tipo real del elemento del array
                DIM infoArray = obtTdA(sim.ref);
                
                // 3. Validar que lo que asignamos coincida con lo que guarda el array
                if (infoArray.telem != $6) {
                    yyerror("Tipos incompatibles en la asignación al array");
                }
                $$ = $6; 
            }
        }
        ;
expreLogic: expreIgual {$$ = $1;}
          | expreLogic opLogic expreIgual
          {
            // opLogic = && o ||
            if($1 != T_LOGICO || $3 != T_LOGICO) yyerror("Error de tipos en la asignacion");
                
            $$ = T_LOGICO;
         }
          ;

expreIgual: expreRel {$$ = $1;}
          | expreIgual opIgual expreRel 
          {
            // if($2 != T_LOGICO || $4 != T_LOGICO){
            // no tienen porque ser logicos, pueden ser enteros. Lo importante es que sean del mismo tipo.

            if($1 != $3) yyerror("Comparación de tipos distintos");
            $$ = T_LOGICO;

            }
          ;

expreRel:  expreAd {$$ = $1;}
         | expreRel opRel expreAd 
         {  
            if($1 != T_LOGICO || $3 != T_LOGICO){
                yyerror("Error de tipos en la asignacion");
            }else{
                $$ = T_LOGICO;
            }
         }
         ;

expreAd:   expreMul {$$ = $1;}
         | expreAd opAd expreMul 
         {
            // Caso + o -: $1 y $3 deben ser enteros
            if($1 != T_ENTERO || $3 != T_ENTERO){
                yyerror("Operación aritmética requiere enteros");
            }
            
            $$ = T_ENTERO;
        }
         ;

expreMul:  expreUna {$$ = $1;}
         | expreMul opMul expreUna 
         {
            // Caso *, /: $1 y $3 deben ser enteros
            if ($1 != T_ENTERO || $3 != T_ENTERO) {
                yyerror("Operación multiplicación requiere enteros");
            }
            $$ = T_ENTERO;
        }        
         ;

expreUna:  expreSufi {$$ = $1;}
         | opUna expreUna {
            // Caso !: $2 se debe ser logico ()
            if ($1 == NOT_) { 
                if ($2 != T_LOGICO) {
                    yyerror("El operador ! requiere tipo lógico");
                }
                $$ = T_LOGICO;
            } else { 
                // Casos + o -: requieren entero
                if ($2 != T_ENTERO) {
                    yyerror("Se requiere tipo entero");
                }
                $$ = T_ENTERO;
            }
        };

expreSufi: const {$$ = $1.tipo;}
         | PARA_ expre PARC_ {$$ = $2;}
         | ID_ {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) yyerror("Identificador no declarado");
             $$ = sim.t; // tipo del identificador o error si no existe
           }
         | ID_ CORA_ expre CORC_ {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) {
                 yyerror("Array no declarado");
                 $$ = T_ERROR;
             } else {
                 if ($3 != T_ENTERO) yyerror("El índice del array debe ser entero");
                 
                 // $$ = obtTdS($1).t; lo que habia hecho Julián.
                 // Yo entiendo que 1 + array[i] es correcto, siempre que el array sea de enteros.
                 // si usamos $$ = obtTdS($1).t; entonces 1 + array[i] da error de tipos porque obtTdS($1).t es T_ARRAY

                 DIM infoArray = obtTdA(sim.ref);
                 $$ = infoArray.telem;  //tipo de elemento del array
             }
           }
         | ID_ PARA_ paramAct PARC_ {
             SIMB sim = obtTdS($1);
             if (sim.t == T_ERROR) yyerror("Función no declarada");
             $$ = sim.t; // Asumo que en TdS se guarda el tipo de retorno en .t
           }
         ;

paramAct:  /* epsilon */
         | listParamAct
         ;

listParamAct: expre
            | expre COMA_ listParamAct
            ;

opLogic:   AND_ { $$  = AND_; }
         | OR_ { $$  = OR_; }
         ;

opIgual:   IGUAL_ { $$  = IGUAL_; }
         | DISTINTO_ { $$  = DISTINTO_; }
         ;

opRel:     MAYOR_ { $$  = MAYOR_; }
         | MENOR_ { $$  = MENOR_; }
         | MAYORIGUAL_ { $$  = MAYORIGUAL_; }
         | MENORIGUAL_ { $$  = MENORIGUAL_; }
         ;

opAd:      MAS_ { $$  = MAS_; }
         | MENOS_ { $$  = MENOS_; }
         ;

opMul:     POR_ { $$  = POR_; }
         | DIV_ { $$  = DIV_; }
         ;

opUna:     MAS_ { $$  = MAS_; }
         | MENOS_ { $$  = MENOS_; }
         | NOT_ { $$  = NOT_; }
         ;

%%
/* --- CÓDIGO DE USUARIO --- */
