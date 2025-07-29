ENTITY mux_8x1 IS
PORT (  a : IN BIT_VECTOR(7 DOWNTO 0);	 -- data inputs
	sel : IN BIT_VECTOR(2 DOWNTO 0); -- selector
	s : OUT BIT); 			 -- data output
END mux_8x1;

ARCHITECTURE structural OF mux_8x1 IS

COMPONENT mux_2x1
PORT (  a, b : IN BIT;  -- data inputs
	sel : IN BIT; 	-- selector
	s : OUT BIT); 	-- data output
END COMPONENT; 
	
COMPONENT mux_4x1
PORT (  a0, a1, a2, a3 : IN BIT;  	 -- data inputs
	sel: IN BIT_VECTOR (1 DOWNTO 0); -- selector
		s : OUT BIT); 		 -- data output
END COMPONENT;

SIGNAL s0, s1 : BIT;
SIGNAL sel0 : BIT_VECTOR (1 DOWNTO 0);

BEGIN
	PROCESS (sel)
	BEGIN
		sel0(1) <= sel(1); 
		sel0(0) <= sel(0);
	END PROCESS;

	u0 : mux_4x1 PORT MAP ( a(7), a(6), a(5), a(4), sel0, s0);
	u1 : mux_4x1 PORT MAP ( a(3), a(2), a(1), a(0), sel0, s1);
	u2 : mux_2x1 PORT MAP ( s0, s1, sel(2), s);
	
END structural;
		
	
