/* view 04 */
CREATE VIEW vw_comercial04 AS
    SELECT p.idProduto, p.descricaoProduto, t. nomeTrabalhador,
        t.especialidade, c.nomeComprador, c.cidadeComprador,
        v.quantidadeProduto, v.valorVenda, v.dataVenda
    FROM Venda v
    JOIN Produto p ON p.idProduto = v.idProduto
    JOIN Comprador c ON c.idComprador = v.idComprador
    JOIN Trabalhador t ON t.idTrabalhador = p.idTrabalhador;
    