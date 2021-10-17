%{
#include "semantic.h"
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
extern int numlin;
int yydebug=1;
%}
%union { 	
		char type;
		int comp;
		char name[15];
		int entero;
		double real;
		char stringLiteral[120];
		struct ast *ast;
		struct list *list;
		struct funDef *funDef;
		struct returnStatement *returnST;
		struct assign *assign;
		struct listContainer *listContainer;
		struct num *num;
}
%token <type> TYPE
%token <comp> COMP
%token <name> ID
%token <entero> ENTERO
%token <real> REAL
%token <stringLiteral> STRINGLITERAL
%token WHILE IF ELSE FUNCT MAIN RETURN PRINT
%right '='
%left '+' '-'
%left '*' '/'
%left '(' ')'
%left UMINUS

%type <ast> statement exp assign compare program
%type <listContainer> statementBlockContainer functionListContainer numListContainer paramListContainer declarationListContainer MainProgram
%type <list> declarationList numList functionList statementBlock paramList expList
%type <ast> declaration
%type <ast> function
%type <ast> returnExp
%type <ast> num

%start program
%%

program: declarationListContainer {printf("Fin declaraciones------------------\n");} functionListContainer {printf("Fin funciones------------------\n");} MainProgram {printf("Final programa\n");}   { $$ = eval($1, $3, $5); printf("parse done.\n"); }
;

MainProgram: MAIN { printf("Main"); } '{' { printf("[ corchetes\n"); } statementBlockContainer '}' { printf("}\n"); } { $$ = $5 }
;

statementBlockContainer: statementBlock { $$ = newListContainer( 'S', $1); }

statementBlock: statement { $$ = newList( $1, NULL); }
	| statement  statementBlock  { $$ = newList ($1, $2); }
;

statement: IF '(' compare ')' '{' statementBlockContainer '}'	 { $$ = (struct ast*)newBranch('I', $3, (struct ast*)$6, NULL); } 
	| IF '(' compare ')' '{'  statementBlockContainer '}' ELSE '{' statementBlockContainer '}'	 { $$ = newBranch('I', $3, (struct ast*)$6, (struct ast*)$10); } 
	| WHILE '(' { printf("while["); } compare ')' '{'{ printf("]  [\n"); } statementBlockContainer '}' { printf("}\n"); }	 { $$ = newBranch('W', $4, (struct ast*)$8, NULL); } 
	| exp ';' { printf(";\n"); }
	| returnExp ';' { printf(";\n"); }
;

function: FUNCT TYPE ID '(' { printf("funct %c %s[", $2, $3); } paramListContainer ')' '{' { printf("] [\n"); } statementBlockContainer '}' { printf("]\n"); }  { $$ = newFunDef($2, false, $3, (struct ast*)$6, (struct ast*)$10); } 
	| FUNCT TYPE '[' ']' ID '(' { printf("funct %c[] %s[", $2, $5); } paramListContainer ')' '{' { printf("] [\n"); } statementBlockContainer '}' { printf("]\n"); }  { $$ = newFunDef($2, true, $5, (struct ast*)$8, (struct ast*)$12); } 
;

functionListContainer : functionList  { $$ = newListContainer('F', $1); }
;

functionList: 	{ $$ =  NULL; }
    | function functionList  { $$ = newList($1, $2); }
;

exp:  '(' { printf("["); } exp ')' { printf("]"); }	 
	| exp '+' { printf("+"); } exp		               	 { $$ = newAst('+', $1, $4); }
	| exp '-' { printf("-"); } exp		               	 { $$ = newAst('-', $1, $4); } 
	| exp '*' { printf("*"); } exp		               	 { $$ = newAst('*', $1, $4); } 
	| exp '/' { printf("/"); } exp 		               	 { $$ = newAst('/', $1, $4); }
	| '-' { printf("-"); } exp %prec UMINUS	        	 { $$ = newAst('M', $3, NULL); }
	| num												 { $$ = $1; } 
	| ID		{ printf("%s", $1); }                    { $$ = newRef($1); } 
	| ID '[' exp ']'	{ printf("]"); }             { $$ = newVecRef($1, $3); }
	| PRINT '(' { printf("PRINT ["); } exp ')'  { printf("]"); }          { $$ = newPrint($4);} 
    | assign											{ $$ = $1; } 
    | STRINGLITERAL { printf("\"%s\"",$1); }  { $$ = newStringLiteral($1); }
	| ID '(' expList ')'  { $$ = newFunCall($1, (struct ast*)$3); }
;

returnExp: RETURN { printf("return "); } exp { $$ = newReturn($3); } 
	| RETURN { printf("return "); } { $$ = newReturn(NULL); }
;

compare: exp COMP { printf("%d",$2); } exp	       { $$ = newAst($2, $1, $4); } 
;

assign:   ID '[' exp ']' '=' { printf("] = "); } exp 	 { $$ = (struct ast*)newVecItemAssign($1, $3, $7); }
	| ID '=' { printf("%s = ", $1); }  exp    { printf("   Asignacion"); }       { $$ = (struct ast*)newAssign($1, $4); }
;

numListContainer: numList	           { $$ = newListContainer('N', $1); } 
;

numList: num	  { printf("] = "); }                 { $$ = newList($1, NULL); } 
	| num',' { printf(","); } numList	             { $$ = newList($1, $4); } 
;

num: ENTERO { printf("%d ", $1); }   { $$ = newNum($1); } 
	| REAL { printf("%f", $1); }   { $$ = newNum($1); }
;

paramListContainer: paramList { $$ = newListContainer('P', $1); }
;

paramList:  { $$ = NULL }
	| TYPE ID { $$ = newList((struct ast*)newSymbol($1, $2, false, 0), NULL); }
    | TYPE ID ',' paramList  { $$ = newList((struct ast*)newSymbol($1, $2, false, 0), $4); } 
;

expList:  { $$ = NULL }
	| exp ',' expList { $$ = newList($1, $3); }
	| exp{ $$ = newList($1, NULL); }
;

declaration: TYPE ID '['{ printf("%c %s[",$1, $2); } ENTERO ']' '=' { printf("] = "); }  '{' { printf("corc"); } numListContainer '}' { printf("corc"); } { $$ = newVecDef($1, $5, $2, (struct ast*)$11); }
	|  TYPE ID '=' { printf("%c %s = ",$1, $2); } exp { $$ = newDef($1, $2, $5); } 
;

declarationListContainer: declarationList { $$ = newListContainer('D', $1); } 
;

declarationList: { $$ =  NULL; }
	| declaration ';' { printf(";     Declaracion\n"); } declarationList { $$ = newList($1, $4); } 
;
%%
int main(int argc, char** argv) {
if (argc>1) yyin=fopen(argv[1],"r");
yyparse();
}
void yyerror(char* mens) {
printf("Error en linea %i: %s ",numlin,mens);
}
