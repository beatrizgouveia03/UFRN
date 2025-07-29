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


	