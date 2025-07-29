CREATE TABLE IF NOT EXISTS "Facilidade" (
	"idFacilidade" serial NOT NULL UNIQUE,
	"nomeFacilidade" varchar(255) NOT NULL,
	PRIMARY KEY ("idFacilidade")
);

CREATE TABLE IF NOT EXISTS "tipoFacilidade" (
	"idTipoFacilidade" serial NOT NULL UNIQUE,
	"descricaoTipoFacilidade" varchar(255) NOT NULL,
	"idFacilidade" bigint NOT NULL,
	PRIMARY KEY ("idTipoFacilidade")
);

CREATE TABLE IF NOT EXISTS "Pessoa" (
	"idPessoa" serial NOT NULL UNIQUE,
	"nomePessoa" varchar(255) NOT NULL,
	"cpfPessoa" varchar(11) NOT NULL,
	"e" bigint NOT NULL,
	"idEndereco" bigint NOT NULL,
	PRIMARY KEY ("idPessoa")
);

CREATE TABLE IF NOT EXISTS "Endereco" (
	"idEndereco" serial NOT NULL UNIQUE,
	"logradouro" varchar(40) NOT NULL,
	"bairro" varchar(20) NOT NULL,
	"municipio" varchar(20) NOT NULL,
	PRIMARY KEY ("idEndereco")
);

CREATE TABLE IF NOT EXISTS "ReservaFacilidade" (
	"idRese" bigint NOT NULL,
	"idReservaFacilidade" serial NOT NULL UNIQUE,
	"perioa" bigint NOT NULL,
	"perio" bigint NOT NULL,
	"periodoAluguel" bigint NOT NULL,
	"dataAluguel" date NOT NULL,
	"idFacilidade" bigint NOT NULL,
	"idPessoa" bigint NOT NULL,
	PRIMARY KEY ("idReservaFacilidade")
);

CREATE TABLE IF NOT EXISTS "ReservaEquipamento" (
	"idReservaEquipamento" serial NOT NULL UNIQUE,
	"idEquipamento" bigint NOT NULL,
	"idReserva" bigint NOT NULL,
	"q" bigint NOT NULL,
	"quna" bigint NOT NULL,
	"quantidade" bigint NOT NULL,
	"dataReserva" date NOT NULL,
	PRIMARY KEY ("idReservaEquipamento")
);

CREATE TABLE IF NOT EXISTS "Esporte" (
	"idEsporte" serial NOT NULL UNIQUE,
	"descricao" bigint NOT NULL,
	"descricaoEsporte" bigint NOT NULL,
	"descricaoEspo" bigint NOT NULL,
	PRIMARY KEY ("idEsporte")
);

CREATE TABLE IF NOT EXISTS "Equipamento" (
	"idEquipamento" serial NOT NULL UNIQUE,
	"descricaoEsport" bigint NOT NULL,
	"descricaoE" bigint NOT NULL,
	"descricaoEqipa" bigint NOT NULL,
	"descricaoEquipamento" varchar(255) NOT NULL,
	"idEsporte" bigint NOT NULL,
	PRIMARY KEY ("idEquipamento")
);

CREATE TABLE IF NOT EXISTS "Manutencao" (
	"id" bigint NOT NULL,
	"idManutencao" serial NOT NULL UNIQUE,
	"dataManutencao" date NOT NULL,
	"idPE" bigint NOT NULL,
	"idPessoa" bigint NOT NULL,
	"idFacilidade" bigint NOT NULL,
	PRIMARY KEY ("idManutencao")
);


ALTER TABLE "tipoFacilidade" ADD CONSTRAINT "tipoFacilidade_fk2" FOREIGN KEY ("idFacilidade") REFERENCES "Facilidade"("idFacilidade");
ALTER TABLE "Pessoa" ADD CONSTRAINT "Pessoa_fk4" FOREIGN KEY ("idEndereco") REFERENCES "Endereco"("idEndereco");

ALTER TABLE "ReservaFacilidade" ADD CONSTRAINT "ReservaFacilidade_fk6" FOREIGN KEY ("idFacilidade") REFERENCES "Facilidade"("idFacilidade");

ALTER TABLE "ReservaFacilidade" ADD CONSTRAINT "ReservaFacilidade_fk7" FOREIGN KEY ("idPessoa") REFERENCES "Pessoa"("idPessoa");
ALTER TABLE "ReservaEquipamento" ADD CONSTRAINT "ReservaEquipamento_fk1" FOREIGN KEY ("idEquipamento") REFERENCES "Equipamento"("idEquipamento");

ALTER TABLE "ReservaEquipamento" ADD CONSTRAINT "ReservaEquipamento_fk2" FOREIGN KEY ("idReserva") REFERENCES "ReservaFacilidade"("idReservaFacilidade");

ALTER TABLE "Equipamento" ADD CONSTRAINT "Equipamento_fk5" FOREIGN KEY ("idEsporte") REFERENCES "Esporte"("idEsporte");
ALTER TABLE "Manutencao" ADD CONSTRAINT "Manutencao_fk4" FOREIGN KEY ("idPessoa") REFERENCES "Pessoa"("idPessoa");

ALTER TABLE "Manutencao" ADD CONSTRAINT "Manutencao_fk5" FOREIGN KEY ("idFacilidade") REFERENCES "Facilidade"("idFacilidade");