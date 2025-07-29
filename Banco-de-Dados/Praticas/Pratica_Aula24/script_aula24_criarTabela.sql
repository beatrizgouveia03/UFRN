/* Função alterada*/
CREATE OR REPLACE FUNCTION criarTabela() RETURNS VOID AS
    $BODY$
        DECLARE
            informacao TEXT;
            i INTEGER;
        BEGIN
	    i := 1;
	    informacao := 'VAMOS POPULAR ESSA TABELA COM MUITO TEXTO';
	    DROP TABLE IF EXISTS tabela2;
	    CREATE TABLE tabela2 (
	         id_numerico INTEGER,
	         id_literal VARCHAR(15),
	         campo1 TEXT,
	         campo2 TEXT,
	         campo3 TEXT
	    );
	    LOOP
	       INSERT INTO tabela2 (id_numerico, id_literal, campo1, campo2, campo3)
	                   values (i, ('IMD000' || i), informacao, informacao, informacao);
               EXIT WHEN i > 100000;
               i := i + 1;
	    END LOOP;
	END;
    $BODY$
LANGUAGE plpgsql VOLATILE;

/* Para executar a função*/
Select criartabela();
