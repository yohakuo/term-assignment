module seg_decode_demo(
    input  [3:0] data_i,
    output [7:0] seg_code_o
);
    seg_decode #(
        .INVERSE      (1'b1)
    )seg_decode_i(
        .data_i       (data_i[3:0]),
        .seg_code_o   (seg_code_o[7:0])
    );

endmodule