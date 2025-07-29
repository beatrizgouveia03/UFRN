ENTITY half_adder IS
PORT ( a, b : IN BIT;    -- data inputs
	  s : OUT BIT;   -- data output
	cout : OUT BIT); -- carry out
END half_adder;

ARCHITECTURE structural OF half_adder IS
BEGIN
	s <= a XOR b;
	cout <= a AND b;
END structural;