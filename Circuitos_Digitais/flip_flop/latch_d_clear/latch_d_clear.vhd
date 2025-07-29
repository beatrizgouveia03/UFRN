ENTITY latch_d_clear IS
PORT (  d : IN BIT;	-- data input
	ena : IN BIT;	-- enable
	clrn : IN BIT;	-- clear
	q : OUT BIT);	-- data output
END latch_d_clear;

ARCHITECTURE behavior OF latch_d_clear IS
BEGIN
	PROCESS(d, ena, clrn)
	BEGIN
		IF(clrn = '0') THEN
			q <= '0';
		ELSIF(ena = '1') THEN
			q <= d;
		END IF;
	END PROCESS;
END behavior;
	
