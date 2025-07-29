ENTITY mux_2x1_Wbits IS
GENERIC (W : NATURAL := 3);

PORT (  a, b : IN BIT_VECTOR (W-1 DOWNTO 0);  -- data inputs
	sel : IN BIT; 			     -- selector
	s   : OUT BIT_VECTOR (W-1 DOWNTO 0));-- data output
END mux_2x1_Wbits;

