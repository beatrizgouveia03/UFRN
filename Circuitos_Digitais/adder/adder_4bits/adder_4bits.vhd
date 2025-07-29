ENTITY adder_4bits IS
PORT (  a0, a1, a2, a3 : IN BIT;       -- first number inputs
	b0, b1, b2, b3 : IN BIT;       -- second number inputs
	s0, s1, s2, s3, s4 : OUT BIT); -- data outputs
END adder_4bits;

ARCHITECTURE structural OF adder_4bits IS

COMPONENT half_adder
PORT ( a, b : IN BIT;    -- data inputs
	  s : OUT BIT;   -- data output
	cout : OUT BIT); -- carry out
END COMPONENT;

COMPONENT full_adder
PORT (  a, b : IN BIT;   -- data input
	cin: IN BIT;	 -- carry in
	s : OUT BIT;	 -- data output
	cout : OUT BIT); -- carry out
END COMPONENT;

SIGNAL c0, c1, c2, c3 : BIT;

BEGIN
	u0 : half_adder PORT MAP ( a0, b0, s0, c0);
	u1 : full_adder PORT MAP ( a1, b1, c0, s1, c1);
	u2 : full_adder PORT MAP ( a2, b2, c1, s2, c2);
	u3 : full_adder PORT MAP ( a3, b3, c2, s3, c3);
	s4 <= c3;
END structural;