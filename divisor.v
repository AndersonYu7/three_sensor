module divisor (
        input      clk_i,
        input      rst_n_i,
        output reg clk_o
    );

    parameter Threshold = 25000000;
    reg [31:0] count_r;

    always @(posedge clk_i or negedge rst_n_i) begin
        if (!rst_n_i) begin
            count_r <= 0;
            clk_o   <= 0;
        end
        else begin
            count_r <= (count_r < Threshold) ? count_r + 1 : 0;
            clk_o   <= (count_r < Threshold) ? clk_o : ~clk_o;
        end
    end

endmodule