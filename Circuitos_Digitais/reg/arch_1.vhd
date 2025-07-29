ARCHITECTURE arch_1 OF reg IS
SIGNAL a, b : BIT;
BEGIN
	PROCESS(clk)
	BEGIN
		IF(clk = '1') THEN
			a <= d;
			b <= a;
			q <= b;
		END IF;
	END PROCESS;
END arch_1;
