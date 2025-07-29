LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY elevador IS
PORT (  buttons     : IN STD_LOGIC_VECTOR(8 DOWNTO 0);    -- data input  
        clk, clrn   : IN BIT;                             -- clk
        display		: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)    -- data output  
);
END elevador;

ARCHITECTURE arch OF elevador IS

-- Botões do elevador
COMPONENT cod_destino IS
PORT(	buttons         : IN STD_LOGIC_VECTOR(8 DOWNTO 0);    -- botões
	    floor_level 	: OUT STD_LOGIC_VECTOR(3 DOWNTO 0)    -- andar destino
);
END COMPONENT;

-- Comparador de andar com destino
COMPONENT comp_andares IS
PORT (  andar, destino  : IN STD_LOGIC_VECTOR(3 DOWNTO 0);   -- andar atual, andar destino  
        result          : OUT BIT_VECTOR (1 DOWNTO 0)        -- comparação ([0] - UP, [1] - DOWN)
);
END COMPONENT;

-- Display do elevador
COMPONENT dec_display IS
PORT (	fl	        : IN STD_LOGIC_VECTOR(3 DOWNTO 0);    -- andar atual  
	    display		: OUT STD_LOGIC_VECTOR(6 DOWNTO 0)    -- display
);
END COMPONENT;

-- Contador de andares/ andar atual
COMPONENT contador IS
    GENERIC (W : NATURAL := 4);
    PORT (
        d : IN STD_LOGIC_VECTOR(W-1 DOWNTO 0);  -- andar atual
        inc : IN BIT;                           -- incremento maq_estados
        clk : IN BIT;                           -- clock
        clrn: IN BIT;                           -- clear == 1
        ena : IN BIT;                           -- enable
        load : IN BIT;                          -- load
        q : BUFFER STD_LOGIC_VECTOR(W-1 DOWNTO 0) -- andar resultante
    );
END COMPONENT;

--Registrador de destino
COMPONENT reg_andar IS
    GENERIC (w : NATURAL := 4);
    PORT (
        d : IN STD_LOGIC_VECTOR (W-1 DOWNTO 0); -- andar destino
        clk : IN BIT;                     -- clock
        clrn : IN BIT;                     -- clear == 1
        ena : IN BIT;                     -- enable
        q : OUT STD_LOGIC_VECTOR (W-1 DOWNTO 0) -- andar destino
    );
END COMPONENT;

-- Máquina de estados do elevador
COMPONENT maq_estados IS
PORT (	clk 	: IN BIT;   -- clock
	    clrn	: IN BIT;   -- clear == 1
	    up	: IN BIT;       -- comparador up
	    down	: IN BIT;   -- comparador down
	    inc, load	: OUT BIT;  -- incremento, load (contador)
cont, reg : OUT BIT); -- enables
END COMPONENT;

SIGNAL comparador: BIT_VECTOR(1 DOWNTO 0);
SIGNAL andar_atual: STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL andar_destino: STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL botao_apertado: STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL incremento, load, cont, reg: BIT;

BEGIN
    b0 : cod_destino PORT MAP (buttons, botao_apertado);
    r0 : reg_andar PORT MAP (botao_apertado, clk, clrn , reg, andar_destino);
    c0 : comp_andares PORT MAP (andar_atual, andar_destino, comparador); 
    m0 : maq_estados PORT MAP (clk, clrn, comparador(0), comparador(1), incremento, load, cont, reg);
    a0 : contador PORT MAP ("0000", incremento, clk, clrn , cont , load, andar_atual);
    d0 : dec_display PORT MAP (andar_atual, display);

END arch;