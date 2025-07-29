ENTITY full_subtractor IS 
PORT (  a, b : IN BIT;	 -- data inputs
	cin : IN BIT;	 -- carry in
	s : OUT BIT;	 -- data output
	cout : OUT BIT); -- carry out  
END full_subtractor;

ARCHITECTURE structural OF full_subtractor IS
BEGIN
	s <= a XOR b XOR cin;
	cout <= (NOT A and b) OR (NOT a AND cin) OR (b AND cin); 	
END structural;