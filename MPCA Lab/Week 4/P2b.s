.DATA
    A: .WORD 34,98,2,65
    B: .WORD 0
.TEXT
    MOV R2,#0
    LDR R1,=A
    ADD R1,R1,#4
    LDR R3,=B
    MOV R5,#8
    MOV R4,#1
LOOP: LDR R6,[R1],R5
    ADD R2,R2,R6
    ADD R4,R4,#1
    CMP R4,#3
    BNE LOOP
    STR R2,[R3]
    //Result stored in R2
.END