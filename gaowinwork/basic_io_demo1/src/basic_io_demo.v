module basic_io_demo(
    input [3:0] key_i,
    output [3:0] led_o
);

        
    assign led_o[3:0] = key_i[3:0];

endmodule