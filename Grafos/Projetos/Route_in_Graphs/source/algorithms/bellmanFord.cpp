#include "simulation.h"

using namespace sml;

/**!
 * Função que implementa o algoritmo de melhor caminho Bellman-Ford.
 * Todas as distâncias iniciam de INFINITO(no nosso caso, o máximo valor inteiro), exceto o inicial que tem distância 0.
 * Dado um grafo, é realizado o "relaxamento" das arestas, que é a verificação se a distância para um vértice 
 * pode ser menor ou reduzida passando por outro vértice.
 * Por último, é feito mais uma verificação nas arestas, caso exista uma opção de distância melhor
 * então existe um ciclo negativo.
 * 
 * @param inicio Vértice inicial 
 */
void Simulation::bellmanFord(int inicio){
    cout << "Bellman-Ford" << endl;

    Graph g = this->graph; // Variável do graph, apenas atalho para this->graph
    const int INF = numeric_limits<int>::max();  // Define o valor de infinito
    vector<int> dist(g.n, INF); //Distâncias iniciais
    vector<int> predecessor(g.n, -1); // Para armazenar o caminho
    
    //Inicializando 
    dist[inicio - 1] = 0;

    // Relaxação das arestas (n-1 vezes)
    for (int i = 1; i <= g.n - 1; i++) {
        for (int u = 0; u < g.n; u++) {
            for (int v = 0; v < g.n; v++) {
                if (g.adj[u][v] != -1) { // Aresta existe
                    if (dist[u] != INF && dist[u] + g.adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + g.adj[u][v];
                        predecessor[v] = u;
                    }
                }
            }
        }
    }

    // Verificação da existência de ciclos negativos
    for (int u = 0; u < g.n; u++) {
        for (int v = 0; v < g.n; v++) {
            if (g.adj[u][v] != -1) {
                if (dist[u] != INF && dist[u] + g.adj[u][v] < dist[v]) {
                    cout << "Ha um ciclo negativo" << endl;
                    return;
                }
            }
        }
    }

    cout << "Distancias a partir do vertice " << g.dictionary[inicio - 1] << ":" << endl;
    for (int i = 0; i < g.n; i++) {
        cout << g.dictionary[i] << ": " << (dist[i] == INF ? "INF" : to_string(dist[i])) << endl;
    }
};