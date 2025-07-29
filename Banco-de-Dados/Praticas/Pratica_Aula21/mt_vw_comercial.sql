/* Materialized View 01 */
CREATE MATERIALIZED VIEW mt_vw_comercial AS
    SELECT p.idProduto, p.descricaoProduto, c.nomeComprador, v.dataVenda, v.quantidadeProduto, v.valorVenda
    FROM Venda v
    JOIN Produto p ON v.idProduto = p.idProduto
    JOIN Comprador c ON v.idComprador = c.idComprador

    WHERE v.quantidadeProduto BETWEEN 30 AND 50
    ORDER BY v.dataVenda, c.nomeComprador;
