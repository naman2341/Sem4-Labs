.TEXT
    MOV R0,#209
    MOV R1,#11
WHILE:
    CMP R0,R1
    BEQ L1
    BGT L2
    B L3
L1:
    MOV R3,R0
    SWI 0X011
    B L4
L2:
    SUB R0,R1
    B WHILE
L3:
    SUB R1,R0
    B WHILE
L4: .END