.DATA 
   //Let N=5
   A : .WORD 12,8,5,7,13
        //FULL WORD
   B : .HWORD 12,8,5,7,13
        //HALF WORD
   C : .byte 12,8,5,7,13
        //BYTE WISE
.TEXT 
    LDR r0,=A
    LDR r1,=B
    LDR r2,=C
    LDR r4,=C 

    ADD r9,r9,#6

    mov r4,#0
        //Stores the count for no of loops
    mov r5,#0
    mov r6,#0
    mov r7,#0
L1 :
        LDR r8,[r0]
        ADD r5,r5,r8
        ADD r0,#4

        ADD r4,#1
        CMP r4,#5
        BNE L1
        STR r5,[r9]
        ADD r9,#4
        mov r4,#0
                //Resets count to 0

L2 : 
        LDRH r8,[r1]
        ADD r6,r6,r8
        ADD r1,#2

        ADD r4,#1
        CMP r4,#5
        BNE L2
        STR r6,[r9]
        ADD r9,#4
        mov r4,#0
                //Resets count to 0

L3 :
        LDRB r8,[r2]
        ADD r7,r7,r8
        ADD r2,#1

        ADD r4,#1
        CMP r4,#5
        BNE L3
        STR r7,[r9]
        ADD r9,#4
        B L4

L4 : .end