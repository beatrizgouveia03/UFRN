CREATE TABLE IF NOT EXISTS "Funcionario" (
	"idFuncionario" serial NOT NULL UNIQUE,
	"nomeFuncionario" varchar(255) NOT NULL,
	"cpfFuncionario" bigint NOT NULL,
	"dataNascimentoFuncionario" date NOT NULL,
	"enderecoFuncionario" varchar(255) NOT NULL,
	PRIMARY KEY ("idFuncionario")
);

CREATE TABLE IF NOT EXISTS "Funcao" (
	"idFuncao" serial NOT NULL UNIQUE,
	"descricaoFuncao" varchar(255) NOT NULL,
	"salario" double precision NOT NULL,
	PRIMARY KEY ("idFuncao")
);

CREATE TABLE IF NOT EXISTS "Animal" (
	"idAnimal" serial NOT NULL UNIQUE,
	"nomeAnimal" varchar(255) NOT NULL,
	"dataNascimentoAnimal" date NOT NULL,
	"idEspecie" bigint NOT NULL,
	PRIMARY KEY ("idAnimal")
);

CREATE TABLE IF NOT EXISTS "Especie" (
	"idEspecie" serial NOT NULL UNIQUE,
	"nomeEspecie" varchar(255) NOT NULL,
	"tipoAlimento" varchar(255) NOT NULL,
	"idGenero" bigint NOT NULL,
	PRIMARY KEY ("idEspecie")
);

CREATE TABLE IF NOT EXISTS "TratoAnimal" (
	"idTratoAnimal" serial NOT NULL UNIQUE,
	"dataHoraAlimentacao" varchar(255) NOT NULL,
	"qntdeAlimento" double precision NOT NULL,
	"idFuncionario" bigint NOT NULL,
	"idAnimal" bigint NOT NULL,
	PRIMARY KEY ("idTratoAnimal")
);

CREATE TABLE IF NOT EXISTS "Genero" (
	"idGenero" serial NOT NULL UNIQUE,
	"descricaoGenero" varchar(255) NOT NULL,
	"idFamilia" bigint NOT NULL,
	PRIMARY KEY ("idGenero")
);

CREATE TABLE IF NOT EXISTS "Familia" (
	"idFamilia" serial NOT NULL UNIQUE,
	"descricaoFamilia" varchar(255) NOT NULL,
	PRIMARY KEY ("idFamilia")
);

CREATE TABLE IF NOT EXISTS "Historico" (
	"idHistorico" serial NOT NULL UNIQUE,
	"idFuncionario" bigint NOT NULL,
	"idFuncao" bigint NOT NULL,
	"dataAdmissao" date NOT NULL,
	PRIMARY KEY ("idHistorico")
);



ALTER TABLE "Animal" ADD CONSTRAINT "Animal_fk3" FOREIGN KEY ("idEspecie") REFERENCES "Especie"("idEspecie");
ALTER TABLE "Especie" ADD CONSTRAINT "Especie_fk3" FOREIGN KEY ("idGenero") REFERENCES "Genero"("idGenero");
ALTER TABLE "TratoAnimal" ADD CONSTRAINT "TratoAnimal_fk3" FOREIGN KEY ("idFuncionario") REFERENCES "Funcionario"("idFuncionario");

ALTER TABLE "TratoAnimal" ADD CONSTRAINT "TratoAnimal_fk4" FOREIGN KEY ("idAnimal") REFERENCES "Animal"("idAnimal");
ALTER TABLE "Genero" ADD CONSTRAINT "Genero_fk2" FOREIGN KEY ("idFamilia") REFERENCES "Familia"("idFamilia");

ALTER TABLE "Historico" ADD CONSTRAINT "Historico_fk1" FOREIGN KEY ("idFuncionario") REFERENCES "Funcionario"("idFuncionario");

ALTER TABLE "Historico" ADD CONSTRAINT "Historico_fk2" FOREIGN KEY ("idFuncao") REFERENCES "Funcao"("idFuncao");