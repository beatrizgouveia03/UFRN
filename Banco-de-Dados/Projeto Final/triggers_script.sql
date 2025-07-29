/*SCRIPT DE CRIAÇÃO DE TRIGGERS E FUNCTIONS*/

-- CRIAÇÃO DE EXEMPLAR:
CREATE OR REPLACE FUNCTION set_copy_status_available()
RETURNS trigger AS $set_copy_status_available$
BEGIN
    -- Atualizar status do exemplar para disponível
    NEW.statusCopy := 'AVAILABLE';

    RETURN NEW;
END;
$set_copy_status_available$ LANGUAGE plpgsql;

-- Setando o trigger para exemplar
CREATE TRIGGER trigger_set_copy_status_available
BEFORE INSERT ON copy
FOR EACH ROW EXECUTE PROCEDURE set_copy_status_available();

-- CRIAÇÃO DE RESERVA:
CREATE OR REPLACE FUNCTION handle_reservation_creation()
RETURNS trigger AS $handle_reservation_creation$
BEGIN
    -- Verificar se o usuário já tem uma reserva ativa
    IF EXISTS (
        SELECT 1
            FROM reservation
                WHERE idUser = NEW.idUser
                    AND statusReservation = 'ACTIVE'
    ) THEN
        RAISE EXCEPTION 'Usuário já possui uma reserva ativa.';
    END IF;

    -- Verificar se o usuário possui multa pendente
    IF EXISTS (
        SELECT 1
            FROM fine f
                JOIN loan l ON f.idLoan = l.idLoan
                    WHERE l.idUser = NEW.idUser
                        AND f.paymentStatusFine ILIKE 'PENDING'
    ) THEN
        RAISE EXCEPTION 'Usuário possui multa pendente.';
    END IF;

    -- Verificar se o usuário possui menos de 3 empréstimos ativos
    IF (
        SELECT COUNT(*)
            FROM loan
                WHERE idUser = NEW.idUser
                     AND statusLoan ILIKE 'BORROWED'
    ) >= 3 THEN
        RAISE EXCEPTION 'Usuário já possui 3 empréstimos ativos.';
    END IF;

    -- Verifica se o usuário possui empréstimo atrasado
    IF EXISTS (
        SELECT 1
            FROM loan 
                WHERE idUser = NEW.idUser
                    AND statusLoan ILIKE 'OVERDUE'
    ) THEN
        RAISE EXCEPTION 'Usuário possui empréstimo atrasado.';
    END IF;


    -- Atualizar status da reserva e do exemplar
    NEW.statusReservation := 'ACTIVE';
    NEW.dateReservation := CURRENT_DATE;

    UPDATE copy
        SET statusCopy = 'RESERVED'
            WHERE idCopy = NEW.idCopy;

    RETURN NEW;
END;
$handle_reservation_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de reserva
CREATE TRIGGER trigger_reservation_creation
BEFORE INSERT ON reservation
FOR EACH ROW EXECUTE PROCEDURE handle_reservation_creation();

-- ATUALIZAÇÃO DE RESERVA:
CREATE OR REPLACE FUNCTION handle_reservation_update()
RETURNS trigger AS $handle_reservation_update$
BEGIN
    
    IF(NEW.statusReservation ILIKE 'ACTIVE') THEN
        -- Criar empréstimo
        INSERT INTO Loan (idUser, idCopy, dateLoan, dueReturnDateLoan, statusLoan)
            VALUES (NEW.idUser, NEW.idCopy, CURRENT_DATE, CURRENT_DATE + INTERVAL '7 days', 'ACTIVE');
            
        -- Atualizar status da reserva
        NEW.statusReservation := 'FINISHED';
    END IF;

    RETURN NEW;
END;
$handle_reservation_update$ LANGUAGE plpgsql;

-- Setando o trigger para atualização de reserva
CREATE TRIGGER trigger_reservation_update
BEFORE UPDATE ON reservation
FOR EACH ROW EXECUTE PROCEDURE handle_reservation_update();

-- CRIAÇÃO DE EMPRÉSTIMO:
CREATE OR REPLACE FUNCTION handle_loan_creation()
RETURNS trigger AS $handle_loan_creation$
BEGIN
    -- Verificar se o usuário possui multa pendente
    IF EXISTS (
        SELECT 1
            FROM fine f
                JOIN loan l ON f.idLoan = l.idLoan
                    WHERE l.idUser = NEW.idUser
                        AND f.paymentStatusFine ILIKE 'PENDING'
    ) THEN
        RAISE EXCEPTION 'Usuário possui multa pendente.';
    END IF;

    -- Verificar se o usuário possui menos de 3 empréstimos ativos
    IF (
        SELECT COUNT(*)
            FROM loan
                WHERE idUser = NEW.idUser
                     AND statusLoan ILIKE 'BORROWED'
    ) >= 3 THEN
        RAISE EXCEPTION 'Usuário já possui 3 empréstimos ativos.';
    END IF;

    -- Verifica se o usuário possui empréstimo atrasado
    IF EXISTS (
        SELECT 1
            FROM loan 
                WHERE idUser = NEW.idUser
                    AND statusLoan ILIKE 'OVERDUE'
    ) THEN
        RAISE EXCEPTION 'Usuário possui empréstimo atrasado.';
    END IF;

    -- Verificar se o exemplar está disponível ou reservado
    IF NOT EXISTS (
        SELECT 1
            FROM copy c
                WHERE c.idCopy = NEW.idCopy
                    AND c.statusCopy ILIKE 'AVAILABLE'
                        OR (c.statusCopy ILIKE 'RESERVED' 
                            AND NEW.idUser = (SELECT idUser 
                                FROM reservation r WHERE r.idCopy = NEW.idCopy))
    ) THEN
        RAISE EXCEPTION 'Exemplar não disponível ou reservado para este usuário.';
    END IF;

    -- Atualizar status do empréstimo e do exemplar
    NEW.dateLoan := CURRENT_DATE;
    NEW.dueReturnDateLoan := CURRENT_DATE + INTERVAL '7 days';
    NEW.statusLoan := 'BORROWED';

    UPDATE copy
    SET statusCopy = 'BORROWED'
    WHERE idCopy = NEW.idCopy;

    RETURN NEW;
END;
$handle_loan_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de empréstimo
CREATE TRIGGER trigger_loan_creation
BEFORE INSERT ON loan
FOR EACH ROW EXECUTE PROCEDURE handle_loan_creation();

-- ATUALIZAÇÃO DE EMPRÉSTIMO:
CREATE OR REPLACE FUNCTION handle_loan_update()
RETURNS trigger AS $handle_loan_update$
BEGIN

    -- Verificar status do empréstimo
    IF NEW.statusLoan ILIKE 'BORROWED' THEN
        -- Atualizar status do empréstimo
        NEW.statusLoan := 'RETURNED';

        -- Atualizar data de retorno
        NEW.dateReturn := CURRENT_DATE;

        -- Atualizar status do exemplar
        UPDATE copy
            SET statusCopy = 'AVAILABLE'
                WHERE idCopy = NEW.idCopy;
    ELSIF NEW.statusLoan ILIKE 'OVERDUE' AND NEW.actualReturnDateLoan IS NOT NULL THEN
        -- Atualizar status do empréstimo
        NEW.statusLoan := 'RETURNED';
        
        -- Criar multa
        INSERT INTO Fine (idLoan, amountFine, paymentStatusFine)
       		VALUES (NEW.idLoan, (CURRENT_DATE - NEW.dueReturnDateLoan), 'PENDING');     

        -- Atualizar status do exemplar
        UPDATE copy
            SET statusCopy = 'AVAILABLE'
                WHERE idCopy = NEW.idCopy;
    END IF;

    RETURN NEW;
END;
$handle_loan_update$ LANGUAGE plpgsql;

-- Setando o trigger para atualização de empréstimo
CREATE TRIGGER trigger_loan_update
BEFORE UPDATE ON loan
FOR EACH ROW EXECUTE PROCEDURE handle_loan_update();

-- CRIAÇÃO DE MULTA:
CREATE OR REPLACE FUNCTION handle_fine_creation()
RETURNS trigger AS $handle_fine_creation$
DECLARE
	fine_rate NUMERIC;
    book_level VARCHAR(10);
BEGIN

    -- Busca o nível de busca do livro
    SELECT searchLevel
        INTO book_level
            FROM Book
                JOIN Copy ON Book.idBook = Copy.idBook
                    JOIN Loan ON Copy.idCopy = Loan.idCopy
                        WHERE Loan.idLoan = NEW.idLoan;

    -- Define a taxa de multa com base no nível de busca
    CASE book_level
        WHEN 'LOW' THEN fine_rate := 0.5;
        WHEN 'MEDIUM' THEN fine_rate := 1.0;
        WHEN 'HIGH' THEN fine_rate := 1.5;
        ELSE
            RAISE EXCEPTION 'Nível de busca desconhecido: %', book_level;
    END CASE;

    -- Calcula o valor da multa
    NEW.amountFine := OLD.amountFine * fine_rate;

    -- Atualizar o status da multa
    NEW.paymentStatusFine := 'PENDING';

    RETURN NEW;
END;
$handle_fine_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de multa
CREATE TRIGGER trigger_fine_creation
BEFORE INSERT ON fine
FOR EACH ROW EXECUTE PROCEDURE handle_fine_creation();

-- CRIAÇÃO DE PESSOA:
CREATE OR REPLACE FUNCTION handle_person_creation()
RETURNS trigger AS $handle_person_creation$
BEGIN
    -- Verificar se a pessoa já existe no sistema
    IF EXISTS (
        SELECT 1 
            FROM person 
                WHERE person.namePerson = NEW.namePerson
					AND person.dateOfBirthPerson = NEW.dateOfBirthPerson
    ) THEN
        RAISE EXCEPTION 'Pessoa já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_person_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de pessoa
CREATE TRIGGER trigger_person_creation
BEFORE INSERT ON person
FOR EACH ROW EXECUTE PROCEDURE handle_person_creation();

-- CRIAÇÃO DE USUÁRIO:
CREATE OR REPLACE FUNCTION handle_user_creation()
RETURNS trigger AS $handle_user_creation$
BEGIN
    -- Verificar se o usuário já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM SUser 
                WHERE SUser.idPerson = NEW.idPerson
    ) THEN
        RAISE EXCEPTION 'Usuário já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_user_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de usuário
CREATE TRIGGER trigger_user_creation
BEFORE INSERT ON SUser
FOR EACH ROW EXECUTE PROCEDURE handle_user_creation();

-- CRIAÇÃO DE FUNCIONÁRIO:
CREATE OR REPLACE FUNCTION handle_staff_creation()
RETURNS trigger AS $handle_staff_creation$
BEGIN
    -- Verificar se o funcionário já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM Staff
                WHERE Staff.idPerson = NEW.idPerson
    ) THEN
        RAISE EXCEPTION 'Funcionário já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_staff_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de funcionário
CREATE TRIGGER trigger_staff_creation
BEFORE INSERT ON Staff
FOR EACH ROW EXECUTE PROCEDURE handle_staff_creation();

-- CRIAÇÃO DE LIVRO:
CREATE OR REPLACE FUNCTION handle_book_creation()
RETURNS trigger AS $handle_book_creation$
BEGIN
    -- Verificar se o livro já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM Book
                WHERE Book.isbnBook = NEW.isbnBook
    ) THEN
        RAISE EXCEPTION 'Livro já existe no sistema';
    END IF;

    RETURN NEW;
END;
$handle_book_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de livro
CREATE TRIGGER trigger_book_creation
BEFORE INSERT ON Book
FOR EACH ROW EXECUTE PROCEDURE handle_book_creation();

-- CRIAÇÃO DE GÊNERO:
CREATE OR REPLACE FUNCTION handle_genre_creation()
RETURNS trigger AS $handle_genre_creation$
BEGIN
    -- Verificar se o gênero já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM Genre
                WHERE Genre.nameGenre = NEW.nameGenre
    ) THEN
        RAISE EXCEPTION 'Gênero já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_genre_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de gênero
CREATE TRIGGER trigger_genre_creation
BEFORE INSERT ON Genre
FOR EACH ROW EXECUTE PROCEDURE handle_genre_creation();

-- CRIAÇÃO DE AUTOR:
CREATE OR REPLACE FUNCTION handle_author_creation()
RETURNS trigger AS $handle_author_creation$
BEGIN
    -- Verificar se o autor já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM Author
                WHERE Author.nameAuthor = NEW.nameAuthor
                    AND Author.dateOfBirthAuthor = NEW.dateOfBirthAuthor
                        AND Author.nationalityAuthor = NEW.nationalityAuthor
    ) THEN
        RAISE EXCEPTION 'Autor já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_author_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de autor
CREATE TRIGGER trigger_author_creation
BEFORE INSERT ON Author
FOR EACH ROW EXECUTE PROCEDURE handle_author_creation();

-- CRIAÇÃO DE EDITORA
CREATE OR REPLACE FUNCTION handle_publisher_creation()
RETURNS trigger AS $handle_publisher_creation$
BEGIN
    -- Verificar se a editora já existe no sistema
    IF EXISTS (
    SELECT 1
        FROM Publisher
            WHERE Publisher.cnpjPublisher = NEW.cnpjPublisher
    ) THEN
        RAISE EXCEPTION 'Editora já existe no sistema';
    END IF;

	RETURN NEW;
END;
$handle_publisher_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de editora
CREATE TRIGGER trigger_publisher_creation
BEFORE INSERT ON Publisher
FOR EACH ROW EXECUTE PROCEDURE handle_publisher_creation();

-- CRIAÇÃO DE ENDEREÇOS
CREATE OR REPLACE FUNCTION handle_address_creation()
RETURNS trigger AS $handle_address_creation$
BEGIN
    -- Verificar se o endereço já existe no sistema
    IF EXISTS (
        SELECT 1
        FROM Address
        WHERE Address.postalCodeAddress = NEW.postalCodeAddress
    ) THEN
        RAISE EXCEPTION 'Endereço já existe no sistema';
    END IF;
    
    RETURN NEW;
END;
$handle_address_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de endereço
CREATE TRIGGER trigger_address_creation
BEFORE INSERT ON Address
FOR EACH ROW EXECUTE PROCEDURE handle_address_creation();

-- CRIAÇÃO DE TELEFONES
CREATE OR REPLACE FUNCTION handle_phone_creation()
RETURNS trigger AS $handle_phone_creation$
BEGIN
    -- Verificar se o telefone já existe no sistema
    IF EXISTS (
        SELECT 1
            FROM Phone
                WHERE Phone.phoneNumber = NEW.phoneNumber
                    AND Phone.dddPhone = NEW.dddPhone
    ) THEN
        RAISE EXCEPTION 'Telefone já existe no sistema';
    END IF;

    RETURN NEW;
END;
$handle_phone_creation$ LANGUAGE plpgsql;

-- Setando o trigger para criação de telefone
CREATE TRIGGER trigger_phone_creation
BEFORE INSERT ON Phone
FOR EACH ROW EXECUTE PROCEDURE handle_phone_creation();

-- FUNÇÃO DE ATUALIZAÇÃO DE EMPRÉSTIMOS ATRASADOS
CREATE OR REPLACE FUNCTION update_overdue_loans()
RETURNS void AS $update_overdue_loans$
BEGIN
    -- Atualizar todos os empréstimos que estão ativos e cuja data de retorno prevista foi ultrapassada
    UPDATE Loan
        SET statusLoan = 'OVERDUE'
            WHERE statusLoan ILIKE 'BORROWED'
                AND dueReturnDateLoan < CURRENT_DATE;
END;
$update_overdue_loans$ LANGUAGE plpgsql;

-- FUNÇÃO DE ATUALIZAÇÃO DE RESERVAS FINALIZADAS
CREATE OR REPLACE FUNCTION update_finished_reservations()
RETURNS void AS $update_finished_reservations$
BEGIN
    -- Atualizar todas as reservas que estão ativas e cuja data da reserva foi a mais de 3 dias
    UPDATE Reservation
        SET statusReservation = 'FINISHED'
            WHERE statusReservation ILIKE 'ACTIVE'
                AND dateReservation < CURRENT_DATE - INTERVAL '3 days';
END;
$update_finished_reservations$ LANGUAGE plpgsql;