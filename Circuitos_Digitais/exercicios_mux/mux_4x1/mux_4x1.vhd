ENTITY mux_4x1 IS
PORT (  a0, a1, a2, a3 : IN BIT;  	 -- data inputs
	sel: IN BIT_VECTOR (1 DOWNTO 0); -- selector
	s : OUT BIT); 		 	 -- data output
END mux_4x1;