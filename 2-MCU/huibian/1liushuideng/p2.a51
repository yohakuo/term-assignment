ORG 0000H	//���³����0000h��ʼ����
	LJMP MAIN	//��ת��main

	ORG 0030H	//���³����0030h��ʼ����
	MAIN:
	MOV A,#0FEH		//1111 1110 0FEH
	LOOP:			
	MOV P2,A			//0111 1111 7FH
	RL A				//1111 1101 0FDH
	LCALL DELAY		//��ʱ
	CJNE A,#0FEH,LOOP	////1111 1110 0FEH���Ƚ�A��0feh������Ⱦ�����LOOP
	MOV A,#0BFH		//1011 1111 0BFH

	LOOP1:
	MOV P2,A
	RR A
	LCALL DELAY
	CJNE A,#7FH,LOOP1
	MOV A,#0FDH
	SJMP LOOP		//��ת��LOOP
	
	DELAY:
	MOV R7,#240
	D1:
	MOV R6,#240
	DJNZ R6,$		//�Լ�һ��ԭ����
	DJNZ R7,D1	//R7�Լ�һ��ԭ����
	RET
	
	END
