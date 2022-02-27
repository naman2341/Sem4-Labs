.text idr1
ldr r0,=data1
ldr r4, =0x05
ldr r1, [r0], #04
sub r4, r4, #01

back :
    LDR R2, [R0]
    cmp r1, r2
    bls less
    mov r1, r2

less:
    add r0, r0, #04
    sub r4, r4, #01
    cmp r4, #00
    
    
