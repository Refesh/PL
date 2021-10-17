void numToRegister(struct reg *r, double num);
void memoryToRegister(struct reg *r, struct symbol * addr);
void registerToRegister(struct reg *r1, struct reg *r2);
void registerToMemory(char sign, int regIndex, int offset, struct reg *src);

void storeStringInMemory(int addr, char *s);

void arrayAccess(struct reg *r, struct symbol * addr, struct reg * offset);
void arrayItemAssign(struct reg *r, struct symbol * addr, struct reg * offset);

void insertLabel(int label);
void insertGoTo(int label);

void reserveSpace(int bytes);


void insertIf(struct reg *r, int label);

void numericLogicalCalculation(char * operation, struct reg *l, struct reg *r);

void insertContext(int label);
void extractContext();

void manageStat();
void manageCode();

void closeFiles();
int openFiles();
