INSERT INTO Comprador (nomeComprador, cidadeComprador) 
VALUES  ('João', 'São Paulo'),
        ('Maria', 'Rio de Janeiro'),
        ('Pedro', 'Belo Horizonte'),
        ('Ana', 'Porto Alegre');

INSERT INTO Trabalhador (nomeTrabalhador, dataNascimento, especialidade)
VALUES  ('Márcio', '1990-01-01', 'Professor'),
        ('Marina', '1995-01-01', 'Designer'),
        ('Carlos', '1992-01-01', 'Professor'),
        ('Júlia', '1996-01-01', 'Designer');

INSERT INTO Produto (idTrabalhador, descricaoProduto, areaPlantada)
VALUES  (1, 'Café', 10.2),
        (2, 'Cacau', 50.5),
        (3, 'Café', 100),
        (4, 'Cacau', 12.8),
        (4, 'Café', 32.9);

INSERT INTO Venda (idComprador, idProduto, dataVenda, quantidadeProduto, valorVenda, dataRecebimento)
VALUES  (1, 1, '2022-01-01', 10, 100, '2022-01-01'),
        (2, 2, '2022-01-01', 20, 200, '2022-01-01'),
        (3, 3, '2022-01-01', 30, 300, '2022-01-01'),
        (4, 4, '2022-01-01', 40, 400, '2022-01-01'),
        (1, 5, '2022-01-01', 50, 500, '2022-01-01');