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
%type <attr> expre const expreLogic expreIgual expreRel expreAd expreMul expreUna expreSufi expreOP
%type <cent> declaFunc


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
         | FALSE_{$$.tipo = T_ENTERO; $$.cent = 0;}
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
            if (obtTdS($1).t == T_ERROR) { //Si no está declarada
                yyerror("Variable no declarada");
            }
        }
         | ID_ CORA_ expre CORC_ ASIG_ expre {
            if (obtTdS($1).t == T_ERROR) { //Si no está declarada
                yyerror("Variable no declarada");
            }
        }
         ;

expreLogic: expreIgual
          | expreLogic opLogic expreIgual
          ;

expreIgual: expreRel
          | expreIgual opIgual expreRel
          ;

expreRel:  expreAd
         | expreRel opRel expreAd
         ;

expreAd:   expreMul
         | expreAd opAd expreMul
         ;

expreMul:  expreUna
         | expreMul opMul expreUna
         ;

expreUna:  expreSufi
         | opUna expreUna
         ;

expreSufi: const
         | PARA_ expre PARC_
         | ID_
         | ID_ CORA_ expre CORC_
         | ID_ PARA_ paramAct PARC_
         ;

paramAct:  /* epsilon */
         | listParamAct
         ;

listParamAct: expre
            | expre COMA_ listParamAct
            ;

opLogic:   AND_
         | OR_
         ;

opIgual:   IGUAL_
         | DISTINTO_
         ;

opRel:     MAYOR_
         | MENOR_
         | MAYORIGUAL_
         | MENORIGUAL_
         ;

opAd:      MAS_
         | MENOS_
         ;

opMul:     POR_
         | DIV_
         ;

opUna:     MAS_
         | MENOS_
         | NOT_
         ;

%%
/* --- CÓDIGO DE USUARIO --- */
