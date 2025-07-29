CREATE TABLE IF NOT EXISTS "Animal" (
	"idAnimal" serial NOT NULL UNIQUE,
	"nomeAnimal" varchar(255) NOT NULL,
	"especieAnimal" varchar(255) NOT NULL,
	"dataNascimentoAnimal" varchar(255) NOT NULL,
	PRIMARY KEY ("idAnimal")
);

CREATE TABLE IF NOT EXISTS "Funcionario" (
	"idFuncionario" serial NOT NULL UNIQUE,
	"nomeFuncionario" varchar(255) NOT NULL,
	PRIMARY KEY ("idFuncionario")
);

CREATE TABLE IF NOT EXISTS "Cargo" (
	"idCargo" serial NOT NULL UNIQUE,
	"nomeCargo" varchar(255) NOT NULL,
	"salario" varchar(255) NOT NULL,
	PRIMARY KEY ("idCargo")
);

CREATE TABLE IF NOT EXISTS "Visitante" (
	"idVisitante" serial NOT NULL UNIQUE,
	"nomeVisitante" varchar(255) NOT NULL,
	"tipo" varchar(255) NOT NULL,
	PRIMARY KEY ("idVisitante")
);

CREATE TABLE IF NOT EXISTS "Rel_Visitante_Entrada" (
	"idRel_Visitante_Entrada" serial NOT NULL UNIQUE,
	"idVisitante" bigint NOT NULL,
	"idEntrada" bigint NOT NULL,
	"dataVisita" date NOT NULL,
	PRIMARY KEY ("idRel_Visitante_Entrada")
);

CREATE TABLE IF NOT EXISTS "Entrada" (
	"idEntrada" serial NOT NULL UNIQUE,
	"tipoEntrada" varchar(255) NOT NULL,
	"valor" varchar(255) NOT NULL,
	PRIMARY KEY ("idEntrada")
);

CREATE TABLE IF NOT EXISTS "Rel_Func_Cargo" (
	"idRel_Func_Cargo" serial NOT NULL UNIQUE,
	"idFuncionario" bigint NOT NULL,
	"idCargo" bigint NOT NULL,
	PRIMARY KEY ("idRel_Func_Cargo")
);





ALTER TABLE "Rel_Visitante_Entrada" ADD CONSTRAINT "Rel_Visitante_Entrada_fk1" FOREIGN KEY ("idVisitante") REFERENCES "Visitante"("idVisitante");

ALTER TABLE "Rel_Visitante_Entrada" ADD CONSTRAINT "Rel_Visitante_Entrada_fk2" FOREIGN KEY ("idEntrada") REFERENCES "Entrada"("idEntrada");

ALTER TABLE "Rel_Func_Cargo" ADD CONSTRAINT "Rel_Func_Cargo_fk1" FOREIGN KEY ("idFuncionario") REFERENCES "Funcionario"("idFuncionario");

ALTER TABLE "Rel_Func_Cargo" ADD CONSTRAINT "Rel_Func_Cargo_fk2" FOREIGN KEY ("idCargo") REFERENCES "Cargo"("idCargo");
