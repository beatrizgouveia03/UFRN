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