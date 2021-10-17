struct ast * eval(struct listContainer *defs, struct listContainer *funs, struct listContainer *main);

struct ast * defsEval(struct listContainer *defs);

struct ast * funsEval(struct listContainer *funs);

struct ast * statementBlockEval(struct listContainer *defs);

struct reg * exprEval(struct ast *exp);
struct reg * numEval(double num);
struct reg * vecRefEval(char *id, struct reg *pos);
struct reg * refEval(char *id);
struct reg * printEval(struct print * print);
struct reg * numOperationEval(struct ast * calculation);
struct reg * assignEval(struct assign * assign);
struct reg * vecItemAssignEval(struct vecItemAssign * assign);

struct reg * ifEval(struct branch* branch);
struct reg * whileEval(struct branch* branch);
struct reg * compareEval(struct ast * compare);

struct reg * paramsEval(struct list * params, struct funDef * fun);
struct reg * funCallEval(struct funCall * funCall);
void * returnEval(struct returnStatement * returnS);
void * numListEval(struct list * numList, struct symbol* array);