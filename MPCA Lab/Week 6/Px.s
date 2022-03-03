.text
    ldr r0,=a;
    mov r1,#0
    mov r2,#0
    ldr r4,=sum

    bl loop
        str r2,[r4]
        swi 0x011

loop:
    ldr r3,[r0],#4
    movs r3,r3
        bpl positive
    l1: add r1,r1,#1
        cmp r3,#10
            bne loop
            mov pc,lr

positive: add r2,r2,r3 
        b l1