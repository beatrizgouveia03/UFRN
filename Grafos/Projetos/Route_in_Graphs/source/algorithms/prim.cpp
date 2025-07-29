#include "simulation.h"
#include <limits>
#include <iostream>
#include <vector>
#include <set>

using namespace sml;
using namespace std;

/**!
 *  @brief Esta função implementa o algoritmo de Prim para encontrar a Árvore Geradora Mínima (AGM) de um grafo.
 * O algoritmo começa em um vértice e vai adicionando as arestas de menor peso que conectam o conjunto Z 
 * de vértices já incluídos à árvore, ao conjunto V de vértices restantes.
 */
void Simulation::prim() {
    const int INF = numeric_limits<int>::max();  // Define o valor de infinito

    int N = this->graph.n;  // Número de vértices no grafo
    vector<vector<int>> D = this->graph.adj;  // Matriz de adjacência como matriz de distância

    // Substituir valores -1 por INF
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (D[i][j] == -1) {
                D[i][j] = INF;
            }
        }
    }

    set<int> Z;  // Conjunto de vértices já incluídos na AGM
    set<int> V;  // Conjunto de vértices restantes

    Z.insert(0);  // Escolhe o vértice inicial (índice 0)
    for (int i = 1; i < N; ++i) {
        V.insert(i);  // Inicializa o conjunto V
    }

    vector<pair<int, int>> TMin;  // Conjunto das arestas da AGM

    // Algoritmo de Prim
    while (Z.size() != N) {  // Enquanto nem todos os vértices forem incluídos
        int minWeight = INF;  // Peso mínimo das arestas
        int j = -1, k = -1;

        // Busca pela aresta de peso mínimo que conecta Z a V
        for (int u : Z) {
            for (int v : V) {
                if (D[u][v] < minWeight) {  // Considera arestas com peso menor
                    minWeight = D[u][v];
                    j = u;
                    k = v;
                }
            }
        }

        if (j != -1 && k != -1) {
            Z.insert(k);  // Adiciona k à AGM
            V.erase(k);   // Remove k de V
            TMin.push_back({j, k});  // Adiciona a aresta (j, k) à AGM
        } else {
            cout << "Erro: Grafo desconexo." << endl;  // Caso o grafo seja desconexo
            return;
        }
    }

    // Exibe as arestas da Árvore Geradora Mínima
    cout << "Arestas da Arvore Geradora Minima:" << endl;
    int totalWeight = 0;  // Peso total da árvore
    for (const auto &edge : TMin) {
        int j = edge.first;
        int k = edge.second;
        cout << j + 1 << " - " << k + 1  // Convertendo para 1-based index
             << " (Peso: " << D[j][k] << ")" << endl;
        totalWeight += D[j][k];  // Atualiza o peso total
    }
    cout << "Peso total da AGM: " << totalWeight << endl;
}
