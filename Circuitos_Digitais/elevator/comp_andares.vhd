LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY comp_andares IS
PORT (  andar, destino : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
        result : OUT BIT_VECTOR (1 DOWNTO 0)
);
END comp_andares;

ARCHITECTURE behavior OF comp_andares IS
BEGIN
    PROCESS( andar, destino)
    BEGIN  
        IF andar > destino THEN
            result <= "10";
           ELSIF andar < destino THEN
            result <= "01";
        ELSE
            result <= "00";
        END IF;
    END PROCESS;
END behavior;