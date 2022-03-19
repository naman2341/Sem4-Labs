.data
    txt: .asciz "pes university"
    delay: .word 15000
.text
    mov r0,#0
    mov r1,#7
    ldr r2,=txt 
    ldr r3,=delay
    ldr r3,[r3]
    mov r4,#0
loop:
    swi 0x206
    swi 0x204
    bl delay_loop
    cmp r0,#30
    addne r0,r0,#1
    moveq r0,#0
    b loop 
delay_loop:
    cmp r4,r3
    addne r4,r4,#1 
    bne delay_loop
    mov r4,#0
    mov pc,lr