#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "semantic.h"
#define R_SIZE 5
#define RR_SIZE 4

int R[R_SIZE]= {0};
int RR[RR_SIZE]= {0};

int dir = 0x12000;
int label = 1;


void addSymbolTable(struct symbol *symbol){
	struct symbol *search = searchSymbol(symbol->name);
    struct symbolTable * table = malloc(sizeof(struct symbolTable));
    if (search != NULL){
		printf("No existe\n");
		exit(0);
	}
    table->symbol = symbol;
    
    if(tail == NULL){
        tail = table;
        head = table;
    }else{
        tail->next = table;
        tail = tail->next;
    }
}

struct symbol *searchSymbol(char *id) {
    struct symbolTable *aux  = head;
    while (aux !=NULL)
    {
        if(strcmp(aux->symbol->name, id) == 0){
            return aux->symbol;
        }
        aux  = aux->next;
    }
    return NULL;
}

struct symbol *searchParameter(char *id, char* funId) {
    struct symbolTable *aux  = head;
    while (aux !=NULL)
    {
        if(strcmp(aux->symbol->name, id) == 0 && aux->symbol->fun != NULL &&  strcmp(aux->symbol->fun->symbol->name, funId) == 0){
            return aux->symbol;
        }
        aux  = aux->next;
    }
    return NULL;
}


struct symbol *newSymbol(char type, char *id, bool isArray, int len) {
	struct symbol *res= malloc(sizeof(struct symbol));
    if(!res) {
		    printf("Out of space\n");
		exit(0);
	}
	res->name = strdup(id) ;
    res->type = type;
    res->len = len;
    res->isArray = isArray;
	res->isFun = false;
	res->fun = NULL;

	return res;
}

struct ast *newStringLiteral(char *literal) {
	struct stringLiteral *res = malloc(sizeof(struct stringLiteral));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}

    res->content = strdup(literal);

	res->nodeType = 't';
	return (struct ast*)res;
}

struct ast *newNum(double value) {
	struct num *res = malloc(sizeof(struct num));
	
	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->value = value;

	res->nodeType = 'n';
	return (struct ast*)res;
}

struct ast *newRef(char *id) {
	struct ref *res = malloc(sizeof(struct ref));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->name = strdup(id);

	res->nodeType = 'r';
	return (struct ast*)res;
}

struct ast *newAst(char nodeType, struct ast *left, struct ast *right) {
	struct ast *res = malloc(sizeof(struct ast));
	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->nodeType = nodeType;
    res->left = left;
    res->right = right;

	return res;
}

struct ast *newVecRef(char *id, struct ast *index) {
	struct vecRef *res = malloc(sizeof(struct vecRef));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->name = strdup(id);
    res->index = index;

	res->nodeType = 'c';
	return (struct ast*)res;
}

struct ast *newPrint(struct ast *content) {
	struct print *res = malloc(sizeof(struct print));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}

    res->ast = content; 

	res->nodeType = 'p';
	return (struct ast*)res;
}

struct ast *newVecItemAssign(char *id, struct ast *index, struct ast *content) {
	struct vecItemAssign *res = malloc(sizeof(struct vecItemAssign));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}

    res->vecRef = (struct vecRef*)newVecRef(id, index);
    res->content = content;

	res->nodeType = 'v';
	return (struct ast*)res;
}

struct ast *newAssign(char *id, struct ast *content) {
	struct assign *res = malloc(sizeof(struct assign));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    
    res->id = strdup(id);
    res->content = content;
    
	res->nodeType = 'a';
	return (struct ast*)res;
}

struct ast *newReturn(struct ast *returnVal) {
	struct returnStatement *res = malloc(sizeof(struct returnStatement));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->ast = returnVal;

	res->nodeType = 'e';
	return (struct ast*)res;
}

struct list *newList( struct ast *current, struct list *next) {
    struct list *list = malloc(sizeof(struct list));

	if(!list) {
		printf("Out of space\n");
		exit(0);
	}
	list->current = current;
	list->next = next;

	return list;
}

struct listContainer *newListContainer(char type, struct list *list) {
	struct listContainer *res = malloc(sizeof(struct listContainer));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->listType = type;
    res->list = list;

	res->nodeType = 'l';
	return res;
}

struct  ast *newDef(char type, char *id, struct ast *content) {
	struct def *res = malloc(sizeof(struct assign));
	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
	res->symbol = newSymbol(type, id, false, 0);
    res->content = content;

	res->nodeType = 'a';
	return (struct ast*)res;
}

struct  ast *newVecDef(char type, int len, char *id, struct ast *numList) {
	struct def *res = malloc(sizeof(struct def));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->symbol = newSymbol(type, id, true, len);
    res->content = numList;
		
	res->nodeType = 'a';
	return (struct ast*)res;
}


struct  ast *newFunDef(char returnType, bool isArray, char *id, struct ast *params, struct ast *content) {
	struct funDef *res = malloc(sizeof(struct funDef));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
	
    struct symbol *symbol = newSymbol(returnType, id, isArray, 0);
	symbol->isFun = true;
    res->symbol = symbol;
	res->params = params;
    res->content = content;

	res->nodeType = 'f';
	return (struct ast*)res;
}

struct  ast *newFunCall(char *id, struct ast *params) {
	struct funCall *res = malloc(sizeof(struct funCall));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->name = strdup(id);
    res->params = params;

	res->nodeType = 'u';
	return (struct ast*)res;
}

struct  ast *newBranch(char type, struct ast *compare, struct ast *branch1, struct ast *branch2) {
	struct branch *res = malloc(sizeof(struct branch));

	if(!res) {
		printf("Out of space\n");
		exit(0);
	}
    res->type = type;
	res->compare = compare;
	res->branch1 = branch1;
    res->branch2 = branch2;

	res->nodeType = 'b';
	return (struct ast*)res;
}


struct reg * getRegister(char *label, int index){
	struct reg * res = malloc(sizeof(struct reg));
	res->type = strdup(label);
	if (strcmp(label, "R") == 0)
	{
		if (index<0)
		{
			int i = 0;
			while(R[i] != 0 && i < R_SIZE){
				i++;
			}
			index = i;
		}
		R[index] = 1;
		res->index = index;
	}else
	{
		if (index<0)
		{
			int i = 0;
			while(RR[i] != 0 && i < RR_SIZE){
				i++;
			}
			RR[i] = 1;
			res->index = i;
		}else{
			RR[index] = 1;
			res->index = index;
		}
	}
	return res;
}

int getNextFreeAddress(int bytes)
{
  dir -= bytes;
  dir = dir & 0xffffc;
  return dir;
}

int getNextLabel(){
	label++;
	if (label == 1)
	{
		label++;
	}
	
	return label;
}

void freeRegisters(){
	for (int i = 0; i < R_SIZE; i++)
	{
		R[i] = 0;
	}
	for (int i = 0; i < RR_SIZE; i++)
	{
		RR[i] = 0;
	}
}