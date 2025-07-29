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