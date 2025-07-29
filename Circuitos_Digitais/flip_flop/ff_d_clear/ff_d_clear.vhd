ENTITY ff_d_clear IS
PORT (  d 	: IN BIT;	-- data input 
	clk 	: IN BIT;	-- clock
	clrn 	: IN BIT;	-- clear
	q 	: OUT BIT);	-- data output
END ff_d_clear;

------------------------------------------------------

ARCHITECTURE arch OF ff_d_clear IS
BEGIN
	PROCESS(clk, clrn)
	BEGIN
		IF(clrn = '0') THEN 
			q <= '0';
		ELSIF(clk'EVENT AND clk = '1') THEN
			q <= d;
		END IF;
	END PROCESS;
END arch;
