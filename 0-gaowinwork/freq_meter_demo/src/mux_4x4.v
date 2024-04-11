`timescale 1ns/1ns
module mux_4x4(
    input   [3:0] index_i,
    input   [15:0] data_i,
    output reg [3:0] data_o
);
  always @(*) begin
   case(index_i[3:0])
   4'b0001: data_o = data_i[3:0];
   4'b0010: data_o = data_i[7:4];
   4'b0100: data_o = data_i[11:8];
   4'b1000: data_o = data_i[15:12];
   default :data_o=4'h0;
   endcase
  end
endmodule