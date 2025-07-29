ENTITY demux_1x2 IS
PORT (  a : IN BIT;			 -- data inputs
	sel : IN BIT;			 -- selector
	s : OUT BIT_VECTOR (1 DOWNTO 0));-- data output
END demux_1x2;

ARCHITECTURE structural OF demux_1x2 IS
BEGIN
	PROCESS(a, sel)
	BEGIN
		s(0) <= a AND NOT sel;
		s(1) <= a AND sel;
	END PROCESS;
END structural;
