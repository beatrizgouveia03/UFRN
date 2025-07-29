#include "simulation.h"
#include <queue>
#include <limits>

using namespace sml;

/**
 * @brief Implementação do algoritmo de Dijkstra para encontrar o caminho mais curto
 * O algoritmo encontra a menor distância entre um vértice inicial e todos os outros vértices do grafo
 * Utiliza uma fila de prioridade para sempre processar o vértice mais próximo do inicial
 * e relaxa as arestas atualizando as distâncias quando encontra caminhos mais curtos
 */
void Simulation::dijkstra(void) {

    //Define infinito como o maior valor possível do tipo int
    const int INF = numeric_limits<int>::max();
    std::string str;
    std::cout << "Digite o vertice inicial: ";
    std::getline(std::cin, str);
    
    //Encontrar o índice do vértice inicial procurando no dicionário de vértices
    size_t start = 0;
    for(const auto& pair : graph.dictionary) {
        if(pair.second == str) {
            start = pair.first;
            break;
        }
    }
    
    //Inicialização dos vetores auxiliares
    std::vector<int> dist(graph.n, INF);
    std::vector<int> parent(graph.n, -1);
    std::vector<bool> visited(graph.n, false);
    
    /**
     * Fila de prioridade que mantém os vértices ordenados pela menor distância
     * Usa pair<int,int> onde:
     * first: distância até o vértice
     * second: índice do vértice
     * greater<> garante que o topo será o vértice com menor distância
     */
    std::priority_queue<
        std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>
    > pq;
    
    //Inicializa o vértice inicial com distância 0
    dist[start] = 0;
    pq.push(std::make_pair(0, start));
    
    //Loop principal do algoritmo
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        
        //Pula vértices já processados
        if(visited[u]) continue;
        visited[u] = true;
        
        //Explora todos os vértices adjacentes ao atual 
        for(size_t v = 0; v < graph.n; v++) {
            if(graph.adj[u][v] == -1) continue;  // Ignora se não há aresta
            
            //Relaxamento: atualiza a distância se encontrou um caminho mais curto
            if(!visited[v] && dist[u] != INF && 
               dist[u] + graph.adj[u][v] < dist[v]) {
                dist[v] = dist[u] + graph.adj[u][v];
                parent[v] = u;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
    
    //Impressão dos resultados para cada vértice
    std::cout << "\nResultados do algoritmo de Dijkstra a partir do vertice " 
              << graph.dictionary[start] << ":\n\n";
         
    for(size_t i = 0; i < graph.n; i++) {
        if(i == start) continue;// Pula o vértice inicial
        

        //Imprime a distância até o vértice atual
        std::cout << "Distancia ate " << graph.dictionary[i] << ": ";
        if(dist[i] == INF) {
            std::cout << "INF (não alcançável)\n";
            continue;
        }
        std::cout << dist[i] << "\n";
        
        //Reconstrói e imprime o caminho usando o vetor de pais
        std::cout << "Caminho: ";
        std::vector<int> path;
        int current = i;
        while(current != -1) {
            path.push_back(current);
            current = parent[current];
        }
        
        //Imprime o caminho na ordem correta (do inicial até o destino)
        for(int j = path.size() - 1; j >= 0; j--) {
            std::cout << graph.dictionary[path[j]];
            if(j > 0) std::cout << " -> ";
        }
        std::cout << "\n\n";
    }
}