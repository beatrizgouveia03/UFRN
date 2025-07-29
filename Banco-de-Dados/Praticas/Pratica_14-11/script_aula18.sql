-- Consulta A
Select nomeTrabalhador, dataNascimento, especialidadeTrabalhador
From Trabalhador
Where especialidadeTrabalhador in ('hortelão','jardineiro')
Or dataNascimento between '1980-01-01' and '2005-01-01'

-- Consulta B
Select p.nomeProduto, p.areaPlantada
From Produto p
join Trabalhador t on t.idTrabalhador = p.idTrabalhador
Where t.especialidadeTrabalhador ilike 'hort%'

-- Consulta C
Select v.dataVenda, valorVenda
From Venda v
join Comprador c on c.idComprador = v.idComprador
Where c.cidadeComprador in ('Natal', 'Mossoro', 'Macaiba')

-- Consulta C'
-- Produto Cartesiano
Select v.dataVenda, valorVenda
From Venda v, Comprador c
Where c.idComprador = v.idComprador
And c.cidadeComprador in ('Natal', 'Mossoro', 'Macaiba')

