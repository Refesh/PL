#include "Qlib.h"
#include "Q.h"

#define INI 0
BEGIN
L 0:
		R6=R7;
		R5=R6;
		R0 = 0.000000;
		R7=R7-4;
		I(R7+0) = R0;
		R0 = 0.000000;
		R7=R7-4;
		I(R7+0) = R0;
		R0 = 0.000000;
		R7=R7-4;
		I(R7+0) = R0;
		R0 = 0.000000;
		R7=R7-4;
		I(R7+0) = R0;
		R7=R7-16;
		R0 = 102.000000;
		I(R6-20) = R0;
		R0 = 53.000000;
		I(R6-24) = R0;
		R0 = 88.000000;
		I(R6-28) = R0;
		R0 = 87.000000;
		I(R6-32) = R0;
		GT(1);
L 2:
		R7=R7-4;
	STAT(0)
		STR(0x11f94, "Numbers in ascending order:");		 
	CODE(0)
		R0 = 3.000000;
		R1 = 73620.000000;
		GT(-12);
L 3:
L 4:
		R0 = I(R6-16);
		RR0 = I(R5-4);
		R0 = R0<RR0;
		IF (R0) GT(5);
		GT(6);
L 5:
	STAT(1)
		STR(0x11f88, "%d\n");		 
	CODE(1)
		R0 = 7.000000;
		R1 = 73608.000000;
		R2 = I(R6-16);
		R4 = R2+5;
		R4 = R4*4;
		R3 = I(R6-R4);
		R2 = R3;
		GT(-12);
L 7:
		R0 = I(R6-16);
		R1 = 1.000000;
		R0 = R0+R1;
		I(R6-16) = R0;
		GT(4);
L 6:
		R7=R5;
		R5 = I(R5);
		R0 = I(R7+4);
		GT(R0);
L 8:
		R7=R7-4;
L 9:
		R0 = I(R6-8);
		R1 = I(R5-4);
		R0 = R0<R1;
		IF (R0) GT(10);
		GT(11);
L 10:
		R0 = I(R6-8);
		R1 = 1.000000;
		R0 = R0+R1;
		I(R6-12) = R0;
L 12:
		R0 = I(R6-12);
		R1 = I(R5-4);
		R0 = R0<R1;
		IF (R0) GT(13);
		GT(14);
L 13:
		R0 = I(R6-8);
		R4 = R0+5;
		R4 = R4*4;
		R1 = I(R6-R4);
		R2 = I(R6-12);
		R4 = R2+5;
		R4 = R4*4;
		R3 = I(R6-R4);
		R1 = R1>R3;
		IF (R1) GT(15);
		GT(16);
L 15:
		R0 = I(R6-8);
		R4 = R0+5;
		R4 = R4*4;
		R1 = I(R6-R4);
		I(R6-4) = R1;
		R0 = I(R6-12);
		R4 = R0+5;
		R4 = R4*4;
		R1 = I(R6-R4);
		R2 = I(R6-8);
		R4 = R2+5;
		R4 = R4*4;
		I(R6-R4) = R1;
		R0 = I(R6-4);
		R1 = I(R6-12);
		R4 = R1+5;
		R4 = R4*4;
		I(R6-R4) = R0;
L 16:
		R0 = I(R6-12);
		R1 = 1.000000;
		R0 = R0+R1;
		I(R6-12) = R0;
		GT(12);
L 14:
		R0 = I(R6-8);
		R1 = 1.000000;
		R0 = R0+R1;
		I(R6-8) = R0;
		GT(9);
L 11:
		R0 = I(R5-4);
		R7 = R7-8;
		I(R7) = R5;
		R5 = R7;
		I(R7+4) = 17;
		I(R5-4) = R0;
		GT(2);
L 17:
		R7=R5;
		R5 = I(R5);
		R0 = I(R7+4);
		GT(R0);
L 1:
		R0 = 4.000000;
		R7 = R7-8;
		I(R7) = R5;
		R5 = R7;
		I(R7+4) = 18;
		I(R5-4) = R0;
		GT(8);
L 18:
	STAT(2)
		STR(0x11f48, "Fin del programa");		 
	CODE(2)
		R0 = 19.000000;
		R1 = 73544.000000;
		GT(-12);
L 19:
		GT(-2); 		# Terminamos la ejecución
END
