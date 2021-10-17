
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "semantic.h"
#include "eval.h"

int varIndex = 1;

struct ast * eval(struct listContainer *defs, struct listContainer *funs, struct listContainer *main){
	openFiles();
	defsEval(defs);
	insertGoTo(1);
	printf("Empieza Declaracion de funciones--------------------------------------------------------------------\n");
	funsEval(funs);
	printf("Empieza main--------------------------------------------------------------------\n");
	insertLabel(1);
	statementBlockEval(main);
	closeFiles();
}

struct ast * defsEval(struct listContainer *defs){
	struct ast *res = malloc(sizeof(struct ast));
	struct list *list = defs->list;

	while (list!=NULL)
	{
		struct def * node = (struct def*)list->current;
		struct symbol * symbol = node->symbol;
		list = list->next;
		

		switch(symbol->type) {
			case 'i': 
			case 'd': 
				if(symbol->isArray){
					reserveSpace(4*symbol->len);
					symbol->varIndex = varIndex++;
					varIndex = varIndex + symbol->len -1;
					struct reg * pos2 = numListEval(((struct listContainer*)node->content)->list, symbol);
				}else{
					struct reg * pos = exprEval(node->content);
					symbol->varIndex = varIndex++;
					reserveSpace(4);
					registerToMemory('+', 7, 0, pos);
				}
				break;

			default: 
				printf("internal error: bad node %c\n", symbol->type);
		}
		addSymbolTable(symbol);
		freeRegisters();
	}
	return res;
}

struct ast * funsEval(struct listContainer *funs){
	struct ast *res = malloc(sizeof(struct ast));
	struct list *list = funs->list;

	while (list!=NULL)
	{
		int label1 = getNextLabel();
		insertLabel(label1);
		struct funDef * fun = (struct funDef*)list->current;
		struct symbol * symbol = fun->symbol;
		
		varIndex = 1;
		fun->label = label1;
		symbol->fun = fun;
		paramsEval(((struct listContainer*)fun->params)->list, fun);
		statementBlockEval(fun->content);
		list = list->next;
		
		addSymbolTable(symbol);
		freeRegisters();
		extractContext();
	}
}

struct ast * statementBlockEval(struct listContainer *defs){
	struct ast *res = malloc(sizeof(struct ast));
	struct list *list = defs->list;
	while (list!=NULL)
	{
        freeRegisters();
		switch(list->current->nodeType) {
			case 'b': 
			switch(((struct branch*)list->current)->type) {
				case 'I': 
				ifEval((struct branch*)list->current);
				break;
				case 'W':
				whileEval((struct branch*)list->current);
				break; 
				default:
				printf("internal error: bad node %c\n", ((struct branch*)list->current)->type);
			}
			break;
			case 'e': 
				freeRegisters();
				returnEval((struct returnStatement*)list->current);
				extractContext();
			break;
			default: 
			exprEval(list->current);
		}
		list = list->next;
	}
	return res;
}

struct reg * exprEval(struct ast *defs){
	struct reg * pos;
	struct reg * pos1;
	switch(defs->nodeType) {
		case '+': 
		case '-': 
		case '*': 
		case '/': 
			numOperationEval(defs);
			break;
		
		case 'n': 
			return numEval(((struct num*)defs)->value);
			break;

		case 'r': 
			refEval(((struct ref*)defs)->name);
			break;

		case 'c':
			pos = exprEval(((struct vecRef*)defs)->index);
			return vecRefEval(((struct vecRef*)defs)->name, pos);
			break;

		case 'p': 
			printEval(((struct print*)defs));
			freeRegisters();
			break;

		case 'a': 
			assignEval((struct assign*)defs);
			freeRegisters();
			break;
		
		case 'v': 
			vecItemAssignEval((struct vecItemAssign*)defs);
			freeRegisters();
			break;

		case 'u': 
			funCallEval((struct funCall*)defs);
			return getRegister("R", 1);
			break;
		
		default: 
			printf("Internal error: bad expr %c\n", defs->nodeType);
	}
}


struct reg * numEval(double num){
	struct reg * res = malloc(sizeof(struct reg));
	if (num != (int)num)
	{
		res = getRegister("RR", -1);
	}else{
		res = getRegister("R", -1);
	}
	numToRegister(res,num);
	return res;
}

struct reg * vecRefEval(char *id, struct reg * offset){
	struct symbol *symbol = searchSymbol(id);
	struct reg * r = getRegister("R", -1);
	arrayAccess(r, symbol, offset);
	return r;
}

struct reg * refEval(char *id){
	struct symbol *symbol = searchSymbol(id);
	struct reg * reg = malloc(sizeof(struct reg));
	if(symbol==NULL){
		printf("Symbol shouldn't be NULL\n");
        exit(0);
	}

	if (strcmp(&symbol->type, "i")==0)
	{
		reg = getRegister("R", -1);
	}else{
		reg = getRegister("RR", -1);
	}

	memoryToRegister(reg, symbol);
	return reg;
}

struct reg * printEval(struct print * print){
	freeRegisters();
	int lab = getNextLabel();
	struct reg * r0 = getRegister("R", 0);
	struct reg * r1  = getRegister("R", 1);
	if (print->ast->nodeType != 't')
	{
		int addr = getNextFreeAddress(strlen("%d\n")*4);

		r0->index = r0->index;
		r0->type = "R";

		storeStringInMemory(addr, "%d\\n");

		numToRegister(r0, (float)lab);
		numToRegister(r1, (float)addr);
		struct reg *r = exprEval(print->ast);
		registerToRegister(getRegister("R", 2), r);
	}else {
		char *content = ((struct stringLiteral*)print->ast)->content;
		int addr = getNextFreeAddress(strlen(content)*4);

		r0->type = "R";

		storeStringInMemory(addr, content);

		numToRegister(r0, (float)lab);
		numToRegister(r1, (float)addr);
	}
	insertGoTo(-12);
	insertLabel(lab);
	
	return r0;
}

struct reg * numOperationEval(struct ast * calculation){
	struct reg * r1 = exprEval(calculation->left);
	struct reg * r2 = exprEval(calculation->right);
	char *ptr = malloc(2*sizeof(char));
	ptr[0] = calculation->nodeType;
	ptr[1] = '\0';
	numericLogicalCalculation(ptr, r1, r2);
	return r1;
}

struct reg * assignEval(struct assign * assign){
	struct reg *r1 = exprEval(assign->content);
	struct symbol* symbol = searchSymbol(assign->id);
	if (symbol==NULL)
	{
		printf("Symbol shouldn't be NULL\n");
        exit(0);
	}
	registerToMemory('-', 6, symbol->varIndex, r1);
	
	return r1;
}

struct reg * vecItemAssignEval(struct vecItemAssign * assign){
	struct reg *r = exprEval(assign->content);
	struct symbol* symbol = searchSymbol(assign->vecRef->name);
	struct reg * offset = exprEval(assign->vecRef->index);
	if (symbol==NULL)
	{
		printf("Symbol shouldn't be NULL\n");
        exit(0);
	}
	arrayItemAssign(r, symbol, offset);
	
	return r;
}

struct reg * ifEval(struct branch* branch){
	int label = getNextLabel();
	int label2 = getNextLabel();
	struct reg * r = compareEval(branch->compare);

	insertIf(r, label);
	insertGoTo(label2);
	insertLabel(label);
	statementBlockEval((struct listContainer*)branch->branch1);
	if ((struct listContainer*)branch->branch2 != NULL)
	{	
	    int label3 = getNextLabel();
		insertGoTo(label3);
		insertLabel(label2);
		statementBlockEval((struct listContainer*)branch->branch2);
		insertLabel(label3);
	}else{
		insertLabel(label2);
	}
	return r;
}

struct reg * whileEval(struct branch* branch){
	int label0 = getNextLabel();
	int label = getNextLabel();
	int label2 = getNextLabel();
	struct reg * r;
	insertLabel(label0);
	r = compareEval(branch->compare);
	insertIf(r, label);
	insertGoTo(label2);
	insertLabel(label);
	statementBlockEval((struct listContainer*)branch->branch1);
	insertGoTo(label0);
	insertLabel(label2);
	return r;
}

struct reg * compareEval(struct ast * compare){
	
	struct reg * r1 = exprEval(compare->left);
	struct reg * r2 = exprEval(compare->right);
	numericLogicalCalculation(compare->nodeType, r1, r2);
	return r1;
}

struct reg * paramsEval(struct list * params, struct funDef * fun){
	while (params!=NULL)
	{
		struct symbol * symbol = (struct symbol*)params->current;
		params = params->next;
		symbol->fun = fun;

		switch(symbol->type) {
			case 'i': 
			case 'd': 
				symbol->varIndex = varIndex++;
				reserveSpace(4);
				break;
			default: 
				printf("internal error: bad node %c\n", symbol->type);
				exit(0);
		}
		addSymbolTable(symbol);
		freeRegisters();
	}
}

struct reg * funCallEval(struct funCall * funCall){
	struct symbol * fun = searchSymbol(funCall->name);
	struct list * params = ((struct list*)funCall->params);
	struct reg *r1 = malloc(sizeof(struct reg));
	int index = 1;
	int label = getNextLabel();

	while (params!=NULL)
	{
		r1 = exprEval(params->current);
        if (index == 1)
        {
           insertContext(label);
        }
		registerToMemory('-', 5, index++, r1);
		params  = params->next;
		freeRegisters();
	}
	insertGoTo(fun->fun->label);
	insertLabel(label);
	return r1;
}

void * returnEval(struct returnStatement * returnS){
	struct reg * r = getRegister("R", 1);
	registerToRegister(r, exprEval(returnS->ast));
}

void * numListEval(struct list * numList, struct symbol* array){
	int index = 0;
	while (numList!=NULL)
	{
		struct reg *r1 = exprEval(numList->current);
		numList = numList->next;
		registerToMemory('-', 6, array->varIndex+index, r1);
		freeRegisters();
		index++;
	}
}