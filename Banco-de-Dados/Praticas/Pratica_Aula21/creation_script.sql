CREATE TABLE Comprador (
	idComprador SERIAL NOT NULL,
	nomeComprador VARCHAR(40),
	cidadeComprador VARCHAR(20),
	PRIMARY KEY(idComprador)
);

CREATE TABLE Trabalhador (
	idTrabalhador SERIAL NOT NULL,
	nomeTrabalhador VARCHAR(40),
	dataNascimento DATE,
	especialidade VARCHAR(10),
	PRIMARY KEY(idTrabalhador)
);

CREATE TABLE Produto (
	idProduto	SERIAL NOT NULL,
	idTrabalhador	INTEGER,
	descricaoProduto VARCHAR(40),
	areaPlantada FLOAT,
	PRIMARY KEY(idProduto),
	FOREIGN KEY (idTrabalhador)
		REFERENCES Trabalhador(idTrabalhador)
);

CREATE TABLE Venda (
	idVenda SERIAL NOT NULL,
	idComprador	INTEGER,
	idProduto	INTEGER,
	dataVenda	 DATE,
	quantidadeProduto	INTEGER,
	valorVenda	FLOAT,
	dataRecebimento	DATE,
	PRIMARY KEY(idVenda),
	FOREIGN KEY (idComprador)
		REFERENCES Comprador(idComprador),
	FOREIGN KEY (idProduto)
		REFERENCES Produto(idProduto)
);


