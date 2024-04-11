	ORG 0000H
	LJMP MAIN
	ORG 0200H
MAIN:
	MOV SP,#60H
	MOV TMOD,#20H	;����T1Ϊ��ʽ2
	MOV SCON,#50H	;���ô���Ϊ��ʽ1
	MOV PCON,#00H	;�����ʲ�����
	MOV TH1,#0FDH
	MOV TL1,#0FDH	;���ò�����Ϊ9600
	SETB TR1		;T1��ʼ����
	MOV R6,#5		;��ǰ��°�������
LOOP:
	MOV A,P1
	CJNE A,#0XFE,LOOP	;����˵������δ���¼����ȴ�
	LCALL DELAY10MS		;����
	CJNE A,#0XFE,LOOP	;�ٴ��жϰ����Ƿ���
	DJNZ R6,K1			;�Ĵ������ݼ�һ����0ת��
	MOV R6,#5
K1:					;��һ�ΰ��°���
	CJNE R6,#4,K2
	MOV A,#'A'
	MOV SBUF,A		;��ʼ���ͣ�������ĸΪA
	MOV A,#0XFE		;led1��
	MOV P0,A
K2:					;�ڶ��ΰ��°���
	CJNE R6,#3,K3
	MOV SBUF,#'B'
	MOV A,#0XFD		;led2��
	MOV P0,A
K3:					;�����ΰ��°���
	CJNE R6,#2,K4
	MOV SBUF,#'C'
	MOV A,#0XF6		;����
	MOV P0,A
K4:					;���Ĵΰ��°���
	CJNE R6,#1,WAIT
	MOV SBUF,#'0'
	MOV A,#0XFF 	;����
	MOV P0,A
WAIT:					;�ȴ�����
	JNB TI,$			;Ϊ0ԭ�������ȴ����ͽ���
	CLR TI				;��0
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