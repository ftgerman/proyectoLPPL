%{
#include <stdio.h>
#include "header.h"
#include "asin.h"


#define retornar(x) {if (verbosidad) ECHO;return x;}
%}

%option noinput
%option nounput
%option yylineno



delimitador [ \t]
letra       [a-zA-Z_]
digito      [0-9]
id          {letra}({letra}|{digito})*
entero      {digito}+
real        {digito}+\.{digito}*|\.{digito}+
comentario  "//".*

%%
{delimitador}+ { if (verbosidad) ECHO; }
\n             { if (verbosidad) { ECHO; fprintf(stdout, "%3d.- ", yylineno); } }
{comentario}  { if (verbosidad) ECHO; }
"int"        { retornar(INT_); }
"bool"       { retornar(BOOL_); }
"true"       { retornar(TRUE_); }
"false"      { retornar(FALSE_); }
"return"     { retornar(RETURN_); }
"read"       { retornar(READ_); }
"print"      { retornar(PRINT_); }
"if"         { retornar(IF_); }
"else"       { retornar(ELSE_); }
"for"        { retornar(FOR_); }
"+"          { retornar(MAS_); }
"-"          { retornar(MENOS_); }
"*"          { retornar(POR_); }
"/"          { retornar(DIV_); }
"!"          { retornar(NOT_); }
"&&"         { retornar(AND_); }
"||"         { retornar(OR_); }
"="          { retornar(ASIG_); }
"=="         { retornar(IGUAL_); }
"!="         { retornar(DISTINTO_); }
">"          { retornar(MAYOR_); }
"<"          { retornar(MENOR_); }
">="         { retornar(MAYORIGUAL_); }
"<="         { retornar(MENORIGUAL_); }
"("          { retornar(PARA_); }
")"          { retornar(PARC_); }
"["          { retornar(CORA_); }
"]"          { retornar(CORC_); }
"{"          { retornar(LLAVEA_); }
"}"          { retornar(LLAVEC_); }
";"          { retornar(PUNTOCOMA_); }
","          { retornar(COMA_); }
{id}         { yylval.ident = strdup(yytext); retornar(ID_); }
{real}          { 
                    //truncar a entero
                    double val = strtod(yytext, NULL);
                    yylval.cent = (int)val;//casting a entero 
                    retornar(CTE_);
                }
{entero}        { yylval.cent = atoi(yytext); retornar(CTE_); }
.            { 
                if (verbosidad) ECHO;
                char msg[100];
                sprintf(msg, "Error Lexico: Caracter no reconocido: %s", yytext);
                yyerror(msg);
            }
%%