ARCHITECTURE structural OF mux_2x1_Wbits IS 
BEGIN
	f0 : FOR i IN (W-1) DOWNTO 0 GENERATE
		s(i) <= (a(i) AND NOT sel) OR (b(i) AND sel);
	END GENERATE f0;
END structural;