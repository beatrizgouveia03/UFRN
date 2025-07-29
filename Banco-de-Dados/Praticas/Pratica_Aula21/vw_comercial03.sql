/* view 03 */
CREATE VIEW vw_comercial03 AS
	SELECT p.idProduto, p.descricaoProduto, c.nomeComprador, v.dataVenda,v.quantidadeProduto, v.valorVenda
	FROM Venda v
	JOIN Produto p ON p.idProduto = v.idProduto
	JOIN Comprador c ON c.idComprador = v.idComprador

	WHERE v.quantidadeProduto BETWEEN 30 AND 50
	ORDER BY v.dataVenda, c.nomeComprador;