/* Titulacao */
insert into Titulacao (nomeTitulacao) values ('Doutorado');
insert into Titulacao (nomeTitulacao) values ('Mestrado');

/* Pesquisador */
insert into Pesquisador (nomePesquisador, cpfPesquisador, passaportePesquisador, instituicaoPesquisador, idTitulacao) 
values ('Andre Carvalho', '45678974130', 'N/A', 'UNESP', 1);
insert into Pesquisador (nomePesquisador, cpfPesquisador, passaportePesquisador, instituicaoPesquisador, idTitulacao) 
values ('Teresa Ludermir', '98678974145', 'N/A', 'UFPE', 1);
insert into Pesquisador (nomePesquisador, cpfPesquisador, passaportePesquisador, instituicaoPesquisador, idTitulacao) 
values ('Marley Vellasco', '98678974145', 'N/A', 'PUC-Rio', 1);
insert into Pesquisador (nomePesquisador, cpfPesquisador, passaportePesquisador, instituicaoPesquisador, idTitulacao) 
values ('Raimundo Nonato', '12345678900', 'N/A', 'UFRN', 1);

/* Periodico */
insert into Periodico (nomePeriodico, issnPeriodico, fatorImpactoPeriodico, citeScorePeriodico, hIndexPeriodico)
values ('Applied Soft Computing', '1568-4946', 8.7, 14.3, 190);
insert into Periodico (nomePeriodico, issnPeriodico, fatorImpactoPeriodico, citeScorePeriodico, hIndexPeriodico)
values ('Knowledge and Information Systems', '0030-4874', 2.7, 9.5, 200);
insert into Periodico (nomePeriodico, issnPeriodico, fatorImpactoPeriodico, citeScorePeriodico, hIndexPeriodico)
values ('Theoretical Computer Science', '2530-9874', 1.1, 2.5, 75);

/* Artigo */
insert into Artigo(tituloArtigo, resumoArtigo)
values ('Two approaches for clustering algorithms with relational-based data', 'It is well known that relational databases still play an important role for many companies around the world. For this reason, the use of data mining methods to discover knowledge in large relational databases has become an interesting research issue. In the context of unsupervised data mining, for instance, the conventional clustering algorithms cannot handle the particularities of the relational databases in an efficient way. There are some clustering algorithms for relational datasets proposed in the literature. However, most of these methods apply complex and/or specific procedures to handle the relational nature of data, or the relational-based methods do not capture the relational nature in an efficient way. Aiming to contribute to this important topic, in this paper, we will present two simple and generic approaches to handle relational-based data for clustering algorithms. One of them treats the relational data through the use of a hierarchical structure, while the second approach applies a weight structure based on relationship and attribute information. In presenting these two approaches, we aim to tackle relational-based dataset in a simple and efficient way, improving the efficiency of corporations that handle relational-based in the unsupervised data mining context. In order to evaluate the effectiveness of the presented approaches, a comparative analysis will be conducted, comparing the proposed approaches with some existing approaches and with a baseline approach. In all analyzed approaches, we will use two well-known types of clustering algorithms (agglomerative hierarchical and K-means). In order to perform this analysis, we will use two internal and one external clusters as validity measures.');
insert into Artigo(tituloArtigo, resumoArtigo)
values ('An evolutionary algorithm for automated machine learning focusing on classifier ensembles: An improved algorithm and extended results', 'A large number of classification algorithms have been proposed in the machine learning literature. These algorithms have different pros and cons, and no algorithm is the best for all datasets. Hence, a challenging problem consists of choosing the best classification algorithm with its best hyper-parameter settings for a given input dataset. In the last few years, Automated Machine Learning (Auto-ML) has emerged as a promising approach for tackling this problem, by doing a heuristic search in a large space of candidate classification algorithms and their hyper-parameter settings. In this work we propose an improved version of our previous Evolutionary Algorithm (EA) – more precisely, an Estimation of Distribution Algorithm – for the Auto-ML task of automatically selecting the best classifier ensemble and its best hyper-parameter settings for an input dataset. The new version of this EA was compared against its previous version, as well as against a random forest algorithm (a strong ensemble algorithm) and a version of the well-known Auto-ML method Auto-WEKA adapted to search in the same space of classifier ensembles as the proposed EA. In general, in experiments with 21 datasets, the new EA version obtained the best results among all methods in terms of four popular predictive accuracy measures: error rate, precision, recall and F-measure.');

/* Publicacao */
insert into Publicacao (paginaInicial, paginaFinal, anoPublicacao, volumePublicacao, numeroPublicacao, idPeriodico, idArtigo)
values (1, 24, 2019, 1, 1, 2, 1);
insert into Publicacao (paginaInicial, paginaFinal, anoPublicacao, volumePublicacao, numeroPublicacao, idPeriodico, idArtigo)
values (1, 18, 2020, 805, 1, 3, 2);

/* Colaboracao */
insert into Colaboracao (idPesquisador, idArtigo) values (4, 2);
insert into Colaboracao (idPesquisador, idArtigo) values (2, 2);
insert into Colaboracao (idPesquisador, idArtigo) values (1, 1);
insert into Colaboracao (idPesquisador, idArtigo) values (2, 1);
insert into Colaboracao (idPesquisador, idArtigo) values (3, 1);
