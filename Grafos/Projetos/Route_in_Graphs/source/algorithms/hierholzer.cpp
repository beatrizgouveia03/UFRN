#include "simulation.h"

using namespace sml;

/**!
 *  @brief Função que implementa o algoritmo de Hierholzer para identificação de ciclos.
 * Um ciclo eureliano é uma cadeia que inicia em um vértice "v", passa por todas as arestas do grafo
 * apenas 1 vez e finaliza em "v".
 * O algoritmo passa pelas arestas não exploradas de cada vértice e depois adiciona esse vértice(que teve as arestas exploradas)
 * no ciclo(variável cycle).
 */
void Simulation::hierholzer (void){ 
    cout << "Hierholzer" << endl;
    Graph g = this->graph;
    vector<int> cycle;          // Armazena o ciclo euleriano
    stack<int> currentPath;     // Pilha para o caminho atual
    map<int, int> edgeIndex;    // Armazena o índice atual de exploração de arestas para cada vértice
 
    vector<vector<int>> adjList(g.n);

    // Converter matriz de adjacência em lista de adjacência para facilitar o uso
    for (int i = 0; i < g.adj.size(); i++) {
        for (int j = 0; j < g.adj[i].size(); j++) {
            if (g.adj[i][j] != 0) {
                adjList[i].push_back(j);
            }
        }
    }

    // Inicializar os índices de exploração de arestas
    for (int i = 0; i < g.n; i++) {
        edgeIndex[i] = 0;
    }

    // Começar com qualquer vértice que tenha arestas (neste caso, o vértice 4)
    int startVertex = 3;
    currentPath.push(startVertex);

    while (!currentPath.empty()) { 
        int currentVertex = currentPath.top();
        // Se o vértice atual ainda tem arestas não exploradas
        if (edgeIndex[currentVertex] < adjList[currentVertex].size()) {
            int nextVertex = adjList[currentVertex][edgeIndex[currentVertex]];
            edgeIndex[currentVertex]++;
            currentPath.push(nextVertex);
        } else { // Não há mais arestas, "fecha o ciclo" removendo o vértice atual
            cycle.push_back(currentVertex);
            currentPath.pop();
        }
    }

    cout << "Ciclo Euleriano:" << endl;
    for (int vertex : cycle) {
        cout << g.dictionary[vertex] << " "; 
    }
    cout << endl; 
};