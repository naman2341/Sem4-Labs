.DATA 
	A : .WORD 1,2,1,2,4,2
	B :.WORD   0,0,0
.TEXT 
	LDR R1,=A
	LDR R2,=B
	MOV R3, #3
LOOP:
	MOV R4,#2
	MOV R6,#0
L1:
	LDR R5 , [R1] , #4
	ADD R6 , R6 , R5 
	SUB R4,R4,#1 
	CMP R4,#0
	BNE L1 
STR R6,[R2],#4
SUB R3,R3 , #1
CMP R3,#0
BNE LOOP 

SWI 0X011  