	ORG 0000H 
	AJMP MAIN ;利用跳转指令跳转到主函数MAIN
	ORG 0003H ;外部中断O的入口为内部ROM的0003H单元
	AJMP I0   ;利用跳转指令跳转到到中断函数中
	ORG 0150H
MAIN:

	SETB EA		;开启总中断(置1)
	SETB EX0	;开启外部中断0
	SETB IT0	;设置外部中断源触发方式为下降沿触发
	SETB P0.0	;初始化LED为灭
	SJMP $		;跳转到自身

ORG 0300H		;中断程序从内部ROM的030OH单元开始保存
I0:
	CPL P0^0	;对P0.取反，改变LED状态
	RETI		;返回主程序
	END

