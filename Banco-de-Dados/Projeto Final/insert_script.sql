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
