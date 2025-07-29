ARCHITECTURE behavior OF mux_2x1_Wbits IS
BEGIN
	PROCESS( a, b, sel)
	BEGIN
		IF( sel = '0') THEN
			s <= a;
		ELSE
			s <= b;
		END IF;
	END PROCESS;
END behavior;