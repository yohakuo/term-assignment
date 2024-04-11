
module state_ctrl(
    input clk,
    input rst,
    input cout_i,
    output reg clear_o,
    output reg count_en_o,
    output reg lock_o
);

localparam SIM_DELAY =1;

localparam ST_IDLE=2'h0;
localparam ST_CLR=2'h1;
localparam ST_CNT=2'h2;
localparam ST_LOCK=2'h3;

wire cout;
reg [1:0] curr_state;
reg [1:0] next_state;

always @(posedge clk or posedge rst) begin
    if(rst) begin   
        curr_state <= #SIM_DELAY ST_IDLE;
        end else begin  
            curr_state <= #SIM_DELAY next_state;
    end
end

always @(*) begin
    case(curr_state)
    ST_IDLE: next_state=ST_CLR;
    ST_CLR: next_state=ST_CNT;
    ST_CNT: next_state=cout_i?ST_LOCK:ST_CNT;
    ST_LOCK: next_state=ST_IDLE;
    default: next_state=ST_IDLE;
    endcase
end

always @(posedge clk or posedge rst) begin
    if(rst)begin
        clear_o = #SIM_DELAY 1'b0;
        count_en_o = #SIM_DELAY 1'b0;
        lock_o = #SIM_DELAY 1'b0;
    end else begin
        clear_o = #SIM_DELAY 1'b0;
        count_en_o = #SIM_DELAY 1'b0;
        lock_o = #SIM_DELAY 1'b0;
        case(curr_state)
            ST_CLR:clear_o = #SIM_DELAY 1'b1;
            ST_CNT:count_en_o = #SIM_DELAY 1'b1;
            ST_LOCK:lock_o = #SIM_DELAY 1'b1;
        endcase
    end
end

endmodule
        
