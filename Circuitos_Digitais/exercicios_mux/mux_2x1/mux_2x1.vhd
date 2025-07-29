ENTITY mux_2x1 IS
PORT (  a, b : IN BIT;  -- data inputs
	sel : IN BIT; 	-- selector
	s : OUT BIT); 	-- data output
END mux_2x1;

ARCHITECTURE structural OF mux_2x1 IS
BEGIN
	s <= (a AND NOT sel) OR (b AND sel);
END structural; 
