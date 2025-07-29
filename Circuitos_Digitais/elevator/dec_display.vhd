LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY dec_display IS
PORT (	fl	: IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	display		: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)
);
END dec_display;

ARCHITECTURE behavior OF dec_display IS
BEGIN
	PROCESS(fl)
		BEGIN
			CASE fl IS
				WHEN "0000" => display <= "1100111";
				WHEN "0001" => display <= "0110000";
				WHEN "0010" => display <= "1101101";
				WHEN "0011" => display <= "1111001";
				WHEN "0100" => display <= "0110011";
				WHEN "0101" => display <= "1011011";
				WHEN "0110" => display <= "1011111";
				WHEN "0111" => display <= "1110000";
				WHEN "1000" => display <= "1111111";
				WHEN OTHERS => display <= "0000000";
			END CASE;
	END PROCESS;
END behavior;
