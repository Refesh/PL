default:
	flex milex.l
	bison -d mycomp.y 
	gcc -o mycomp semantic.c eval.c codeGeneration.c mycomp.tab.c lex.yy.c -lfl -L C:\GnuWin32\lib
	.\mycomp.exe sort.txt

compile:
	gcc IQ.o Qlib.c -o IQ -no-pie
	./IQ out.q.c
