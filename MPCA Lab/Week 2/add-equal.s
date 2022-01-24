.text

        MOV r0, #30
        MOV r1, #10
        SUBs r2, r0, r1
        BEQ condition
                SUB r3, r0, r1
                B exit
        condition:
                ADD r3, r0, r1
        exit:
                SWI 0x011
.end