LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY contador IS
    GENERIC (W : NATURAL := 4);
    PORT (
        d : IN STD_LOGIC_VECTOR(W-1 DOWNTO 0); -- data input
        inc : IN BIT; -- increments
        clk : IN BIT; -- clock
        clrn : IN BIT; -- clear
        ena : IN BIT; -- enable
        load : IN BIT; -- load
        q : BUFFER STD_LOGIC_VECTOR(W-1 DOWNTO 0) -- data output
    );
END contador;

ARCHITECTURE behavior OF contador IS
BEGIN
    PROCESS (clk, clrn, ena)
    BEGIN
        IF (clrn = '0') THEN
            q <= (OTHERS => '0');
        ELSIF (ena = '0') THEN
                q <= q;
        ELSIF (clk'EVENT AND clk = '1') THEN
                            IF (load = '1') THEN
                    q <= d;
                ELSE
                    IF (inc = '0') THEN
                        q <= q - 1;
                    ELSE
                        q <= q + 1;
                    END IF;
                END IF;
            END IF;
            END PROCESS;
END behavior;