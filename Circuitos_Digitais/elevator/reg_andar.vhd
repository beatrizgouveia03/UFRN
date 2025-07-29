LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY reg_andar IS
    GENERIC (w : NATURAL := 4);
    PORT (
        d : IN STD_LOGIC_VECTOR (W-1 DOWNTO 0); -- input
        clk : IN BIT; -- clock
        clrn : IN BIT; -- clear
        ena : IN BIT; -- enable
        q : OUT STD_LOGIC_VECTOR (W-1 DOWNTO 0) -- output
    );
END reg_andar;

ARCHITECTURE arch OF reg_andar IS
BEGIN
    PROCESS (clk, clrn)
    BEGIN
        IF (clrn = '0') THEN
            q <= (OTHERS => '0');
        ELSIF (clk'EVENT AND clk = '1') THEN
            IF (ena = '1') THEN
                q <= d;
            END IF;
        END IF;
    END PROCESS;
END arch;