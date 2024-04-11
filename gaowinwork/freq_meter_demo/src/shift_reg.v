`timescale 1ns/1ns

module shift_reg #(
    parameter DIRECTION ="LEFT",
    parameter WIDTH     =9,
    parameter INIT_VALUE=9'h1
)(
    input                clk,
    input                rst,
    input                load_i,
    input     [WIDTH-1:0]load_data_i,
    input                reg_in_i,
    output reg[WIDTH-1:0]reg_out_o
);
    localparam SIM_DELAY = 1;

    always @(posedge clk or posedge rst or posedge load_i)begin
        if(rst) begin
            reg_out_o <= #SIM_DELAY INIT_VALUE;
        end else if(load_i)begin
            reg_out_o <= #SIM_DELAY load_data_i;
        end else begin
            reg_out_o <= #SIM_DELAY DIRECTION == "LEFT"?
                           {reg_out_o[WIDTH-2:0], reg_in_i} :
                           {reg_in_i, reg_out_o[WIDTH-1:1]};
        end
    end

endmodule