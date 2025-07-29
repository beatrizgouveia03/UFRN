ARCHITECTURE arch_3 OF mux_4x1 IS
BEGIN
	s  <= 	a0 WHEN sel = "00" ELSE
		a1 WHEN sel = "01" ELSE
		a2 WHEN sel = "10" ELSE
		a3 ;
END arch_3;