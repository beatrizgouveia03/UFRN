ENTITY latch_d IS 
PORT (  d : IN BIT;	-- data input
	ena : IN BIT;	-- enable
	q : OUT BIT);	-- data output
END latch_d;

ARCHITECTURE behavior OF latch_d IS
BEGIN
	PROCESS(d, ena)
	BEGIN
		IF (ena = '1') THEN
			q <= d;
		END IF;
	END PROCESS;
END behavior;
