ENTITY mux_16x1 IS
PORT (  a : IN BIT_VECTOR(15 DOWNTO 0);	  -- data input
	sel : IN BIT_VECTOR(3 DOWNTO 0);  -- selector
	s : OUT BIT);			  -- data output
END mux_16x1;

ARCHITECTURE arch OF mux_16x1 IS

COMPONENT mux_4x1
PORT (  a0, a1, a2, a3 : IN BIT;  	 -- data inputs
	sel: IN BIT_VECTOR (1 DOWNTO 0); -- selector
	s : OUT BIT); 			 -- data output
END COMPONENT;

SIGNAL s0, s1, s2, s3 : BIT;
SIGNAL sel0, sel1 : BIT_VECTOR(1 DOWNTO 0);

BEGIN
	PROCESS(sel)
	BEGIN
		sel0(0) <= sel(0);
		sel0(1) <= sel(1);
		sel1(0) <= sel(2);
		sel1(1) <= sel(3);
	END PROCESS;
	
	u0 : mux_4x1 PORT MAP ( a(15), a(14), a(13), a(12), sel0, s0);
	u1 : mux_4x1 PORT MAP ( a(11), a(10), a(9), a(8), sel0, s1);
	u2 : mux_4x1 PORT MAP ( a(7), a(6), a(5), a(4), sel0, s2);
	u3 : mux_4x1 PORT MAP ( a(3), a(2), a(1), a(0), sel0, s3);
	u4 : mux_4x1 PORT MAP ( s0, s1, s2, s3, sel1, s);

END arch;
