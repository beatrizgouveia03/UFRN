#include "simulation.h"

using namespace sml;

/**!
 *  @brief Esta função é uma implementação do algoritmo de Hierholzer
 * para encontrar caminhos eulerianos em um grafo direcionado.
 * 
 */
void Simulation::hierholzerPaths (void){
    int n = this->graph.n;                     //!< Número de vértices
    vector<vector<int>> aux = this->graph.adj; //!< Matriz auxilia
    vector<int> in(n, 0), out(n, 0);           //!< Vetores de graus de entrada e saída

    // Calcular graus de entrada e saída
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            (aux[i][j] > 0) ? out[i]++, in[j]++ : 0;
        }   
    }
    
    // Calcular graus de cada vértice
    vector<int> degrees(n, 0);                  //!< Vetor de graus
    for (int i = 0; i < n; i++) {
        degrees[i] = out[i] - in[i];
    }

    // Printar tabela de graus
    cout << "Tabela de graus: " << endl;
    for(auto i{0}; i<n; ++i){
        cout << "Vértice" << i+1 << " : " << degrees[i] << endl; 
    }


    // Verificar a condição de existência de um caminho euleriano em um digrafo
    int start = 0, end = n - 1; // Vértices de início e fim (1 e 19)

    if (degrees[start] != 1 || degrees[end] != -1) {
        cout << "Nao ha caminho euleriano: grau de origem ou destino inválido" << endl;
        return;
    }

    for (int i = 1; i < n-1; i++) {
        if (degrees[i]%2 != 0) {
            cout << "Nao ha caminho euleriano: grau de vértice interno impar." << endl;
            break;
        }
    }

    // Inicializar pilha para armazenar caminho euleriano
    vector<int> eulerianPath;            //!< Vetor para armazenar o caminho euleriano
    stack<int> currentPath;              //!< Pilha para armazenar o caminho atual

    //1. Escolher o vértice inicial v de G
    int v = 0;                                  //!< Vértice inicial
    currentPath.push(v);                        //!< Adiciona o vértice inicial ao caminho em construção

    //2. Construir uma cadeia fechada C, a partir de v, percorrendo as arestas de G
    //aleatoriamente.
    while (!currentPath.empty()) {
        bool flag = false;
        int currVertex = currentPath.top();  //!< Vértice atual

        for (int i = 0; i < n; i++) {
            if (aux[currVertex][i] >= 0) {
                flag = true;
                // Adicionar a aresta ao caminho em construção
                currentPath.push(i);
                // Remover a aresta do grafo
                aux[currVertex][i] = -1;
                // Atualizar os graus
                degrees[currVertex]--;
                degrees[i]++;
                break;
            }
        }
        if (!flag) {
            //3. Remover de G as arestas de C
            eulerianPath.push_back(currVertex);
            currentPath.pop();
            break;
        }
    }

    //4. Enquanto (M ≠ Ø) Fazer
    while (true) {
        bool flag = false;

        //5. Escolher v tal que d(v) > 0 e v ∈ C
        for (int i = 0; i < n; i++) {
            if (degrees[i] > 0) {
                currentPath.push(i);
                flag = true;
                break;
            }
        }
        if (!flag) {
            break;
        }

        //6. Construir uma cadeia fechada H, a partir de v, percorrendo as arestas de G
        vector<int> temp;
        temp.push_back(currentPath.top());

        while (true) {
            bool flag = false;
            int currVertex = currentPath.top();  //!< Vértice atual

            for (int i = 0; i < n; i++) {
                if (aux[currVertex][i] >= 0) {
                    flag = true;
                    // Adicionar a aresta ao caminho em construção
                    currentPath.push(i);
                    // Remover a aresta do grafo
                    aux[currVertex][i] = -1;
                    // Atualizar os graus
                    degrees[currVertex]--;
                    degrees[i]++;
                    break;
                }
            }
            if (!flag) {
                temp.push_back(currVertex);
                currentPath.pop();
                break;
            }
        }

        //7. Remover de G as arestas de H
        // Já removidas no passo 6

        //8. C ← H ∪ C
        auto it = find(eulerianPath.begin(), eulerianPath.end(), v);
        if(it != eulerianPath.end()){
            eulerianPath.insert(it+1, temp.begin(), temp.end());
        }
       
        //9. H ← Ø
    }   
    //10. Fim_do_enquanto

    //11. Imprimir C
    for (int i = 0; i < eulerianPath.size(); i++) {
        cout << eulerianPath[i] + 1 << " ";
    };
}   

