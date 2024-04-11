`timescale 1ns / 1ps
`define UD #1
module seq_control
(
	input clk,
	input sec_en,//数码管秒闪控制
	input [2:0]control_dig,
	input [1:0]sel,
	input [3:0]key,
	output reg [3:0]dig,
	output reg [7:0]smg
);
/*===================================================
				
===================================================*/
reg [3:0] shin_control=4'd0;

always @(posedge clk)
begin
	if(shin_control==4'd8)//0-8一共9个周期 在校正时延迟点亮数码管  36个周期显示一次 亮度降低
		shin_control <= `UD 4'd0;
	else 
		shin_control <= `UD shin_control + 1'b1;
end 


always @(*)
begin
	case(control_dig)
		4'd0: //正常显示
			case(sel)
				2'd0:dig = 4'b0001;
				2'd1:dig = 4'b0010;
				2'd2:dig = 4'b0100;
				2'd3:dig = 4'b1000; //第四位
			default:dig =  4'b0000;
			endcase
		4'd5: //计时显示
			case(sel)
				2'd0:dig = 4'b0000;
				2'd1:dig = 4'b0000;
				2'd2:dig = 4'b0100;
				2'd3:dig = 4'b1000;
			default:dig =  4'b0000;
			endcase        
		4'd4://时钟高位校准
			case(sel)
				2'd0:begin if(sec_en) dig = 4'b0001 ;else dig = 4'b0000; end
				2'd1:dig = 4'b0010;
				2'd2:dig = 4'b0100;
				2'd3:dig = 4'b1000;
			default:dig =  4'b0000;
			endcase
		4'd3://时钟低位校准
			case(sel)
				2'd0:dig = 4'b0001;
				2'd1:begin if(sec_en) dig = 4'b0010 ;else dig = 4'b0000; end 
				2'd2:dig = 4'b0100;
				2'd3:dig = 4'b1000;
			default:dig =  4'b0000;
			endcase
		4'd2: //分钟高位校准
			case(sel)
				2'd0:dig = 4'b0001;
				2'd1:dig = 4'b0010;
				2'd2:begin if(sec_en) dig = 4'b0100 ;else dig = 4'b0000; end 
				2'd3:dig = 4'b1000;
			default:dig = 4'b0000;
			endcase
		4'd1: //分钟低位校准
			case(sel)
				2'd0:dig = 4'b0001;
				2'd1:dig = 4'b0010;
				2'd2:dig = 4'b0100;
				2'd3:begin if(sec_en) dig = 4'b1000 ;else dig = 4'b0000; end 
			default:dig = 4'b0000;
			endcase
		default:dig = 4'b0000;
	endcase 
end

//===========================================

//===========================================
always @(*)
begin
	case(key)
		4'd0:smg = ~(8'h3f);//"0"  
		4'd1:smg = ~(8'h06);//"1"  
		4'd2:smg = ~(8'h5b);//"2"  
		4'd3:smg = ~(8'h4f);//"3"  
		4'd4:smg = ~(8'h66);//"4"  
		4'd5:smg = ~(8'h6d);//"5"  
		4'd6:smg = ~(8'h7d);//"6"  
		4'd7:smg = ~(8'h07);//"7"  
		4'd8:smg = ~(8'h7f);//"8"  
		4'd9:smg = ~(8'h6f);//"9"  
		default:smg = ~(8'h00);		
	endcase
end 

endmodule