ENTITY half_subtractor IS
PORT (  a, b : IN BIT;   -- data inputs
	s : OUT BIT;	 -- data output
	cout : OUT BIT); -- carry out
END half_subtractor;

ARCHITECTURE structural OF half_subtractor IS
BEGIN
	s <= a XOR b;
	cout <= NOT a AND b;
END structural;
