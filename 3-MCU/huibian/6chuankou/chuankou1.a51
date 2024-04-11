	ORG 0000H
	LJMP MAIN
	ORG 0200H
MAIN:
	MOV SP,#60H
	MOV TMOD,#20H	;设置T1为方式2
	MOV SCON,#50H	;设置串口为方式1
	MOV PCON,#00H	;波特率不倍增
	MOV TH1,#0FDH
	MOV TL1,#0FDH	;设置波特率为9600
	SETB TR1		;T1开始计数
	MOV R6,#5		;标记按下按键次数
LOOP:
	MOV A,P1
	CJNE A,#0XFE,LOOP	;不等说明按键未按下继续等待
	LCALL DELAY10MS		;消抖
	CJNE A,#0XFE,LOOP	;再次判断按键是否按下
	DJNZ R6,K1			;寄存器内容减一，非0转移
	MOV R6,#5
K1:					;第一次按下按键
	CJNE R6,#4,K2
	MOV A,#'A'
	MOV SBUF,A		;开始发送，发送字母为A
	MOV A,#0XFE		;led1亮
	MOV P0,A
K2:					;第二次按下按键
	CJNE R6,#3,K3
	MOV SBUF,#'B'
	MOV A,#0XFD		;led2亮
	MOV P0,A
K3:					;第三次按下按键
	CJNE R6,#2,K4
	MOV SBUF,#'C'
	MOV A,#0XF6		;都亮
	MOV P0,A
K4:					;第四次按下按键
	CJNE R6,#1,WAIT
	MOV SBUF,#'0'
	MOV A,#0XFF 	;都灭
	MOV P0,A
WAIT:					;等待按键
	JNB TI,$			;为0原地跳，等待发送结束
	CLR TI				;清0
	LJMP LOOP
DELAY10MS:				;@11.0592MHz
	PUSH 30H
	PUSH 31H
	MOV 30H,#18
	MOV 31H,#230
NEXT:
	DJNZ 31H,NEXT
	DJNZ 30H,NEXT
	POP 31H
	POP 30H
	RET

END