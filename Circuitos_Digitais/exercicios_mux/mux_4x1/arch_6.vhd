ARCHITECTURE arch_6 OF mux_4x1 IS
BEGIN
	PROCESS( a0, a1, a2, a3, sel)
	BEGIN
		CASE sel IS
			WHEN "00" => s <= a0;
			WHEN "01" => s <= a1;
			WHEN "10" => s <= a2;
			WHEN OTHERS => s <= a3;
		END CASE;
	END PROCESS;
END arch_6;