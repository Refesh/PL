%{
#include "mycomp.tab.h"
#include <string.h>

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

\"([^"])*\"   { strncpy(yylval.stringLiteral,&yytext[1],yyleng-2); yylval.stringLiteral[yyleng-2] = '\0'; return STRINGLITERAL; }

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
