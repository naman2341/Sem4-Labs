;Write a program in ARM7TDMI-ISA to transfer a block of 256 words stored  
;at memory location X to memory location Y using  Load Multiple and Store 
;Multiple instructions. The rate of transfer is 32 bytes.

; HERE 24 WORDS OF DATA IS TO BE TRANSFERED USING 8 GPRS. 
; THIS IS REPEATED 3 TIMES HICH IS THE LOOP COUNT.

.DATA

  A: .WORD 10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240
  B: .WORD 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,00,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

.TEXT
  LDR R0,=A   ; ARRAY A INITIALISED
  LDR R9,=B   ; ARRAY B INITIALISED
  
  MOV R10,#0   ; COUNT REGISTER
  
LOOP:  LDMIA R0!,{R1-R8}   ; R1-R8 REGISTERS USED AS BUFFER REGISTERS TO CARRY THE DATA 
	   STMIA R9!,{R1-R8}
       ADD R10,R10,#1
       CMP R10,#3          ; COUNT IS 3 TIMES AS 24 WORDS ARE TO BE TRANSFERED.
       BNE LOOP
       SWI 0X011
 .END