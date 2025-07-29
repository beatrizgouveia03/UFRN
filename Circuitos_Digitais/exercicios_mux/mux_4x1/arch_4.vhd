ARCHITECTURE arch_4 OF mux_4x1 IS
BEGIN
	WITH sel SELECT
		s  <= 	a0 WHEN "00",
			a1 WHEN "01",
			a2 WHEN "10",
			a3 WHEN OTHERS;
END arch_4;
