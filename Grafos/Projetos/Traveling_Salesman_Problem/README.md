# Problema do Caixeiro Viajante

## Índice

1. [Introdução](#introdução)
2. [Algoritmos](#algoritmos)
3. [Cenários](#cenários)
4. [Utilização](#utilização)
5. [Métodos de Compilação](#métodos-de-compilação)
6. [Contribuindo](#contribuindo)
7. [Documentação](#documentação)
8. [Licença](#licença)

## Introdução

O problema do caixeiro viajante (Traveling Salesman Problem - TSP) é um dos problemas clássicos de otimização combinatória. Ele consiste em encontrar o menor caminho possível que permita a um vendedor visitar todas as cidades de um conjunto exatamente uma vez e retornar à cidade de origem. Apesar de sua formulação simples, o TSP é um problema NP-difícil, o que significa que sua resolução exata para grandes instâncias requer um esforço computacional significativo.

O objetivo deste projeto é explorar diferentes algoritmos para resolver o TSP, avaliando seus desempenhos em diferentes cenários.

## Algoritmos

Algoritmos Implementados
Neste projeto, foram implementados quatro algoritmos diferentes para resolver o problema do caixeiro viajante (Traveling Salesman Problem - TSP), cada um com abordagens específicas para encontrar soluções otimizadas:

*Guloso*

- Um algoritmo simples que constrói o tour escolhendo a aresta mais barata disponível em cada passo, até que todas as cidades sejam visitadas.

*Inserção Mais Barata*
- Insere cidades no tour de forma incremental, sempre escolhendo a posição que resulta no menor custo adicional.

*GRASP com Troca de Vizinhança*
- Um método baseado em busca local onde uma solução inicial é construída de forma aleatória e, em seguida, é refinada por meio de trocas entre pares de cidades.

*GRASP com Reversão de Sub-Caminho*
- Similar ao GRASP anterior, mas o refinamento é feito invertendo subcaminhos do tour, explorando uma vizinhança diferente.
Esses algoritmos permitem comparar diferentes abordagens e analisar o impacto das estratégias de otimização sobre o custo total do tour.

## Cenários
Para testar os algoritmos implementados, foram utilizados diferentes cenários baseados em um conjunto de cidades do estado do Rio Grande do Norte. Esses cenários foram projetados para avaliar o desempenho dos algoritmos em instâncias de diferentes tamanhos, variando de pequenos problemas a situações mais complexas.

Os cenários considerados incluem os seguintes tamanhos de instâncias:
- 6 cidades
- 7 cidades
- 12 cidades
- 24 cidades
- 36 cidades
- 48 cidades

## Entradas dos Cenários
As entradas para os algoritmos foram construídas com base em duas métricas principais que representam as características reais das cidades:

1.Distância

A distância entre as cidades, medida em quilômetros, foi utilizada como uma métrica de custo para avaliar a eficiência das rotas.

2.Tempo

O tempo necessário para se deslocar entre as cidades foi usado como outra métrica para medir a qualidade dos tours.

## Utilização

Para utilizar este projeto, siga os passos abaixo:

1. Clone o repositório em sua máquina local utilizando o seguinte comando:

   ```shell
   git clone https://github.com/beatrizgouveia03/Grafos.git
   ```

2. Navegue até o diretório deste projeto: 

   ```shell
   cd Grafos/Projetos/Traveling_Salesman_Problem/
   ```

3. Compile o projeto de acordo com o método de sua escolha (veja [Métodos de Compilação](#métodos-de-compilação) para mais detalhes).

4. Execute o programa compilado para visualizar os algoritmos de rotas em grafos em execução com seus arquivos de entrada.

## Métodos de Compilação

Este projeto utiliza o CMake como sistema de build, permitindo uma compilação fácil e eficiente do código em C++. Para compilar os algoritmos, siga os passos abaixo:

1. Certifique-se de que o CMake está instalado no seu sistema.

2. Navegue até o diretório do projeto:

   ```shell
   cd Grafos/Projetos/Traveling_Salesman_Problem/
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

Isso criará uma pasta `docs` (ou outro diretório especificado no campo `OUTPUT_DIRECTORY` do arquivo Doxyfile) com os arquivos da documentação gerada. Você pode visualizar a documentação abrindo o arquivo [index.html](/Projetos/Traveling_Salesman_Problem/docs/html/index.html), localizado dentro da subpasta `html`, em seu navegador web.

## Licença

Este projeto está licenciado sob a Licença MIT. Veja o arquivo [LICENSE](/LICENSE.md) para mais detalhes.
