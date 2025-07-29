ARCHITECTURE arch_2 OF reg IS
SIGNAL a, b : BIT;
BEGIN
	PROCESS(clk)
	BEGIN
		IF(clk = '1') THEN
			a <= d;
			b <= a;
		END IF;
	END PROCESS;
	q <= b;
END arch_2;
