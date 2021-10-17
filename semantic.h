#include <stdbool.h>
void yyerror(char *s);

int yyparse();
int yylex();


struct ast 
{
	char nodeType;

	struct ast *left;
	struct ast *right;
};

struct symbol 
{
	char *name;
	char type;

    int varIndex;
    bool isArray;
    bool isFun;
    struct funDef* fun;
    int len;
};

struct symbolTable
{
	struct symbol *symbol;
    struct symbolTable *next;
};


struct reg 
{
	char *type;

    int index;
};

struct symbolTable *head;
struct symbolTable *tail;

struct list 
{
    struct ast *current;
    struct list *next;
};

struct listContainer 
{
    char nodeType;
    char listType;
    struct list *list;
};

struct funDef
{
    char nodeType;
    int label;
    struct symbol *symbol;
    struct ast *params;
    struct ast *content;
};

struct def 
{
    char nodeType;
    struct symbol *symbol;
    struct ast *content;
};

struct assign 
{
    char nodeType;
    char* id;
    struct ast *content;
};


struct ref 
{
    char nodeType;
    char *name;
};

struct vecRef 
{
    char nodeType;
    struct ast *index;
    char *name;
};

struct funCall
{
    char nodeType;
    char *name;
    struct list *params;
};

struct vecItemAssign 
{
    char nodeType;
    struct vecRef *vecRef;
    struct ast *content;
};

struct num 
{
    char nodeType;
    double value;
};

struct branch
{
    char nodeType;
    char type;
    struct ast *compare;
    struct ast *branch1;
    struct ast *branch2;
};

struct returnStatement
{
    char nodeType;
    struct ast *ast;
};

struct print
{
    char nodeType;
    struct ast *ast;
};

struct stringLiteral
{
    char nodeType;
    char *content;
};

void addToSymbolTable(struct symbol *symbol);

struct symbol *newSymbol(char type, char *id, bool isArray, int len);

struct ast *newAst(char nodeType, struct ast *left, struct ast *right);
struct ast *newPrint(struct ast *content);
struct ast *newAssign(char *id, struct ast *content);
struct ast *newDef(char type, char *id, struct ast *content);
struct ast *newFunDef(char returnType, bool isArray, char *id, struct ast *params, struct ast *content);
struct ast *newVecItemAssign(char *id, struct ast *index, struct ast *content);
struct ast *newVecDef(char type, int len, char *id, struct ast *numList);
struct ast *newRef(char *id);
struct ast *newVecRef(char *id, struct ast *index);
struct ast *newFunCall(char *id, struct ast *params);
struct ast *newNum(double num);
struct list *newList(struct ast *current, struct list *next);
struct listContainer *newListContainer(char type, struct list *list);
 
struct ast *newReturn(struct ast *returnVal);
struct ast *newStringLiteral(char *literal);
struct ast *newBranch(char type, struct ast *compare, struct ast *branch1, struct ast *branch2);

struct symbol *searchSymbol(char *id);

struct reg * getRegister(char *label, int index);

int getNextFreeAddress(int bytes);
int getNextLabel();

void freeRegisters();