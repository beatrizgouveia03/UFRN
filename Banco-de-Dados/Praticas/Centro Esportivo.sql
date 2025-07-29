CREATE TABLE IF NOT EXISTS "atleta" (
	"idatleta" bigint NOT NULL UNIQUE,
	"datanascimento" date NOT NULL,
	PRIMARY KEY ("idatleta")
);

CREATE TABLE IF NOT EXISTS "treinador" (
	"idtreinador" bigint NOT NULL UNIQUE,
	PRIMARY KEY ("idtreinador")
);

CREATE TABLE IF NOT EXISTS "modalidade" (
	"idmodalidade" bigint NOT NULL UNIQUE,
	PRIMARY KEY ("idmodalidade")
);

CREATE TABLE IF NOT EXISTS "rel_atl_mod" (
	"idatleta" bigint NOT NULL,
	"idmodalidade" bigint NOT NULL,
	"idrel_atl_mod" bigint NOT NULL UNIQUE,
	PRIMARY KEY ("idrel_atl_mod")
);

CREATE TABLE IF NOT EXISTS "rel_trei_mod" (
	"idrel_trei_mod" bigint NOT NULL UNIQUE,
	"idtreinador" bigint NOT NULL,
	"idmodalidade" bigint NOT NULL,
	PRIMARY KEY ("idrel_trei_mod")
);

CREATE TABLE IF NOT EXISTS "rel_atl_trei" (
	"idrel_atl_trei" bigint NOT NULL UNIQUE,
	"idatleta" bigint NOT NULL,
	"idtreinador" bigint NOT NULL,
	PRIMARY KEY ("idrel_atl_trei")
);




ALTER TABLE "rel_atl_mod" ADD CONSTRAINT "rel_atl_mod_fk0" FOREIGN KEY ("idatleta") REFERENCES "atleta"("idatleta");

ALTER TABLE "rel_atl_mod" ADD CONSTRAINT "rel_atl_mod_fk1" FOREIGN KEY ("idmodalidade") REFERENCES "modalidade"("idmodalidade");
ALTER TABLE "rel_trei_mod" ADD CONSTRAINT "rel_trei_mod_fk1" FOREIGN KEY ("idtreinador") REFERENCES "treinador"("idtreinador");

ALTER TABLE "rel_trei_mod" ADD CONSTRAINT "rel_trei_mod_fk2" FOREIGN KEY ("idmodalidade") REFERENCES "modalidade"("idmodalidade");
ALTER TABLE "rel_atl_trei" ADD CONSTRAINT "rel_atl_trei_fk1" FOREIGN KEY ("idatleta") REFERENCES "atleta"("idatleta");

ALTER TABLE "rel_atl_trei" ADD CONSTRAINT "rel_atl_trei_fk2" FOREIGN KEY ("idtreinador") REFERENCES "treinador"("idtreinador");
