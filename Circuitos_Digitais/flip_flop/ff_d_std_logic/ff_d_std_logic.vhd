LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;

ENTITY ff_d_std_logic IS
PORT (  d 	: IN STD_LOGIC;	  -- data input
	clk 	: IN STD_LOGIC;   -- clock
	q 	: OUT STD_LOGIC); -- data output
END ff_d_std_logic;

-----------------------------------------

ARCHITECTURE arch OF ff_d_std_logic IS
BEGIN
	PROCESS(clk)
	BEGIN
		IF rising_edge(clk) THEN
			q <= d;
		END IF;
	END PROCESS;
END arch;
