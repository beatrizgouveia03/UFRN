ARCHITECTURE arch_3 OF reg IS
BEGIN
	PROCESS(clk)
	VARIABLE a, b : BIT;
	BEGIN
		IF(clk = '1') THEN
			a := d;
			b := a;
			q <= b;
		END IF;
	END PROCESS;
END arch_3;
