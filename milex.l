%{
#include "mycomp.tab.h"
#include <string.h>
/*#define ENTERO 257
#define REAL 258
#define FOR 259
#define WHILE 260
#define INT 261
#define DOUBLE 262
#define CHAR 263
#define BOOLEAN 264
#define IF 265
#define ELSE 266
#define FUNCT 267
#define MAIN 268
#define RETURN 270
#define PRINT 271
#define BREAK 272
#define CONTINUE 273
#define STRING 275
#define ID 277
#define COMP 278*/
int numlin = 1;
void error(char*);
%}
letra [a-zA-Z]
digito [0-9]
letdig {letra}|{digito}
stringText [^\";]
%%
[-=;\[\]{}(),\+*\^/] {return yytext[0];}
{digito}+ { yylval.entero = atoi(yytext); return ENTERO;   }
{digito}+\.{digito}+ {  yylval.real = atof(yytext); return REAL; }

"while" {return WHILE;}
"if" {return IF;}
"else" {return ELSE;}
"fun" {return FUNCT;}
"Main" {return MAIN;}
"return" {return RETURN;}
"print" {return PRINT;}


"int"    { yylval.type = 'i'; return TYPE; }
"double" { yylval.type = 'd'; return TYPE; }

\"([^\\"])*\"   { strncpy(yylval.stringLiteral,&yytext[1],yyleng-2); yylval.stringLiteral[yyleng-2] = '\0'; return STRINGLITERAL; }

{letra}+{digito}* { sscanf(yytext, "%s", yylval.name); return ID; }

"=="	{ yylval.comp = 1; return COMP; }
"!="	{ yylval.comp = 2; return COMP; }
">"	    { yylval.comp = 3; return COMP; }
"<"	    { yylval.comp = 4; return COMP; }
">="	{ yylval.comp = 5; return COMP; }
"<="	{ yylval.comp = 6; return COMP; }


\n {numlin++;}
[ \t] |
^#.* {/* ignora */}
. /*{error("símbolo desconocido");}*/
<<EOF>> {return 0;}
%%
