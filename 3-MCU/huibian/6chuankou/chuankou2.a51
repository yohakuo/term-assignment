	ORG 0000H
	LJMP MAIN
	ORG 0300H
MAIN:
	MOV SP,#60H
	MOV TMOD,#20H	;����T1Ϊ��ʽ2
	MOV SCON,#50H	;���ô���Ϊ��ʽ1
	MOV PCON,#00H	;�����ʲ�����
	MOV TH1,#0FDH
	MOV TL1,#0FDH	;���ò�����Ϊ9600
	SETB TR1		;T1��ʼ����
	MOV R6,#5

LOOP:	
	JNB RI,$			;Ϊ0ת�ƣ��ȴ�����
	CLR RI
	MOV A,SBUF			;��������
	DJNZ R6,K1			;�Ĵ������ݼ�1����0ת��
	MOV R6,#5

K1:					
	CJNE R6,#4,K2
	MOV A,#0XFE		;led1��
	MOV P0,A
	LJMP LOOP	;�ȴ���һ�ν�������
K2:					
	CJNE R6,#3,K3
	MOV A,#0XFD		;led2��
	MOV P0,A
	LJMP LOOP	;�ȴ���һ�ν�������
K3:					
	CJNE R6,#2,K4
	MOV A,#0XF6		;����
	MOV P0,A
	LJMP LOOP	;�ȴ���һ�ν�������
K4:
	CJNE R6,#1,LOOP
	MOV A,#0XFF 	;����
	MOV P0,A
	LJMP LOOP	;�ȴ���һ�ν�������

END