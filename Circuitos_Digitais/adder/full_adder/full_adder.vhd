ENTITY full_adder IS
PORT (  a, b : IN BIT;   -- data input
	cin: IN BIT;	 -- carry in
	s : OUT BIT;	 -- data output
	cout : OUT BIT); -- carry out
END full_adder;

ARCHITECTURE structural OF full_adder IS
BEGIN
	s <= a XOR b XOR cin;
	cout <= (a AND cin) OR (b AND cin) OR (a AND b);
END structural;