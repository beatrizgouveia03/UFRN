# Simulador de Rotas em Grafos

## Índice

1. [Introdução](#introdução)
2. [Algoritmos](#algoritmos)
3. [Utilização](#utilização)
4. [Métodos de Compilação](#métodos-de-compilação)
5. [Contribuindo](#contribuindo)
6. [Documentação](#documentação)
7. [Licença](#licença)

## Introdução

O Simulador de Rotas em Grafos é um projeto desenvolvido para demonstrar o funcionamento de diversos algoritmos clássicos em grafos e digrafos ponderados. 
O objetivo principal é fornecer uma ferramenta prática para visualizar, entender e aplicar conceitos fundamentais de teoria dos grafos, sendo eles a construção de árvores geradoras mínimas, o cálculo de caminhos mínimos, a análise de grafos Eulerianos e a resolução de problemas de fluxo em redes.


## Algoritmos

- **Árvores Geradoras Mínimas:**
  - [x] (1) Kruskal [Anny]
  - [x] (2) Prim [Davi]
  - [x] (3) Chu-Liu/Edmonds [José]
- **Caminho mais curto:**
  - [x] (4) Dijkstra [Anny]
  - [x] (5) Bellman-Ford [Alisson]
  - [x] (6) Floyd-Warshall [Davi]
- **Grafos Eulerianos:**
  - [x] (7) Hierholzer (ciclos) [Alisson]
  - [x] (8) Hierholzer (caminhos) [Beatriz]
- **Fluxo em Redes:**
  - [x] (9) Ford-Fulkerson [José]
  - [x] (10) Edmonds-Karp [Beatriz]

## Utilização

Para utilizar este projeto, siga os passos abaixo:

1. Clone o repositório em sua máquina local utilizando o seguinte comando:

   ```shell
   git clone https://github.com/beatrizgouveia03/Grafos.git
   ```

2. Navegue até o diretório deste projeto: 

   ```shell
   cd Grafos/Projetos/Route_in_Graphs/
   ```

3. Compile o projeto de acordo com o método de sua escolha (veja [Métodos de Compilação](#métodos-de-compilação) para mais detalhes).

4. Execute o programa compilado para visualizar os algoritmos de rotas em grafos em execução com seus arquivos de entrada.

## Métodos de Compilação

Este projeto utiliza o CMake como sistema de build, permitindo uma compilação fácil e eficiente do código em C++. Para compilar os algoritmos, siga os passos abaixo:

1. Certifique-se de que o CMake está instalado no seu sistema.

2. Navegue até o diretório do projeto:

   ```shell
   cd Grafos/Projetos/Route_in_Graphs/
   ```

3. Crie um diretório de build e gere um Makefile Unix baseado no script encontrado no nível atual:

   ```shell
   cmake -S . -B build
   ```

4. Compile o projeto utilizando os arquivos de build gerados:

   ```shell
   cmake --build build
   ```

5. Após a compilação bem-sucedida, você encontrará o arquivo executável no diretório `build`, com o nome `Route_in_Graphs`. Execute o programa para visualizar os algoritmos em ação com os arquivos de entrada selecionados.

## Contribuindo

Contribuições para este projeto são bem-vindas! Se você deseja melhorar a implementação de um algoritmo existente, adicionar um novo algoritmo, introduzir novos cenários ou corrigir quaisquer problemas, siga os passos abaixo:

1. Faça um fork do repositório.

2. Crie uma nova branch para sua contribuição:

   ```shell
   git checkout -b feature/novo-algoritmo
   ```

3. Realize suas modificações e adições.

4. Faça o commit das suas alterações:

   ```shell
   git commit -m "Adicionar novo algoritmo: [Nome do Algoritmo]"
   ```

5. Envie sua branch:

   ```shell
   git push origin feature/novo-algoritmo
   ```

6. Abra um pull request, descrevendo suas alterações e a motivação por trás delas.

## Documentação

O projeto utiliza o Doxygen para gerar a documentação. Para gerar a documentação, navegue até o diretório do projeto e execute o seguinte comando:

```shell
doxygen Doxyfile
```

Isso criará uma pasta `docs` (ou outro diretório especificado no campo `OUTPUT_DIRECTORY` do arquivo Doxyfile) com os arquivos da documentação gerada. Você pode visualizar a documentação abrindo o arquivo [index.html](/Projetos/Route_in_Graphs/docs/html/index.html), localizado dentro da subpasta `html`, em seu navegador web.

## Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](/LICENSE.md) para mais detalhes.
