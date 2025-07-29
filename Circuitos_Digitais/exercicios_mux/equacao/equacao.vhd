ENTITY equacao IS
PORT (  a :IN BIT_VECTOR(2 DOWNTO 0);	-- data input
	s : OUT BIT); 			-- data output
END equacao;

ARCHITECTURE arch OF equacao IS
BEGIN
	s <= (NOT a(2) AND NOT a(1) AND NOT a(0)) OR (a(2) AND NOT a(0)) OR (a(1) AND a(0));
END arch;
