module seg_decode #(
    parameter INVERSE = 1'b1
)(
    input [3:0] data_i,
    output [7:0] seg_code_o
);
    reg [7:0] seg_code;

    assign seg_code_o[7:0] =INVERSE ?~seg_code[7:0] : seg_code[7:0];

    always @(*) begin
        case(data_i[3:0])
        4'h0: seg_code = 8'h3f;
        4'h1: seg_code = 8'h06;
        4'h2: seg_code = 8'h5b;
        4'h3: seg_code = 8'h4f;
        4'h4: seg_code = 8'h66;
        4'h5: seg_code = 8'h6d;
        4'h6: seg_code = 8'h7d;
        4'h7: seg_code = 8'h07;
        4'h8: seg_code = 8'h7f;
        4'h9: seg_code = 8'h6f;
        default:seg_code = 8'h00;
        endcase
    end
endmodule