;; 单个数码管循环显示0~9数字
		ORG	000H
START:
		MOV R4,#0				;循环显示10次

LOOP:							;循环显示数字，R4递增
		MOV A,R4
		MOV DPTR,#NTABLE
		MOVC A,@A+DPTR
		MOV P0,A
		CALL DELAY
		INC R4
		CJNE	R4,#10,LOOP		;R4递增到10时结束循环
		JMP START

		;; 数码管显示编码表
NTABLE:	DB	3FH,06H,5BH,4FH,66H,6DH,7DH,07H,7FH,6FH

DELAY:							;延时500ms
		MOV R1,#50
D1:		MOV R2,#20
D2:		MOV R3,#248
		DJNZ	R3,$
		DJNZ	R2,D2
		DJNZ	R1,D1

		RET
		END
