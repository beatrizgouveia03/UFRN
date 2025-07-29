CREATE TABLE Cliente (
  idCliente SERIAL NOT NULL,
  nomeCliente VARCHAR(45) NOT NULL,
  cpf VARCHAR(14) NOT NULL,
  email VARCHAR(20) NOT NULL,
  PRIMARY KEY(idCliente)
);

CREATE TABLE Servico (
  idServico serial NOT NULL,
  descricaoServico VARCHAR(30) NOT NULL,
  valorServico FLOAT NOT NULL,
  horasServico INTEGER NOT NULL,
  PRIMARY KEY(idServico)
);

/*
2.a)
Possíveis situações de orçamento: ABERTO, FINALIZADO, AGUARDANDO, CONCLUINDO
*/
CREATE TABLE Orcamento (
  idOrcamento SERIAL NOT NULL,
  descricaoProblema VARCHAR(50) NOT NULL,
  situacao VARCHAR(15) NOT NULL CHECK (situacao IN ('ABERTO','FINALIZADO','AGUARDANDO','APROVADO')),
  dataInicio DATE NULL,
  dataFim DATE NULL,
  totalValor FLOAT NULL,
  totalHoras INTEGER NULL,
  idCliente INTEGER NOT NULL REFERENCES Cliente,
  PRIMARY KEY(idOrcamento)
);

CREATE TABLE Itens (
  idItens SERIAL NOT NULL,
  idServico INTEGER NOT NULL REFERENCES Servico,
  idOrcamento INTEGER NOT NULL REFERENCES Orcamento,
  situacaoServico VARCHAR(12) NULL,
  PRIMARY KEY(idItens)
);

/*
Inserts de Cliente
*/
Insert into Cliente (nomeCliente, cpf, email) values 
('Angelina', '123.568.789-41', 'angelina@gmail.com'),
('Bread Pitt', '874.125.742-22', 'pitt@gmail.com'),
('Roberto Carlos', '594.235.789-99', 'roberto@gmail.com'),
('Francisco dos Santos','369.951.753-33', 'francisco@gmail.com'),
('Ana Cristiva Silva', 	'159.853.951-23', 'anac@gmail.com');


/* 4.a) criando trigger controle de Serviço*/
CREATE FUNCTION fc_servico_verifica_campos() 
RETURNS trigger AS $tr_servico_verifica_campos$
BEGIN 
   IF NEW.valorServico < 60 THEN
      RAISE EXCEPTION '% não pode ter um valor menor que 60', NEW.descricaoServico;
	  ROLLBACK;
   END IF; 
   IF NEW.horasServico < 1 THEN
      RAISE EXCEPTION '% não pode ter uma quantidade de horas menor que 1', NEW.descricaoServico;
	  ROLLBACK;
   END IF;
RETURN NEW;
END;
$tr_servico_verifica_campos$ LANGUAGE plpgsql;

/* Associando o gatilho ao evento de Insert ou Update*/
CREATE TRIGGER tr_servico_verifica_campos BEFORE INSERT OR UPDATE 
ON Servico
FOR EACH ROW EXECUTE 
PROCEDURE fc_servico_verifica_campos();

/*
Inserts de Serviço
*/
Insert into Servico (descricaoServico, valorServico, horasServico) values ('Trocar oleo do motor', 145.50, 1);
Insert into Servico (descricaoServico, valorServico, horasServico) values ('Balanceamento', 60.00, 1);
Insert into Servico (descricaoServico, valorServico, horasServico) values ('Suspensão', 450.50, 4);
Insert into Servico(descricaoServico, valorServico, horasServico) values ('Injeção Eletrônica', 150.00, 2);
Insert into Servicos (descricaoServico, valorServico, horasServico) values ('Embreagem', 75.25, 1);
Insert into Servico (descricaoServico, valorServico, horasServico) values ('Check-Up', 25.25, 1);


/* 4.b) criando trigger controle de Orçamento*/
CREATE FUNCTION fc_abrir_orcamento() RETURNS trigger AS $tr_abrir_orcamento$
BEGIN
   -- Insere o status ABERTO e data corrente
   IF NEW.descricaoProblema IS NOT NULL THEN
      NEW.situacao = 'ABERTO';
	  NEW.dataInicio = CURRENT_DATE;
	  NEW.totalValor = 0.0;
	  NEW.totalHoras = 0;
   END IF;   
RETURN NEW;
END;
$tr_abrir_orcamento$ LANGUAGE plpgsql;

/* Associando o gatilho ao evento de Insert ou Update*/
CREATE TRIGGER tr_abrir_orcamento BEFORE INSERT 
ON Orcamento
FOR EACH ROW EXECUTE 
PROCEDURE fc_abrir_orcamento();

/*
Inserts de Orçamento
*/
Insert into Orcamento (descricaoProblema, idCliente) values ('Vibrações e direção puxando', 1);
Insert into Orcamento (descricaoProblema, idCliente) values ('Dificuldade no engate das marchas', 2);
Insert into Orcamento (descricaoProblema, idCliente) values ('Falhando e sem força', 3);


/* 4.c) criando trigger controle de Itens*/
CREATE FUNCTION fc_itens_inserir() RETURNS trigger AS $tr_itens_inserir$
BEGIN
   -- Insere o status ABERTO
   IF NEW.idServico IS NOT NULL THEN
      NEW.situacaoServico = 'ABERTO';
   END IF;   
RETURN NEW;
END;
$tr_itens_inserir$ LANGUAGE plpgsql;

/* Associando o gatilho ao evento de Insert ou Update*/
CREATE TRIGGER tr_itens_inserir BEFORE INSERT 
ON Itens
FOR EACH ROW EXECUTE 
PROCEDURE fc_itens_inserir();

/*
Inserts de Itens
*/
Insert into Itens (idServico, idOrcamento) values (1, 1);
Insert into Itens (idServico, idOrcamento) values (2, 1);
Insert into Itens (idServico, idOrcamento) values (3, 2);
Insert into Itens (idServico, idOrcamento) values (4, 2);


/* 4.d) View */
create view vw_Orcamento
as
Select c.nomeCliente, c.cpf, c.email, o.dataInicio, o.descricaoProblema, o.situacao,
o.totalValor, s.descricaoServico, s.valorServico, s.horasServico 
from Cliente c
join Orcamento o on o.idCliente = c.idCliente
join Itens i on i.idOrcamento = o.idOrcamento
join Servico s on s.idServico = i.idServico 
where o.situacao = 'FINALIZADO';

Select * from vw_Orcamento


/* 4.e) Trigger para controlar mudança de status do Orçamento 
Se mudar status de ABERTO para AGUARDANDO, mudar também nos itens
*/

CREATE FUNCTION fc_atualizar_itens_orcamento() RETURNS TRIGGER AS $tr_atualizar_itens_orcamento$
BEGIN
	IF (NEW.situacao <> OLD.situacao) AND (NEW.situacao = 'AGUARDANDO') THEN
		UpDate itens
		SET situacaoServico = NEW.situacao
		WHERE idOrcamento = OLD.idOrcamento; 
	END IF;	
    RETURN NEW;
END;
$tr_atualizar_itens_orcamento$ LANGUAGE plpgsql;

CREATE TRIGGER tr_atualizar_itens_orcamento
AFTER UPDATE ON Orcamento
FOR EACH ROW EXECUTE PROCEDURE fc_atualizar_itens_orcamento();

-- testando a function
Update Orcamento
set situacao = 'AGUARDANDO'
where idorcamento = 1;


/* 4.f) Trigger para controlar mudança de status dos Itens 
Se mudar status de AGUARDANDO para APROVADO, mudar também o status de Orçamento,
somar os valores e as horas e atualizar.
*/

CREATE FUNCTION fc_atualizar_orcamento() RETURNS TRIGGER AS $tr_atualizar_orcamento$
DECLARE
   valor float   := 0.0;
   hora  integer := 0;
BEGIN
	IF (NEW.situacaoServico <> OLD.situacaoServico) AND (NEW.situacaoServico = 'APROVADO') THEN
		UpDate Orcamento
		SET situacao = NEW.situacaoServico
		WHERE idOrcamento = OLD.idOrcamento;
		
		Select valorServico into valor  From Servico where idServico = OLD.idServico;
		Select horasServico into hora   From Servico where idServico = OLD.idServico; 

		UpDate Orcamento
		SET totalValor = totalValor + valor
		where idOrcamento = OLD.idOrcamento;
		
		UpDate Orcamento
		SET totalHoras = totalHoras + hora
		where idOrcamento = OLD.idOrcamento;

	END IF;	
    RETURN NEW;
END;
$tr_atualizar_orcamento$ LANGUAGE plpgsql;

CREATE TRIGGER tr_atualizar_orcamento
AFTER UPDATE ON Itens
FOR EACH ROW EXECUTE PROCEDURE fc_atualizar_orcamento();

-- testando a function
Update Itens
set situacaoservico = 'APROVADO'
where situacaoservico like 'AGUARDANDO';