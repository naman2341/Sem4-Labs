.data

    A: .WORD 5,1,63,7,24,1,7,8,23
    ANS: .WORD 0,0,0

.text
    LDR r0,=A
    LDR r4,=ANS
    MOV r9,#3
    MOV r8,#0 
loop:
    LDMIA r0!,{r1-r3}    
    ADD r1,r1,r2
    ADD r1,r1,r3
    STR r1,[r4],#4
    ADD r8,r8,#1
    CMP r8,r9 
    BEQ end 
    B loop 

end: .end