#include "simulation.h"

using namespace sml;


/**!
 *  @brief Esta função é uma implementação do algoritmo de Edmonds-Karp
 * de fluxo em redes. Dado um grafo, ele determina qual o fluxo 
 * máximo possível,se utilizando de uma busca em largura(bfs) 
 * para achar o menor caminho entre a origem e o destino.
 * 
 */
void Simulation::edmondsKarp (void){
    vector<int> parent(this->graph.n);    //!< Lista auxiliar para recuperar o caminho achado pela BFS
    int source = 0, sink = this->graph.n - 1; //!< Índices do nó origem e do nó destino.
    vector<vector<int>> residual = this->graph.adj; //!< Matriz residual

    Graph aux;
    aux.n = this->graph.n;
    aux.dictionary = this->graph.dictionary;

    int maxFlow = 0, count = 0;

    //Enquanto houver caminho entre a origem e o destino
    while(bfs(parent, residual, source, sink)){
        const int INF = numeric_limits<int>::max();  // Define o valor de infinito
        int pathFlow = INF;
        int s = sink;

        //Determina o gargalo desse caminho
        while(s != source){
            int p = parent[s];
            pathFlow = min(pathFlow, residual[p][s]); 
            s = p; 
        }

        //Atualiza a matriz residual de acordo com o gargalo
        for(int i{sink}; i!=source; i = parent[i]){
            residual[parent[i]][i] -= pathFlow;
            residual[i][parent[i]] += pathFlow;
        }

        //Soma ao fluxo total o fluxo máximo do caminho achado
        maxFlow += pathFlow;

        aux.adj = residual;
        cout << "---------- " << ++count << "a PASSAGEM: (FLUXO RESTANTE) ------------" << endl;
        cout << aux << endl;
        cout << "FLUXO MAXIMO DO CAMINHO: " << pathFlow << endl<< endl;
    }

    cout << "====================================================" << endl;
    cout << endl;
    cout << "FLUXO MAXIMO DO GRAFO: " << maxFlow << endl;
    cout << endl;
    cout << "====================================================" << endl;

    return;
};

/**!
 *  @brief Função auxiliar do algoritmo de Edmonds-Karp.
 * Implementação do algoritmo de busca em largura usada para determinar
 * o menor caminho entre a origem e o destino de um grafo, através de 
 * sua matriz de adjacência, caso exista, e atualizar um vetor de nós-pais
 * para a futura reconstrução do caminho determinado.
 * Ela retorna um booleano indicando se a busca foi sucedida.
 * 
 * @param parent Endereço do vetor de nós-pais a ser atualizado
 * @param residual Matriz residual do grafo
 * @param src Ìndice do nó de origem do grafo
 * @param snk Ìndice do nó de destino do grafo
 * @return Um booleano indicando se foi possível achar um caminho(TRUE) ou não(FALSE)
 */
bool Simulation::bfs(vector<int> &parent, vector<vector<int>> residual, int src, int snk){
    size_t n = residual.size();
    vector<bool> visited(n, false); //!< Vetor que indica quais nós foram visitados
    queue<int> q;   //!< Fila de nós a serem visitados
    q.push(src);
    visited[src] = true;

    //Enquanto houver nó a ser visitado
    while(!q.empty()){
        //Recuperar o nó na frente da fila
        int f = q.front();
        q.pop();

        //Visitar todos os nós-filhos desse nó e adicioná-los na fila
        for(int i{0}; i<n; ++i){
            if(!visited[i] && residual[f][i] > 0){
                q.push(i);
                visited[i] = true;
                parent[i] = f;

                //Caso o nó visitado seja o destino, retornar true
                if(i == snk) return true;
            }
        }

    }

    return false;

}