-- Criando tabela de Funcionario
CREATE TABLE Funcionario(
	idFuncionario SERIAL NOT NULL,
	nomeFuncionario VARCHAR(30),
	cidadeFuncionario VARCHAR(40),
	PRIMARY KEY(idFuncionario)
);

-- Criando tabela de Produto
CREATE TABLE Produto(
	idProduto SERIAL NOT NULL,
	nomeProduto VARCHAR(30),
	precoProduto FLOAT,
	PRIMARY KEY(idProduto)
);

-- Criando tabela de Solicitacao
CREATE TABLE Solicitacao(
	idSolicitacao SERIAL NOT NULL,
	dataSolicitacao DATE,
	idFuncionario INTEGER NOT NULL,
	PRIMARY KEY(idSolicitacao),
	FOREIGN KEY(idFuncionario) 
		REFERENCES Funcionario(idFuncionario)
);

-- Criando tabela de Item
CREATE TABLE Item(
	idItem SERIAL NOT NULL,
	quantidade INTEGER NOT NULL,
	idProduto INTEGER NOT NULL,
	idSolicitacao INTEGER NOT NULL,
	PRIMARY KEY(idItem),
	FOREIGN KEY(idProduto) 
		REFERENCES Produto(idProduto),
	FOREIGN KEY(idSolicitacao)
		REFERENCES Solicitacao(idSolicitacao)
);