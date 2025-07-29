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

-- Inserções dos produtos
INSERT INTO Produto(nomeProduto, precoProduto) VALUES ('Computador', 1499.99);
INSERT INTO Produto(nomeProduto, precoProduto) VALUES ('Monitor', 1200.00);
INSERT INTO Produto(nomeProduto, precoProduto) VALUES ('Teclado', 99.90);
INSERT INTO Produto(nomeProduto, precoProduto) VALUES ('Mouse', 49.99);
INSERT INTO Produto(nomeProduto, precoProduto) VALUES ('Tablet', 1799.90);

-- Inserções dos funcionarios
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Emmanuel', 'Natal');
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Danilo', 'Ceará-Mirim');
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Murilo', 'São José de Mipibu');
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Emily', 'Natal');
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Cleiton', 'Natal');
INSERT INTO Funcionario(nomeFuncionario, cidadeFuncionario) VALUES ('Beatriz', 'Parnamirim');

-- Inserções das solicitações
INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-04-22'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Emmanuel';
INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-04-22'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Beatriz';
INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-04-22'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Emily';

INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-11-13'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Emily';
INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-11-13'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Danilo';
INSERT INTO Solicitacao(dataSolicitacao, idFuncionario) 
	SELECT date('2024-11-13'), idFuncionario FROM Funcionario WHERE nomeFuncionario LIKE 'Cleiton';

-- Inserções dos itens
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 1000
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Tablet'
				WHERE s.dataSolicitacao = '2024-04-22'
  					AND f.nomeFuncionario LIKE 'Emmanuel';
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 100
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Teclado'
				WHERE s.dataSolicitacao = '2024-04-22'
  					AND f.nomeFuncionario LIKE 'Beatriz';
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 5
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Teclado'
				WHERE s.dataSolicitacao = '2024-04-22'
  					AND f.nomeFuncionario LIKE 'Emily';
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 17
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Mouse'
				WHERE s.dataSolicitacao = '2024-11-13'
  					AND f.nomeFuncionario LIKE 'Emily';
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 80
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Tablet'
				WHERE s.dataSolicitacao = '2024-11-13'
  					AND f.nomeFuncionario LIKE 'Cleiton';			
INSERT INTO Item(idSolicitacao, idProduto, quantidade)
	SELECT s.idSolicitacao, p.idProduto, 50
		FROM Solicitacao s JOIN Funcionario f ON s.idFuncionario = f.idFuncionario
			JOIN Produto p ON p.nomeProduto LIKE 'Computador'
				WHERE s.dataSolicitacao = '2024-11-13'
  					AND f.nomeFuncionario LIKE 'Danilo';


-- Mostre todos os produtos (nomeProduto) que o preço for maior que R$ 100,00
SELECT nomeProduto FROM Produto WHERE precoProduto > 100.00;

-- Mostre todos os funcionários que moram em Natal e Parnamirim
SELECT nomeFuncionario FROM Funcionario WHERE cidadeFuncionario IN ('Natal', 'Parnamirim');

-- Mostre todos os produtos que tiveram a quantidade solicitada maior que 50
SELECT nomeProduto FROM Produto p JOIN Item i ON p.idProduto = i.idProduto AND i.quantidade > 50;

-- Mostre o nome dos funcionários, sem repetição, que fizeram solicitações na data de ontem
SELECT nomeFuncionario FROM Funcionario F JOIN Solicitacao s 
	ON f.idFuncionario = s.idFuncionario AND s.dataSolicitacao = '2024-11-13';

-- Mostre todas as solicitações (funcionários, produtos, preços e quantidades) feitas em 22/04/2024
SELECT nomeFuncionario, nomeProduto, precoProduto, quantidade 
	FROM Item i JOIN Produto p ON i.idProduto = p.idProduto
		JOIN Solicitacao s ON i.idSolicitacao = s.idSolicitacao AND s.dataSolicitacao = '2024-04-22'
				JOIN Funcionario f ON s.idFuncionario = f.idFuncionario;

-- Mostre o total (valor = preço * quantidade) das solicitações feitas pelos funcionários
SELECT nomeFuncionario, (i.quantidade * p.precoProduto) as totalSolicitacao FROM Funcionario f
	JOIN Solicitacao s ON f.idFuncionario = s.idFuncionario
		JOIN Item i ON s.idSolicitacao = i.idSolicitacao
			JOIN Produto p ON p.idProduto =  i.idProduto;