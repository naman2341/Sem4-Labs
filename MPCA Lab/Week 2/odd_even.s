
.text
        
        MOV r1, #12
        ANDs r2, r1, #1
        
        
        BEQ condition
                MOV r0, #0xFF
                B exit
        condition:
                MOV r0, #0x00
        exit:
                SWI 0x011
.end