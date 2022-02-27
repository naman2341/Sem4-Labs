Ldr R0, =A
mov r10,#9
mov r1,#0
mov r2,#1
str r1,[r0],#4
add r3,r2,r1
loop: str r3,[r0],#4
add r3,r2,r1
mov r1,r2
mov r2,r3
sub r10,r10,#1
cmp r10,#0
beq exit
bne loop
exit: swi 0x11
A: .word