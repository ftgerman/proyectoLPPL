/*****************************************************************************/
/**                        Analizador Sintáctico                            **/
/*****************************************************************************/

%{
#include <stdio.h>
#include "header.h" // Fichero de cabeceras del proyecto


void yyerror(const char *s);
extern int yylex();
extern int yylineno;
extern char *yytext;
%}

/* --- DECLARACIÓN DE TOKENS --- */

/* Palabras Reservadas */
%token INT_ BOOL_ TRUE_ FALSE_ RETURN_
%token READ_ PRINT_ IF_ ELSE_ FOR_

/* Identificadores y Constantes */
%token ID_ CTE_

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

//verbose para errores
%define parse.error verbose

%%
/* --- REGLAS DE LA GRAMATICA --- */

programa: listDecla
        ;

listDecla: decla
         | listDecla decla
         ;

decla:     declaVar
         | declaFunc
         ;

declaVar:  tipoSimp ID_ PUNTOCOMA_
         | tipoSimp ID_ ASIG_ const PUNTOCOMA_
         | tipoSimp ID_ CORA_ CTE_ CORC_ PUNTOCOMA_
         ;

const:     CTE_
         | TRUE_
         | FALSE_
         ;

tipoSimp:  INT_
         | BOOL_
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
         | ID_ ASIG_ expre
         | ID_ CORA_ expre CORC_ ASIG_ expre
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
