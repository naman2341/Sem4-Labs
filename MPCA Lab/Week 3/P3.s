.DATA
    A : .WORD 44
    B : .WORD 2
    C : .WORD 33
    D : .WORD 0
    E : .WORD 0

.TEXT
    LDR r0,=A
    LDR r1,=B
    LDR r2,=C
    LDR r3,=D 
    LDR r4,=E
    LDR r5,[r0]
    LDR r6,[r1]
    LDR r7,[r2]
    LDR r9,=C
    CMP r5,r6
    //If A==B
    BEQ L1
    CMP r6,r7
    //Else If B==C
    BEQ L2
    B L3
    //Else

L1 :
    ADD r8,r5,r6
    //C=A+B
    STR r8,[r9]
    B L4
L2 :
    SUB r8,r5,r6
    //D=A-B
    STR r8,[r3]
    B L4
L3 :
    MUL r8,r5,r6
    //E=A*B
    STR r8,[r4]
    B L4
//r8 Stores the results
L4 : .end