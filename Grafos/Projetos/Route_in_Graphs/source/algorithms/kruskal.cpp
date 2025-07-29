#include "simulation.h"
#include <algorithm>
#include <vector>

using namespace sml;

/**
 * Estruturas auxiliares para implementação do Union-Find
 * MAXN define o tamanho máximo do conjunto de vértices
 * parent[] armazena o pai de cada vértice no conjunto
 * rank_set[] armazena o rank (tamanho) de cada conjunto
 */
#define MAXN 1000
static int parent[MAXN];
static int rank_set[MAXN];

/**
 * @brief Função que inicializa as estruturas do Union-Find
 * Cada elemento começa como seu próprio pai (conjuntos disjuntos)
 * e com rank 1 (tamanho inicial do conjunto)
 */
static void init(size_t n) {
    for(size_t i = 0; i < n; i++) {
        parent[i] = i;
        rank_set[i] = 1;
    }
}

/**
 *  @brief Função Find do Union-Find que encontra o representante (pai) de um conjunto
 * Implementa a otimização de compressão de caminho, que faz todos os nós
 * do caminho apontarem diretamente para a raiz, melhorando performance futura
 */
static size_t find(size_t cur) {
    size_t root = cur;
    
    while(parent[root] != root)
        root = parent[root];
    
    //Path compression
    while(parent[cur] != root) {
        size_t temp = parent[cur];
        parent[cur] = root;
        cur = temp;
    }
    
    return root;
}

/**
 *  @brief Função Union do Union-Find que une dois conjuntos
 * Implementa a otimização union by rank, unindo sempre o conjunto menor ao maior
 * para manter a árvore balanceada
 */
static void join(size_t x, size_t y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    if(rank_set[x] > rank_set[y]) std::swap(x, y);
    rank_set[y] += rank_set[x];
    parent[x] = y;
}

/**
 *  @brief Implementação do algoritmo de Kruskal para encontrar a Árvore Geradora Mínima (MST)
 * O algoritmo ordena as arestas por peso e tenta adicionar cada uma à MST,
 * verificando se não forma ciclo usando Union-Find.
 * Uma MST é uma árvore que conecta todos os vértices do grafo usando o menor peso total possível
 */
void Simulation::kruskal(void) {
    //Converter matriz de adjacência para lista de arestas
    std::vector<std::pair<int, std::pair<size_t, size_t>>> edges;
    
    for(size_t i = 0; i < graph.n; i++) {
        for(size_t j = i + 1; j < graph.n; j++) {
            if(graph.adj[i][j] != -1) {
                edges.push_back({graph.adj[i][j], {i, j}});
            }
        }
    }
    
    //Inicializar estruturas do Union-Find e ordenar arestas por peso
    init(graph.n);
    sort(edges.begin(), edges.end());
    
    //Estruturas para armazenar o resultado (arestas da MST e peso total)
    std::vector<std::pair<int, std::pair<size_t, size_t>>> mst;
    int total_weight = 0;
    
    //Algoritmo principal de Kruskal
    for(const auto& edge : edges) {
        size_t u = edge.second.first;
        size_t v = edge.second.second;
        
        //Verifica se adicionar a aresta não forma ciclo
        if(find(u) != find(v)) {
            join(u, v);
            mst.push_back(edge);
            total_weight += edge.first;
        }
    }
    
    //Imprime as arestas selecionadas e o peso total da MST
    std::cout << "\nArvore Geradora Minima encontrada pelo algoritmo de Kruskal:\n";
    std::cout << "Arestas da AGM:\n";
    for(const auto& edge : mst) {
        std::cout << graph.dictionary[edge.second.first] << " -- " 
                 << graph.dictionary[edge.second.second] << " : "
                 << edge.first << "\n";
    }
    std::cout << "Peso total da AGM: " << total_weight << "\n";
}