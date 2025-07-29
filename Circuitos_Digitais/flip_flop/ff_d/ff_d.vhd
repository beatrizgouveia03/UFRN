ENTITY ff_d IS
PORT (  d : IN BIT;	-- data input
	clk : IN BIT;	-- clock
	q : OUT BIT);	-- data output
END ff_d;

-----------------------------------

ARCHITECTURE arch OF  ff_d IS
BEGIN
	PROCESS(clk)
	BEGIN
		IF(clk = '1') THEN
			q <= d;
		END IF;
	END PROCESS;
END arch;
