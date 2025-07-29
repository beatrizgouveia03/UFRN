-- Criar tabela Titulação
CREATE TABLE Titulacao (
    idTitulacao SERIAL NOT NULL,
    nomeTitulacao VARCHAR(15) NOT NULL,
    PRIMARY KEY (idTitulacao)
);

-- Criar tabela Pesquisador
CREATE TABLE Pesquisador (
    idPesquisador SERIAL NOT NULL,
    nomePesquisador VARCHAR(50) NOT NULL,
    cpfPesquisador VARCHAR(11) NOT NULL,
    passaportePesquisador VARCHAR(15),
    instituicaoPesquisador VARCHAR(30),
    idTitulacao INTEGER NOT NULL,
    PRIMARY KEY (idPesquisador),
    FOREIGN KEY (idTitulacao) 
        REFERENCES Titulacao(idTitulacao)
);

-- Criar tabela Artigo
CREATE TABLE Artigo (
    idArtigo SERIAL NOT NULL,
    tituloArtigo VARCHAR(250) NOT NULL,
    resumoArtigo TEXT,
    PRIMARY KEY (idArtigo)
);

-- Criar tabela Colaboração
CREATE TABLE Colaboracao (
    idColaboracao SERIAL NOT NULL,
    idPesquisador INTEGER NOT NULL,
    idArtigo INTEGER NOT NULL,
    PRIMARY KEY (idColaboracao),
    FOREIGN KEY (idPesquisador)
        REFERENCES Pesquisador(idPesquisador),
    FOREIGN KEY (idArtigo)
        REFERENCES Artigo(idArtigo)
);

-- Criar tabela Periodico
CREATE TABLE Periodico (
    idPeriodico SERIAL NOT NULL,
    nomePeriodico VARCHAR(40)NOT NULL,
    issnPeriodico VARCHAR(10) NOT NULL,
    fatorImpactoPeriodico FLOAT,
    citeScorePeriodico  FLOAT,
    hIndexPeriodico INTEGER,
    PRIMARY KEY (idPeriodico)
);

-- Criar tabela Publicação
CREATE TABLE Publicacao (
    idPublicacao SERIAL NOT NULL,
    paginaInicial INTEGER NOT NULL,
    paginaFinal INTEGER NOT NULL,
    anoPublicacao INTEGER NOT NULL,
    volumePublicacao INTEGER,
    numeroPublicacao INTEGER,
    idPeriodico INTEGER NOT NULL,
    idArtigo INTEGER NOT NULL,
    PRIMARY KEY (idPublicacao),
    FOREIGN KEY (idPeriodico)
        REFERENCES Periodico(idPeriodico),
    FOREIGN KEY (idArtigo)
        REFERENCES Artigo(idArtigo)
);