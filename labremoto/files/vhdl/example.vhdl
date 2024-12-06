-- design.vhdl
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity counter is
    Port ( clk      : in  STD_LOGIC;
           reset    : in  STD_LOGIC;
           count    : out STD_LOGIC_VECTOR(3 downto 0));
end counter;

architecture Behavioral of counter is
    signal count_reg : STD_LOGIC_VECTOR(3 downto 0) := "0000";
begin
    process(clk, reset)
    begin
        if reset = '1' then
            count_reg <= "0000";
        elsif rising_edge(clk) then
            count_reg <= count_reg + 1;
        end if;
    end process;

    count <= count_reg;
end Behavioral;
