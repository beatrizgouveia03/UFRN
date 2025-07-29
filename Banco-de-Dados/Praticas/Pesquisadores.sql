CREATE TABLE IF NOT EXISTS "Colaboracao" (
	"idColaboracao" serial NOT NULL UNIQUE,
	"idArtigo" bigint NOT NULL,
	"idPesquisador" bigint NOT NULL,
	PRIMARY KEY ("idColaboracao")
);

CREATE TABLE IF NOT EXISTS "Periodico" (
	"idPeriodico" serial NOT NULL UNIQUE,
	"nomePeriodico" varchar(40) NOT NULL,
	"isbnPeriodico" varchar(13) NOT NULL,
	"fatorImpacto" double precision NOT NULL,
	"citeScore" double precision NOT NULL,
	"hIndex" double precision NOT NULL,
	PRIMARY KEY ("idPeriodico")
);

CREATE TABLE IF NOT EXISTS "Titulacao" (
	"tipoTitulacao" varchar(100) NOT NULL,
	"descricaoTitulacao" varchar(255) NOT NULL,
	"idTitulacao" serial NOT NULL UNIQUE,
	PRIMARY KEY ("idTitulacao")
);

CREATE TABLE IF NOT EXISTS "Artigo" (
	"idArtigo" serial NOT NULL UNIQUE,
	"tituloArtigo" varchar(40) NOT NULL,
	"resumoArtigo" varchar(255) NOT NULL,
	PRIMARY KEY ("idArtigo")
);

CREATE TABLE IF NOT EXISTS "Publicacao" (
	"idPublicacao" serial NOT NULL UNIQUE,
	"idArtigo" bigint NOT NULL,
	"idPeriodico" bigint NOT NULL,
	"paginaInicial" bigint NOT NULL,
	"paginaFinal" bigint NOT NULL,
	"doiPeriodico" varchar(20) NOT NULL,
	"volumePeriodico" bigint NOT NULL,
	"numeroPeriodico" bigint NOT NULL,
	"anoPublicacao" bigint NOT NULL,
	PRIMARY KEY ("idPublicacao")
);

CREATE TABLE IF NOT EXISTS "Pesquisador_has_titulacao" (
	"idPesquisador_has_Titulacao" serial NOT NULL UNIQUE,
	"idPesquisador" bigint NOT NULL,
	"idTitulacao" bigint NOT NULL,
	PRIMARY KEY ("idPesquisador_has_Titulacao")
);

CREATE TABLE IF NOT EXISTS "Pesquisador" (
	"idPesquisador" serial NOT NULL UNIQUE,
	"nomePesquisador" varchar(40) NOT NULL,
	"siglaInstituicaoPesquisador" varchar(10) NOT NULL,
	PRIMARY KEY ("idPesquisador")
);

ALTER TABLE "Colaboracao" ADD CONSTRAINT "Colaboracao_fk1" FOREIGN KEY ("idArtigo") REFERENCES "Artigo"("idArtigo");

ALTER TABLE "Colaboracao" ADD CONSTRAINT "Colaboracao_fk2" FOREIGN KEY ("idPesquisador") REFERENCES "Pesquisador"("idPesquisador");



ALTER TABLE "Publicacao" ADD CONSTRAINT "Publicacao_fk1" FOREIGN KEY ("idArtigo") REFERENCES "Artigo"("idArtigo");

ALTER TABLE "Publicacao" ADD CONSTRAINT "Publicacao_fk2" FOREIGN KEY ("idPeriodico") REFERENCES "Periodico"("idPeriodico");
ALTER TABLE "Pesquisador_has_titulacao" ADD CONSTRAINT "Pesquisador_has_titulacao_fk1" FOREIGN KEY ("idPesquisador") REFERENCES "Pesquisador"("idPesquisador");

ALTER TABLE "Pesquisador_has_titulacao" ADD CONSTRAINT "Pesquisador_has_titulacao_fk2" FOREIGN KEY ("idTitulacao") REFERENCES "Titulacao"("idTitulacao");
