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