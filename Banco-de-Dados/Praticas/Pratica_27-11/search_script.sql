-- a) Mostre o nome do pesquisador e a instituição dos pesquisadores que possuem doutorado.
SELECT nomePesquisador as Pesquisador,
        instituicaoPesquisador as Instituicao
FROM Pesquisador p
 JOIN Titulacao t ON p.idTitulacao = t.idTitulacao
WHERE t.nomeTitulacao = 'Doutorado';

-- b) Mostre os títulos de artigos publicados por pesquisadores da UFRN.
SELECT tituloArtigo as Titulo
FROM Artigo a
    JOIN Colaboracao c ON a.idArtigo = c.idArtigo
    JOIN Pesquisador p ON c.idPesquisador = p.idPesquisador
WHERE p.instituicaoPesquisador = 'UFRN';

-- c) Mostre o nome dos pesquisadores que publicaram no periódico chamado “Theoretical Computer Science”.
SELECT nomePesquisador as Pesquisador
FROM Pesquisador p
    JOIN Colaboracao c ON p.idPesquisador = c.idPesquisador
    JOIN Artigo a ON c.idArtigo = a.idArtigo
    JOIN Publicacao pu ON a.idArtigo = pu.idArtigo
    JOIN Periodico pe ON pu.idPeriodico = pe.idPeriodico
WHERE pe.nomePeriodico = 'Theoretical Computer Science';

-- d) Mostre qual o periódico que possui o maior fator de impacto. 
SELECT nomePeriodico as Periodico,
        fatorImpactoPeriodico as Maior_Fator_Impacto
FROM Periodico
WHERE fatorImpactoPeriodico = 
	(SELECT MAX(fatorImpactoPeriodico) FROM Periodico);

-- e) Mostre o total de artigos publicados por pesquisadores da UFRN. 
SELECT COUNT(a.idArtigo) as Total_de_Artigos
FROM Artigo a
    JOIN Colaboracao c ON a.idArtigo = c.idArtigo
    JOIN Pesquisador p ON c.idPesquisador = p.idPesquisador
WHERE p.instituicaoPesquisador = 'UFRN';