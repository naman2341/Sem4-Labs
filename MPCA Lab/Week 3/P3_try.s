.DATA
    A : .WORD 30
    B : .WORD 40
    C : .WORD 50
    D : .WORD 0
    E : .WORD 0

.TEXT
    LDR r0,=A
    LDR r1,=B
    LDR r2,=C
    LDR r9,=C
    LDR r3,=D 
    LDR r4,=E

    LDR r5,[r0]
    LDR r6,[r1]
    LDR r7,[r2]


    CMP r5,r6
    BEQ L2
    CMP r6,r7
    BEQ L3
    B L4

L2 :
    ADD r8,r5,r6
    STR r8,[r9]
    B L5
L3 :
    SUB r8,r5,r6
    STR r8,[r3]
    B L5
L4 :
    MUL r8,r5,r6
    STR r8,[r4]
    B L5

L5 : .end