#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "semantic.h"
#include "codeGeneration.h"

char *output_file = "out.q.c";
char *tmpMain = ".tmp_main";
int stat = -1;
int code = 0;

FILE *mainFile;
FILE *output;

int openFiles()
{
  mainFile = fopen(tmpMain, "w+");

  return 0;
}

void writeInTmpFile(char *format, ...)
{
  va_list ap;
  va_start(ap, format);

  vfprintf(mainFile, format, ap);

  va_end(ap);
}

void writeOutputFile(char *format, ...)
{
  va_list ap;
  va_start(ap, format);

  vfprintf(output, format, ap);

  va_end(ap);
}

void manageStat()
{
  if (code > stat)
  {
    writeInTmpFile("\tSTAT(%d)\n", code);
    stat = code;
  }
}

void manageCode()
{
  if (code == stat)
  {
    writeInTmpFile("\tCODE(%d)\n", code);
    code++;
  }
}

void closeFiles()
{
  int c;

  output = fopen(output_file, "w");

  fseek(mainFile, 0, SEEK_SET);

  writeOutputFile("#include \"Qlib.h\"\n");
  writeOutputFile("#include \"Q.h\"\n\n");
  writeOutputFile("#define INI 0\n");
  writeOutputFile("BEGIN\n");

  writeOutputFile("L 0:\n");

  writeOutputFile("\t\tR6=R7;\n");
  writeOutputFile("\t\tR5=R6;\n");

  while ((c = fgetc(mainFile)) != EOF)
  {
    fputc(c, output);
  }

  writeOutputFile("\t\tGT(-2); \t\t# Terminamos la ejecución\n");
  writeOutputFile("END\n");

  fclose(mainFile);
  fclose(output);
}

void numToRegister(struct reg *r, double num)
{
  writeInTmpFile("\t\t%s%d = %f;\n", r->type, r->index , num);
}

void memoryToRegister(struct reg *r, struct symbol * addr)
{
  if (addr->fun == NULL)
  { 
    writeInTmpFile("\t\t%s%d = I(R6-%d);\n", r->type, r->index , addr->varIndex*4);
  }else{
    writeInTmpFile("\t\t%s%d = I(R5-%d);\n", r->type, r->index , addr->varIndex*4);
  }
}

void arrayAccess(struct reg *r, struct symbol * addr, struct reg * offset)
{
  writeInTmpFile("\t\tR4 = %s%d+%d;\n", offset->type, offset->index, addr->varIndex);
  writeInTmpFile("\t\tR4 = R4*4;\n");
  if (addr->fun == NULL)
  { 
    writeInTmpFile("\t\t%s%d = I(R6-R4);\n", r->type, r->index);
  }else{
    writeInTmpFile("\t\t%s%d = I(R5-R4);\n", r->type, r->index);
  }
}

void arrayItemAssign(struct reg *r, struct symbol * addr, struct reg * offset)
{
  writeInTmpFile("\t\tR4 = %s%d+%d;\n", offset->type, offset->index, addr->varIndex);
  writeInTmpFile("\t\tR4 = R4*4;\n");
  if (addr->fun == NULL)
  { 
    writeInTmpFile("\t\tI(R6-R4) = %s%d;\n", r->type, r->index);
  }else{
    writeInTmpFile("\t\tI(R5-R4) = %s%d;\n", r->type, r->index);
  }
  
}

void registerToMemory(char sign, int regIndex, int offset, struct reg *src)
{
  if (strcmp(src->type, "R") == 0)
  {
    writeInTmpFile("\t\tI(R%d%c%d) = %s%d;\n", regIndex, sign, offset*4, src->type, src->index);
  }else{
    writeInTmpFile("\t\tP(R%d%c%d) = %s%d;\n", regIndex, sign, offset*4, src->type, src->index);
  }
}

void reserveSpace(int bytes)
{
  writeInTmpFile("\t\tR7=R7-%d;\n", bytes);
}

void storeStringInMemory(int addr, char *s)
{
  manageStat();
  writeInTmpFile("\t\tSTR(0x%x, \"%s\");\t\t \n", addr, s);
  manageCode();
}

void insertLabel(int label)
{
  writeInTmpFile("L %d:\n", label);
}

void insertGoTo(int label)
{
  writeInTmpFile("\t\tGT(%d);\n", label);
}

void numericLogicalCalculation(char* operation, struct reg *l, struct reg *r)
{
  switch ((int)operation)
  {
  case 1:
    operation  = "==";
    break;
  case 2:
    operation  = "!=";
    break;
  case 3:
    operation  = ">";
    break;

  case 4:
    operation  = "<";
    break;

  case 5:
    operation  = ">=";
    break;
  case 6:
    operation  = "<=";
    break;

  default:
    break;
  }
  writeInTmpFile("\t\t%s%d = %s%d%s%s%d;\n", l->type, l->index, l->type, l->index, operation, r->type, r->index);
}

void insertContext(int label){
  writeInTmpFile("\t\tR7 = R7-8;\n");
  writeInTmpFile("\t\tI(R7) = R5;\n");
  writeInTmpFile("\t\tR5 = R7;\n");
  writeInTmpFile("\t\tI(R7+4) = %d;\n", label);
}

void extractContext(){
  writeInTmpFile("\t\tR7=R5;\n");
  writeInTmpFile("\t\tR5 = I(R5);\n");
  writeInTmpFile("\t\tR0 = I(R7+4);\n");
  writeInTmpFile("\t\tGT(R0);\n");
}

void insertIf(struct reg *r, int label)
{
  manageCode();
  writeInTmpFile("\t\tIF (%s%d) GT(%d);\n", r->type, r->index, label);
}

void registerToRegister(struct reg *r1, struct reg *r2){
  writeInTmpFile("\t\t%s%d = %s%d;\n", r1->type, r1->index , r2->type, r2->index);
}