#include "simulation.h" 
#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <string>

using namespace sml;

/**!
 *  @brief Esta função implementa o algoritmo de Floyd-Warshall para encontrar as distâncias mínimas entre todos os pares de vértices
 * de um grafo ponderado. O algoritmo atualiza a matriz de distâncias e a matriz de predecessores para reconstrução de caminhos.
 */
void Simulation::floydWarshall() {
    const int INF = numeric_limits<int>::max();  // Define o valor de infinito

    int n = this->graph.n;  // Número de vértices no grafo
    vector<vector<int>> adj = this->graph.adj;  // Matriz de adjacência
    vector<vector<int>> dist(n, vector<int>(n, INF));  // Matriz de distâncias
    vector<vector<int>> pred(n, vector<int>(n, -1));   // Matriz de predecessores
    map<int, string> dic = this->graph.dictionary;    // Lista que mantém o nome de cada vértice

    // Inicializa as distâncias e os predecessores
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj[i][j] != -1) {
                dist[i][j] = adj[i][j];
                pred[i][j] = i; // Inicializa o predecessor
            }
            if (i == j) {
                dist[i][j] = 0;  // A distância para si mesmo é 0
                pred[i][j] = i;  // Predecessor de si mesmo é o próprio vértice
            }
        }
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];  // Atualiza o predecessor
                }
            }
        }
    }

    // Solicita ao usuário o vértice inicial para exibir as distâncias
    int start;
    cout << "Digite o vertice inicial: ";
    cin >> start;

    start -= 1; 

    if (start < 0 || start >= n) {
        cout << "Erro: vértice inválido!" << endl;
        return;
    }

    // Exibe as distâncias a partir do vértice inicial
    cout << "Floyd-Warshall" << endl;
    cout << "Distancias a partir do vertice " << dic[start] << ":" << endl;

    for (int i = 0; i < n; ++i) {
        cout << (i + 1) << ": ";
        if (dist[start][i] == INF) {
            cout << "INF" << endl;  // Infinito quando não alcançavel
        } else {
            cout << "Distancia: " << dist[start][i] << "/ Predecessor: " << dic[pred[start][i]] << endl;  
        }
    }
}
