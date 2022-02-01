.DATA
    A : .WORD 11
    //value of n

.TEXT
    LDR r3,=A
    LDR r0,[r3]
    //store value
    mov r1,#0
    //count
    mov r2,#0 

L1 : 
    ADD r1,#1
    ADD r2,r2,r1
    //sum=prev sum+ incremented number
    CMP r1,r0
    BNE L1
    ADD r3,#4
    STR r2,[r3]
    B L2 
L2 : .end