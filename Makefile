default:
	bison -d mycomp.y -v
	flex milex.l
	gcc -o mycomp semantic.c eval.c codeGeneration.c mycomp.tab.c lex.yy.c -lfl -L C:\GnuWin32\lib
	.\mycomp.exe fibo.txt

compile:
	gcc IQ.o Qlib.c -o IQ -no-pie 
	./IQ out.q.c

debug:
	gcc IQ.o Qlib.c -o IQ -no-pie 
	./IQ -g out.q.c
