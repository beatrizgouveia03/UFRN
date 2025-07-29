ENTITY ff_d_clear_ena IS
PORT (  d	: IN BIT;	-- data input
	clk 	: IN BIT;	-- clock
	clrn	: IN BIT;	-- clear
	ena	: IN BIT;	-- enable
	q 	: OUT BIT);	-- data output
END ff_d_clear_ena;

ARCHITECTURE arch OF ff_d_clear_ena IS
BEGIN
	PROCESS(clk,clrn)
	BEGIN
		IF(clrn = '0') THEN
			q <= '0';
		ELSIF(clk'EVENT AND clk = '1') THEN
			IF(ena = '1') THEN
				q <= d;
			END IF;
		END IF;
	END PROCESS;
END arch;
