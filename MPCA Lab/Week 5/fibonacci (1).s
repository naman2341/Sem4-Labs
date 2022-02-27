Ldr R0,=A;
Mov R10,#9
Mov R1,#0
Mov R2,#1
Str R1,[R0],#4
Add R3,R2,R1
Loop:	Str R3,[R0],#4
Add R3,R2,R1
Mov R1,R2
Mov R2,R3 
Sub R10,R10,#1
Cmp R10,#0
Beq Exit
Bne Loop
	
Exit: Swi 0x11	
A: .word