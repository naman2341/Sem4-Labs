.DATA 
	A:.WORD 1,2,3,4,5,6,7,8,9 
	B:.WORD 1,2,3,4,5,6,7,8,9 
	C:.WORD 0,0,0,0,0,0,0,0,0 
.TEXT
	LDR R0,=A   
	LDR R1,=B
	LDR R2,=C
	MOV R5,#0
	MOV R6,#0
	MOV R7,#0
	MOV R8,#0

LOOP:	
	LDR R3,[R0],#4           
	LDR R4,[R1],#12
	MLA R8,R3,R4,R8
	ADD R5,R5,#1
	CMP R5,#3
	BNE LOOP
	STR R8,[R2],#4
	BL L1

L1:				
	LDR R3,[R0,#-12]!       
	LDR R4,[R1,#-32]!
	MOV R8,#0
	MOV R5,#0
	ADD R6,R6,#1		
	CMP R6,#3
	BLT LOOP
	
	LDR R3,[R0,#12]!	
	LDR R4,[R1,#-12]!
	MOV R8,#0
	MOV R5,#0
	MOV R6,#0
	ADD R7,R7,#1
	CMP R7,#3
	BNE LOOP
	BNE LOOP
	SWI 0X011

