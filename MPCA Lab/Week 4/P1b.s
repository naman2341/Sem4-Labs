.DATA
    A: .WORD 12,144
.TEXT
    LDR R5,=A
    ADD R6,R5,#4
    LDR R0,[R5]
    LDR R1,[R6]
WHILE:
    CMP R0,R1
    BEQ L1
    BGT L2
    B L3
L1:
    MOV R3,R0
    STR R3,[R4]
    SWI 0X011
    B L4
L2:
    SUB R0,R1
    B WHILE
L3:
    SUB R1,R0
    B WHILE
L4: .END