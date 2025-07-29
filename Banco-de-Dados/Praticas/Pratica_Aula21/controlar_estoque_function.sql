/*Criando função */
CREATE FUNCTION f_controlar_estoque() RETURNS TRIGGER AS $t_controla_estoque$
BEGIN 
    IF(TG_OP = 'DELETE') THEN
        UPDATE Produto 
        SET estoque = estoque + OLD.quantidadeProduto
        WHERE idProduto = OLD.idProduto;
    ELSIF (TG_OP = 'UPDATE') THEN
        UPDATE Produto 
        SET estoque = estoque - (NEW.quantidadeProduto - OLD.quantidadeProduto)
        WHERE idProduto = OLD.idProduto;
    ELSIF (TG_OP = 'INSERT') THEN
        UPDATE Produto
        SET estoque = estoque - NEW.quantidadeProduto
        WHERE idProduto = NEW.idProduto;
    END IF;
    RETURN NULL; -- result is ignored since this is an AFTER trigger
END;
$t_controla_estoque$ LANGUAGE plpgsql;

/*Criando trigger*/
CREATE TRIGGER t_controla_estoque
    AFTER INSERT OR UPDATE OR DELETE ON Venda
    FOR EACH ROW EXECUTE PROCEDURE f_controlar_estoque();