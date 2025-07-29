
ENTITY maq_estados IS
PORT (	clk 	: IN BIT; -- clock
	    clrn	: IN BIT; -- clear
	    up	: IN BIT; -- input 1
	    down	: IN BIT; -- input 2
	    inc, load 	: OUT BIT; -- output
cont, reg : OUT BIT); -- enables
END  maq_estados;

ARCHITECTURE arch OF  maq_estados IS
TYPE state_type IS (parar, subir, descer);

SIGNAL state_reg : state_type;
SIGNAL next_state: state_type;

BEGIN
p_state_reg: PROCESS(clk, state_reg, clrn)
	BEGIN
		IF (clrn='0') THEN
			state_reg <= parar;
		ELSE
			state_reg <= next_state;
		END IF;
	END PROCESS;

p_next_state: PROCESS(state_reg, up, down)
	BEGIN
		CASE (state_reg) IS
			WHEN parar => 	IF (up ='1') THEN
						next_state <= subir;
					ELSIF (down = '1') THEN
						next_state <= descer;
                    ELSE 
                        next_state <= parar;
					END IF;
			WHEN subir =>  	IF (up ='1') THEN
						next_state <= subir;
                    ELSE 
                        next_state <= parar;
					END IF;
            WHEN descer =>  IF (down = '1') THEN
						next_state <= descer;
                    ELSE 
                        next_state <= parar;
                    END IF;
			WHEN OTHERS => 	next_state <= parar;
			END CASE;
	END PROCESS;
-- Output
    p_output: PROCESS(state_reg)
	BEGIN
        IF(state_reg = subir) THEN
            inc <= '1';
            load <= '0';
			cont <= '1' ;
			reg <= '0';
        ELSIF(state_reg = descer) THEN
            inc <= '0';
            load <= '0';
			cont <= '1';
			reg <= '0';
        ELSE
            inc <= '0';
            load <= '1';
			cont <= '0';
			reg <= '1';
        END IF;
    END PROCESS;
END arch;