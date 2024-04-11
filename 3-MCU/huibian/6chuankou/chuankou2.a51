	ORG 0000H
	LJMP MAIN
	ORG 0300H
MAIN:
	MOV SP,#60H
	MOV TMOD,#20H	;设置T1为方式2
	MOV SCON,#50H	;设置串口为方式1
	MOV PCON,#00H	;波特率不倍增
	MOV TH1,#0FDH
	MOV TL1,#0FDH	;设置波特率为9600
	SETB TR1		;T1开始计数
	MOV R6,#5

LOOP:	
	JNB RI,$			;为0转移，等待接收
	CLR RI
	MOV A,SBUF			;接收数据
	DJNZ R6,K1			;寄存器内容减1，非0转移
	MOV R6,#5

K1:					
	CJNE R6,#4,K2
	MOV A,#0XFE		;led1亮
	MOV P0,A
	LJMP LOOP	;等待下一次接收数据
K2:					
	CJNE R6,#3,K3
	MOV A,#0XFD		;led2亮
	MOV P0,A
	LJMP LOOP	;等待下一次接收数据
K3:					
	CJNE R6,#2,K4
	MOV A,#0XF6		;都亮
	MOV P0,A
	LJMP LOOP	;等待下一次接收数据
K4:
	CJNE R6,#1,LOOP
	MOV A,#0XFF 	;都灭
	MOV P0,A
	LJMP LOOP	;等待下一次接收数据

END