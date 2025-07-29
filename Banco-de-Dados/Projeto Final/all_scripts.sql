/* SCRIPTS DE CRIAÇÃO DAS TABELAS */

-- Criando a tabela Person
CREATE TABLE Person (
  idPerson SERIAL NOT NULL,
  namePerson VARCHAR(50),
  emailPerson VARCHAR(50),
  dateOfBirthPerson DATE,
  PRIMARY KEY (idPerson)
);

-- Criando a tabela Genre
CREATE TABLE Genre (
  idGenre SERIAL NOT NULL,
  nameGenre VARCHAR(40),
  descriptionGenre TEXT,
  PRIMARY KEY (idGenre)
);

-- Criando a tabela Address
CREATE TABLE Address (
  idAddress SERIAL NOT NULL,
  streetAddress VARCHAR(100),
  cityAddress VARCHAR(50),
  postalCodeAddress VARCHAR(20),
  PRIMARY KEY (idAddress)
);

-- Criando a tabela Author
CREATE TABLE Author (
  idAuthor SERIAL NOT NULL,
  nameAuthor VARCHAR(50),
  nationalityAuthor VARCHAR(30),
  biographyAuthor TEXT,
  dateOfBirthAuthor DATE,
  PRIMARY KEY (idAuthor)
);

-- Criando a tabela Book
CREATE TABLE Book (
  idBook SERIAL NOT NULL,
  titleBook VARCHAR(100),
  isbnBook VARCHAR(20) UNIQUE,
  publicationYearBook SMALLINT,
  descriptionBook TEXT,
  searchLevel VARCHAR(7),
  PRIMARY KEY (idBook)
);

-- Criando a tabela SUser
CREATE TABLE SUser (
  idUser SERIAL NOT NULL,
  idPerson INT NOT NULL,
  registrationDateUser DATE,
  PRIMARY KEY (idUser),
  FOREIGN KEY (idPerson) REFERENCES Person(idPerson) ON DELETE CASCADE
);

-- Criando a tabela Staff
CREATE TABLE Staff (
  idStaff SERIAL NOT NULL,
  idPerson INT NOT NULL,
  roleTitleStaff VARCHAR(50),
  employmentDateStaff DATE,
  PRIMARY KEY (idStaff),
  FOREIGN KEY (idPerson) REFERENCES Person(idPerson) ON DELETE CASCADE
);

-- Criando a tabela Phone
-- Possíveis tipos de telefone : Móvel('MOBILE'), Fixo('FIXED'), Comercial('COMMERCIAL')
CREATE TABLE Phone (
  idPhone SERIAL NOT NULL,
  idPerson INT NOT NULL,
  dddPhone VARCHAR(2),
  numberPhone VARCHAR(9),
  typePhone VARCHAR(10) NOT NULL CHECK(typePhone IN ('MOBILE', 'FIXED', 'COMMERCIAL')),
  PRIMARY KEY (idPhone),
  FOREIGN KEY (idPerson) REFERENCES Person(idPerson) ON DELETE CASCADE
);

-- Criando a tabela Publisher
CREATE TABLE Publisher (
  idPublisher SERIAL NOT NULL,
  idAddress INT NOT NULL,
  namePublisher VARCHAR(50),
  contactEmailPublisher VARCHAR(50),
  cnpjPublisher VARCHAR(14),
  PRIMARY KEY (idPublisher),
  FOREIGN KEY (idAddress) REFERENCES Address(idAddress) ON DELETE CASCADE
);

-- Criando a tabela Book-Genre
CREATE TABLE Book_has_Genre (
  idBook_has_Genre SERIAL NOT NULL,
  idBook INT NOT NULL,
  idGenre INT NOT NULL,
  PRIMARY KEY (idBook_has_Genre),
  FOREIGN KEY (idBook) REFERENCES Book(idBook) ON DELETE CASCADE,
  FOREIGN KEY (idGenre) REFERENCES Genre(idGenre) ON DELETE CASCADE
);

-- Criando a tabela Book-Author
CREATE TABLE Book_has_Author (
  idBook_has_Author SERIAL NOT NULL,
  idBook INT NOT NULL,
  idAuthor INT NOT NULL,
  PRIMARY KEY (idBook_has_Author),
  FOREIGN KEY (idBook) REFERENCES Book(idBook) ON DELETE CASCADE,
  FOREIGN KEY (idAuthor) REFERENCES Author(idAuthor) ON DELETE CASCADE
);

-- Criando a tabela Book-Publisher
CREATE TABLE Book_has_Publisher (
  idBook_has_Publisher SERIAL NOT NULL,
  idBook INT NOT NULL,
  idPublisher INT NOT NULL,
  PRIMARY KEY (idBook_has_Publisher),
  FOREIGN KEY (idBook) REFERENCES Book(idBook) ON DELETE CASCADE,
  FOREIGN KEY (idPublisher) REFERENCES Publisher(idPublisher) ON DELETE CASCADE
);

-- Criando a tabela Person-Address
CREATE TABLE Person_has_Address (
  idPerson_has_Address SERIAL NOT NULL,
  idPerson INT NOT NULL,
  idAddress INT NOT NULL,
  PRIMARY KEY (idPerson_has_Address),
  FOREIGN KEY (idPerson) REFERENCES Person(idPerson) ON DELETE CASCADE,
  FOREIGN KEY (idAddress) REFERENCES Address(idAddress) ON DELETE CASCADE
);

-- Criando a tabela Copy
-- Possíveis status do exemplar: Emprestado('BORROWED'), Reservado('RESERVED'), Danificado('DAMAGED') ou Disponível('AVAILABLE')
CREATE TABLE Copy (
  idCopy SERIAL NOT NULL,
  idBook INTEGER NOT NULL,
  statusCopy VARCHAR(10) CHECK(statusCopy IN ('BORROWED', 'RESERVED', 'DAMAGED', 'AVAILABLE' )),
  PRIMARY KEY (idCopy),
  FOREIGN KEY (idBook) REFERENCES Book(idBook) ON DELETE CASCADE
);

-- Criando a tabela Reservation
-- Possíveis status da reserva: Ativa('ACTIVE') ou Finalizada('FINISHED')
CREATE TABLE Reservation (
  idReservation SERIAL NOT NULL,
  idUser INTEGER NOT NULL,
  idCopy INTEGER NOT NULL,
  dateReservation DATE,
  statusReservation VARCHAR(10) CHECK(statusReservation IN ('ACTIVE', 'FINISHED')),
  PRIMARY KEY (idReservation),
  FOREIGN KEY (idUser) REFERENCES SUser(idUser) ON DELETE CASCADE,
  FOREIGN KEY (idCopy) REFERENCES Copy(idCopy) ON DELETE CASCADE
);

-- Criando a tabela Loan
-- Possíveis status do empréstimo: Emprestado('BORROWED'), Devolvido('RETURNED'), Atrasado('OVERDUE')
CREATE TABLE Loan (
  idLoan SERIAL NOT NULL,
  idCopy INT NOT NULL,
  idUser INT NOT NULL,
  dateLoan DATE,
  dueReturnDateLoan DATE,
  actualReturnDateLoan DATE,
  statusLoan VARCHAR(10) CHECK(statusLoan IN ('BORROWED', 'RETURNED', 'OVERDUE')),
  PRIMARY KEY (idLoan),
  FOREIGN KEY (idCopy) REFERENCES Copy(idCopy) ON DELETE CASCADE,
  FOREIGN KEY (idUser) REFERENCES SUser(idUser) ON DELETE CASCADE
);

-- Criando a tabela Fine
-- Possíveis status do multa: Pendente('PENDING'), Paga('PAID')
CREATE TABLE Fine (
  idFine SERIAL NOT NULL,
  idLoan INT NOT NULL,
  amountFine DECIMAL(10, 2),
  paymentStatusFine VARCHAR(10) CHECK(paymentStatusFine IN ('PENDING', 'PAID')),
  PRIMARY KEY (idFine),
  FOREIGN KEY (idLoan) REFERENCES Loan(idLoan) ON DELETE CASCADE
);

/*SCRIPT DE INSERÇÃO DE DADOS*/

-- Populando a tabela Person
INSERT INTO Person (namePerson, emailPerson, dateOfBirthPerson) VALUES
('Beatriz Souza', 'beatriz.souza@example.com', '1990-05-15'),
('Carlos Silva', 'carlos.silva@example.com', '1985-10-20'),
('Ana Clara', 'ana.clara@example.com', '1995-07-01'),
('José Santos', 'jose.santos@example.com', '1988-12-12'),
('Mariana Oliveira', 'mariana.oliveira@example.com', '1992-09-09'),
('Lucas Pereira', 'lucas.pereira@example.com', '1993-03-05'),
('Fernanda Lima', 'fernanda.lima@example.com', '1989-11-23'),
('Gabriel Almeida', 'gabriel.almeida@example.com', '2000-04-18'),
('Julia Costa', 'julia.costa@example.com', '1998-06-25'),
('Ricardo Gomes', 'ricardo.gomes@example.com', '1987-01-31');

-- Populando a tabela Address
INSERT INTO Address (streetAddress, cityAddress, postalCodeAddress) VALUES
('Rua A, 123', 'São Paulo', '01001-000'),
('Avenida B, 456', 'Rio de Janeiro', '20010-000'),
('Praça C, 789', 'Belo Horizonte', '30100-000'),
('Rua D, 321', 'Porto Alegre', '90010-000'),
('Avenida E, 654', 'Recife', '50010-000'),
('Praça F, 987', 'Fortaleza', '60010-000'),
('Rua G, 111', 'Salvador', '40010-000'),
('Avenida H, 222', 'Curitiba', '80010-000'),
('Praça I, 333', 'Manaus', '69010-000'),
('Rua J, 444', 'Brasília', '70010-000');

-- Populando a tabela SUser
INSERT INTO SUser (idPerson, registrationDateUser) VALUES
(1, '2024-01-01'),
(2, '2024-02-01'),
(3, '2024-03-01'),
(4, '2024-04-01'),
(5, '2024-05-01'),
(6, '2024-06-01'),
(7, '2024-07-01'),
(8, '2024-08-01'),
(9, '2024-09-01'),
(10, '2024-10-01');

-- Populando a tabela Staff
INSERT INTO Staff (idPerson, roleTitleStaff, employmentDateStaff) VALUES
(1, 'Bibliotecário', '2023-01-01'),
(2, 'Assistente', '2023-02-01'),
(3, 'Gerente', '2023-03-01'),
(4, 'Recepcionista', '2023-04-01'),
(5, 'Auxiliar', '2023-05-01'),
(6, 'Técnico', '2023-06-01'),
(7, 'Consultor', '2023-07-01'),
(8, 'Analista', '2023-08-01'),
(9, 'Estagiário', '2023-09-01'),
(10, 'Supervisor', '2023-10-01');

-- Populando a tabela Book
INSERT INTO Book (titleBook, isbnBook, publicationYearBook, descriptionBook, searchLevel) VALUES
('O Senhor dos Anéis', '978-3-16-148410-0', 1954, 'Fantasia épica', 'HIGH'),
('Dom Casmurro', '978-85-359-0277-3', 1899, 'Romance brasileiro', 'MEDIUM'),
('1984', '978-0-452-28423-4', 1949, 'Distopia', 'HIGH'),
('A Culpa é das Estrelas', '978-0-525-47881-2', 2012, 'Romance', 'MEDIUM'),
('Harry Potter e a Pedra Filosofal', '978-0-7475-3269-9', 1997, 'Fantasia', 'HIGH'),
('O Alquimista', '978-0-06-112241-5', 1988, 'Ficção espiritual', 'LOW'),
('A Revolução dos Bichos', '978-0-452-28425-8', 1945, 'Sátira', 'MEDIUM'),
('Orgulho e Preconceito', '978-0-19-280238-5', 1813, 'Romance', 'MEDIUM'),
('O Pequeno Príncipe', '978-2-07-061275-8', 1943, 'Fábula', 'LOW'),
('Cem Anos de Solidão', '978-0-06-088328-7', 1967, 'Realismo mágico', 'HIGH');

-- Populando a tabela Genre
INSERT INTO Genre (nameGenre, descriptionGenre) VALUES
('Fantasia', 'Gênero literário que explora mundos imaginários e seres sobrenaturais.'),
('Romance', 'Gênero literário focado em relações amorosas e emocionais.'),
('Distopia', 'Gênero que apresenta sociedades futuras e opressivas.'),
('Ficção', 'Gênero literário baseado em narrativas não reais.'),
('Fábula', 'Gênero literário com lições morais, muitas vezes usando animais como personagens.'),
('Realismo mágico', 'Gênero literário que mistura o real e o fantástico de forma natural.'),
('Aventura', 'Gênero que envolve aventuras emocionantes e viagens.'),
('Mistério', 'Gênero que envolve investigações e enigmas a serem desvendados.'),
('Histórico', 'Gênero que se baseia em eventos históricos reais ou fictícios.'),
('Terror', 'Gênero focado em provocar medo e tensão nos leitores.');

-- Populando a tabela Author
INSERT INTO Author (nameAuthor, dateOfBirthAuthor, nationalityAuthor, biographyAuthor) VALUES
('J.R.R. Tolkien', '1892-01-03', 'Britânico', 'Escritor e professor, famoso por "O Senhor dos Anéis".'),
('Machado de Assis', '1839-06-21', 'Brasileiro', 'Um dos maiores escritores brasileiros, autor de "Dom Casmurro".'),
('George Orwell', '1903-06-25', 'Britânico', 'Famoso por suas obras "1984" e "A Revolução dos Bichos".'),
('John Green', '1977-08-24', 'Americano', 'Escritor de romances, incluindo "A Culpa é das Estrelas".'),
('J.K. Rowling', '1965-07-31', 'Britânica', 'Autora da série "Harry Potter".'),
('Paulo Coelho', '1947-08-24', 'Brasileiro', 'Autor de "O Alquimista" e outros best-sellers.'),
('George R.R. Martin', '1948-09-20', 'Americano', 'Autor da série "As Crônicas de Gelo e Fogo", inspiração para "Game of Thrones".'),
('Jane Austen', '1775-12-16', 'Britânica', 'Autora de "Orgulho e Preconceito" e outras obras que criticam a sociedade de sua época.'),
('Antoine de Saint-Exupéry', '1900-06-29', 'Francês', 'Escritor de "O Pequeno Príncipe", um dos livros mais traduzidos do mundo.'),
('Gabriel García Márquez', '1927-03-06', 'Colombiano', 'Autor de "Cem Anos de Solidão" e um dos maiores expoentes do realismo mágico.');

-- Populando a tabela Publisher
INSERT INTO Publisher (idAddress, cnpjPublisher, namePublisher, contactEmailPublisher) VALUES
(1, '12345678000195', 'Editora XYZ', 'contato@editoraxyz.com'),
(2, '98765432000123', 'Editora ABC', 'editor@editorabc.com'),
(3, '11223344000178', 'Livraria Brasil', 'livraria@livrariabrasil.com'),
(4, '55667788000156', 'Editora Nacional', 'atendimento@editoranacional.com'),
(5, '66778899000100', 'Livros do Mundo', 'contato@livrosdomundo.com'),
(6, '99887766000111', 'Editora Universal', 'editorau@universal.com'),
(7, '12312312300122', 'Livraria do Porto', 'contato@livrariadoporto.com'),
(8, '44332211000134', 'Editora Moderna', 'moderna@editoramoderna.com'),
(9, '55443322000145', 'Cultura Livros', 'livros@culturalivros.com'),
(10, '66554433000156', 'Livraria e Editora', 'livrariaeditora@editoralivros.com');

-- Populando a tabela Copy (Exemplar)
INSERT INTO Copy (idBook, statusCopy) VALUES
(1, 'RESERVED'),
(1, 'RESERVED'),
(1, 'BORROWED'),
(1, 'RESERVED'),
(2, 'RESERVED'),
(2, 'DAMAGED'),
(2, 'BORROWED'),
(2, 'RESERVED'),
(3, 'RESERVED'),
(3, 'BORROWED'),
(3, 'AVAILABLE'),
(4, 'AVAILABLE'),
(4, 'DAMAGED'),
(5, 'AVAILABLE'),
(5, 'AVAILABLE'),
(5, 'AVAILABLE'),
(6, 'AVAILABLE'),
(6, 'AVAILABLE'),
(7, 'AVAILABLE'),
(7, 'DAMAGED'),
(8, 'AVAILABLE'),
(8, 'AVAILABLE'),
(9, 'AVAILABLE'),
(9, 'AVAILABLE'),
(10, 'DAMAGED');

-- Populando a tabela Reservation (Reserva)
INSERT INTO Reservation (idUser, idCopy, dateReservation, statusReservation) VALUES
(1, 1, '2025-01-10', 'ACTIVE'),
(2, 2, '2024-02-10', 'ACTIVE'),
(3, 3, '2024-03-20', 'FINISHED'),
(4, 4, '2024-04-25', 'ACTIVE'),
(5, 5, '2024-05-30', 'ACTIVE'),
(6, 6, '2024-06-05', 'FINISHED'),
(7, 7, '2024-07-15', 'FINISHED'),
(8, 8, '2025-01-09', 'ACTIVE'),
(9, 9, '2024-09-25', 'ACTIVE'),
(10, 10, '2024-10-05', 'FINISHED');

-- Populando a tabela Loan (Empréstimo)
INSERT INTO Loan (idUser, idCopy, dateLoan, dueReturnDateLoan, actualReturnDateLoan, statusLoan) VALUES
(1, 1, '2024-10-05', '2024-10-12', NULL, 'BORROWED'),
(2, 2, '2024-02-05', '2024-02-12', NULL, 'BORROWED'),
(3, 3, '2024-06-05', '2024-06-12', '2024-06-12', 'RETURNED'),
(4, 4, '2024-04-20', '2024-04-27', NULL, 'BORROWED'),
(5, 5, '2024-03-20', '2024-03-27', NULL, 'BORROWED'),
(6, 6, '2024-06-01', '2024-06-08', '2024-06-06', 'RETURNED'),
(7, 7, '2024-07-05', '2024-07-12', '2024-07-15', 'OVERDUE'),
(8, 8, '2024-08-01', '2024-08-08', NULL, 'BORROWED'),
(9, 9, '2025-01-10', '2025-01-17', NULL, 'BORROWED'),
(10, 10, '2024-10-01', '2024-10-08', NULL, 'OVERDUE');

-- Populando a tabela Fine (Multas)
INSERT INTO Fine (idLoan,amountFine, paymentStatusFine) VALUES
(7, 3.00, 'PENDING');

-- Populando a tabela book_has_author (relacionamento entre Livro e Autor)
INSERT INTO book_has_author (idBook, idAuthor) VALUES
(1, 1),  -- "O Senhor dos Anéis" por J.R.R. Tolkien
(2, 2),  -- "Dom Casmurro" por Machado de Assis
(3, 3),  -- "1984" por George Orwell
(4, 4),  -- "A Culpa é das Estrelas" por John Green
(5, 5),  -- "Harry Potter" por J.K. Rowling
(6, 6),  -- "O Alquimista" por Paulo Coelho
(7, 7),  -- "As Crônicas de Gelo e Fogo" por George R.R. Martin
(8, 8),  -- "Orgulho e Preconceito" por Jane Austen
(9, 9),  -- "O Pequeno Príncipe" por Antoine de Saint-Exupéry
(10, 10); -- "Cem Anos de Solidão" por Gabriel García Márquez

-- Populando a tabela book_has_genre (relacionamento entre Livro e Gênero)
INSERT INTO book_has_genre (idBook, idGenre) VALUES
(1, 1),  -- "O Senhor dos Anéis" é de gênero Fantasia
(2, 2),  -- "Dom Casmurro" é de gênero Romance
(3, 3),  -- "1984" é de gênero Distopia
(4, 4),  -- "A Culpa é das Estrelas" é de gênero Romance
(5, 1),  -- "Harry Potter" é de gênero Fantasia
(6, 2),  -- "O Alquimista" é de gênero Romance
(7, 1),  -- "As Crônicas de Gelo e Fogo" é de gênero Fantasia
(8, 2),  -- "Orgulho e Preconceito" é de gênero Romance
(9, 1),  -- "O Pequeno Príncipe" é de gênero Fantasia
(10, 3); -- "Cem Anos de Solidão" é de gênero Realismo Mágico

-- Populando a tabela book_has_publisher (relacionamento entre Livro e Editora)
INSERT INTO book_has_publisher (idBook, idPublisher) VALUES
(1, 1),  -- "O Senhor dos Anéis" publicado pela Editora XYZ
(2, 2),  -- "Dom Casmurro" publicado pela Editora ABC
(3, 3),  -- "1984" publicado pela Livraria Brasil
(4, 4),  -- "A Culpa é das Estrelas" publicado pela Editora Nacional
(5, 5),  -- "Harry Potter" publicado pela Livros do Mundo
(6, 6),  -- "O Alquimista" publicado pela Editora Universal
(7, 7),  -- "As Crônicas de Gelo e Fogo" publicado pela Livraria do Porto
(8, 8),  -- "Orgulho e Preconceito" publicado pela Editora Moderna
(9, 9),  -- "O Pequeno Príncipe" publicado pela Cultura Livros
(10, 10); -- "Cem Anos de Solidão" publicado pela Livraria e Editora

-- Populando a tabela person_has_address (relacionamento entre Pessoa e Endereço)
INSERT INTO person_has_address (idPerson, idAddress) VALUES
(1, 1),  -- Pessoa 1 (João da Silva) tem o endereço 1
(2, 2),  -- Pessoa 2 (Maria Oliveira) tem o endereço 2
(3, 3),  -- Pessoa 3 (Carlos Pereira) tem o endereço 3
(4, 4),  -- Pessoa 4 (Ana Souza) tem o endereço 4
(5, 5),  -- Pessoa 5 (Roberta Costa) tem o endereço 5
(6, 6),  -- Pessoa 6 (Fernando Almeida) tem o endereço 6
(7, 7),  -- Pessoa 7 (Luciana Dias) tem o endereço 7
(8, 8),  -- Pessoa 8 (Eduardo Lima) tem o endereço 8
(9, 9),  -- Pessoa 9 (Felipe Santos) tem o endereço 9
(10, 10); -- Pessoa 10 (Juliana Barbosa) tem o endereço 10

-- Populando a tabela phone (relacionamento entre Pessoa e Telefone)
INSERT INTO phone (idPerson, dddPhone, numberPhone, typePhone) VALUES
(1, '11', '987654321', 'MOBILE'),   -- João da Silva, telefone móvel
(1, '11', '345678901', 'FIXED'),    -- João da Silva, telefone fixo
(2, '21', '987123456', 'MOBILE'),   -- Maria Oliveira, telefone móvel
(3, '31', '987234567', 'MOBILE'),   -- Carlos Pereira, telefone móvel
(3, '31', '234567890', 'COMMERCIAL'), -- Carlos Pereira, telefone comercial
(4, '41', '987345678', 'MOBILE'),   -- Ana Souza, telefone móvel
(5, '51', '987456789', 'MOBILE'),   -- Roberta Costa, telefone móvel
(5, '51', '234567891', 'COMMERCIAL'), -- Roberta Costa, telefone comercial
(6, '61', '987567890', 'MOBILE'),   -- Fernando Almeida, telefone móvel
(7, '71', '987678901', 'MOBILE'),   -- Luciana Dias, telefone móvel
(8, '81', '987789012', 'MOBILE'),   -- Eduardo Lima, telefone móvel
(9, '91', '987890123', 'MOBILE'),   -- Felipe Santos, telefone móvel
(10, '11', '987901234', 'MOBILE');  -- Juliana Barbosa, telefone móvel

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

/* CRIAÇÃO DAS VIEWS MATERIALIZADAS E VIEWS*/

-- LISTAGEM DE TODOS OS AUTORES (VIEW MATERIALIZADA)
CREATE MATERIALIZED VIEW mt_vw_list_all_authors AS
SELECT
    idAuthor,
    nameAuthor AS Nome,
    dateofBirthAuthor AS DataNascimento,
    nationalityAuthor AS Nacionalidade,
    biographyAuthor AS Biografia
FROM Author
WHERE idAuthor > 0
ORDER BY nameAuthor;

-- LISTAGEM DE TODOS OS GÊNEROS (VIEW MATERIALIZADA)
CREATE MATERIALIZED VIEW mt_vw_list_all_genres AS
SELECT
    idGenre AS ID,
    nameGenre AS Nome,
    descriptionGenre AS Descrição
FROM Genre
WHERE idGenre > 0
ORDER BY nameGenre;

-- LISTAGEM DE TODOS OS LIVROS DA ACERVO (VIEW MATERIALIZADA)
CREATE MATERIALIZED VIEW mt_vw_list_all_books AS
SELECT
    b.idBook AS ID,
    b.titleBook AS Titulo,
    b.isbnBook AS ISBN,
    a.nameAuthor AS Autor,
    g.nameGenre AS Gênero,
    b.publicationYearBook AS AnoPublicação,
    p.namePublisher AS Editora,
    b.descriptionBook AS Descrição,
    b.searchLevel AS NívelDeBusca
FROM Book b

JOIN Book_has_Author bha ON bha.idBook = b.idBook
JOIN Author a ON a.idAuthor = bha.idAuthor

JOIN Book_has_Genre bhg ON bhg.idBook = b.idBook
JOIN Genre g ON g.idGenre = bhg.idGenre

JOIN Book_has_Publisher bhp ON bhp.idBook = b.idBook
JOIN Publisher p ON p.idPublisher = bhp.idPublisher

WHERE b.idBook > 0
ORDER BY b.titleBook;

-- LISTAGEM DE TODOS OS EMPRÉSTIMOS (VIEW)
CREATE OR REPLACE VIEW vw_list_all_loans AS
SELECT
    l.idLoan AS ID,
    p.namePerson AS Usuário,
    b.titleBook AS Exemplar,
    l.dateLoan AS DataEmprestimo,
    l.dueReturnDateLoan AS DataDevoluçãoPrevista,
    l.actualReturnDateLoan AS DataDevoluçãoRealizada,
    l.statusLoan AS Status
FROM Loan l

JOIN SUser u ON u.idUser = l.idUser
JOIN Person p ON p.idPerson = u.idPerson

JOIN Copy c ON c.idCopy = l.idCopy
JOIN Book b ON b.idBook = c.idBook

WHERE l.idLoan > 0
ORDER BY l.dateLoan;

-- LISTAGEM DE TODOS OS EMPRÉSTIMOS ATRASADOS (VIEW)
CREATE OR REPLACE VIEW vw_list_overdue_loans AS
SELECT
    l.idLoan AS ID,
    p.namePerson AS Usuário,
    b.titleBook AS Exemplar,
    l.dateLoan AS DataEmprestimo,
    l.dueReturnDateLoan AS DataDevoluçãoPrevista,
    l.actualReturnDateLoan AS DataDevoluçãoRealizada
FROM Loan l

JOIN SUser u ON u.idUser = l.idUser
JOIN Person p ON p.idPerson = u.idPerson

JOIN Copy c ON c.idCopy = l.idCopy
JOIN Book b ON b.idBook = c.idBook

WHERE l.statusLoan ILIKE 'OVERDUE'
ORDER BY l.dateLoan;

-- LISTAGEM DE TODAS AS RESERVAS (VIEW)
CREATE OR REPLACE VIEW vw_list_all_reservations AS
SELECT
    r.idReservation AS ID,
    p.namePerson AS Usuário,
    b.titleBook AS Exemplar,
    r.dateReservation AS DataReserva,
    r.statusReservation AS Status
FROM Reservation r

JOIN SUser u ON u.idUser = r.idUser
JOIN Person p ON p.idPerson = u.idPerson

JOIN Copy c ON c.idCopy = r.idCopy
JOIN Book b ON b.idBook = c.idBook

WHERE r.idReservation > 0
ORDER BY r.dateReservation;

-- LISTAGEM DE TODAS AS RESERVAS ATIVAS (VIEW)
CREATE OR REPLACE VIEW vw_list_active_reservations AS
SELECT
    r.idReservation AS ID,
    p.namePerson AS Usuário,
    b.titleBook AS Exemplar,
    r.dateReservation AS DataReserva
FROM Reservation r

JOIN SUser u ON u.idUser = r.idUser
JOIN Person p ON p.idPerson = u.idPerson

JOIN Copy c ON c.idCopy = r.idCopy
JOIN Book b ON b.idBook = c.idBook

WHERE r.statusReservation ILIKE 'ACTIVE'
ORDER BY r.dateReservation;

-- LISTAGEM DE TODAS AS MULTAS (VIEW)
CREATE OR REPLACE VIEW vw_list_all_fines AS
SELECT
    f.idFine AS ID,
    p.namePerson AS Usuário,
    f.amountFine AS Valor,
    f.paymentStatusFine AS Status
FROM Fine f

JOIN Loan l ON l.idLoan = f.idLoan
JOIN SUser u ON u.idUser = l.idUser
JOIN Person p ON p.idPerson = u.idPerson

WHERE f.idFine > 0
ORDER BY p.namePerson;

-- LISTAGEM DE TODAS AS MULTAS PENDENTES (VIEW)
CREATE OR REPLACE VIEW vw_list_pending_fines AS
SELECT
    f.idFine AS ID,
    p.namePerson AS Usuário,
    f.amountFine AS Valor
FROM Fine f

JOIN Loan l ON l.idLoan = f.idLoan
JOIN SUser u ON u.idUser = l.idUser
JOIN Person p ON p.idPerson = u.idPerson

WHERE f.paymentStatusFine  ILIKE 'PENDING'
ORDER BY p.namePerson;