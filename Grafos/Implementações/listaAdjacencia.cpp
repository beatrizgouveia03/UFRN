/*!
 * Algorithm that represents a graph as an adjacency list
 * @author Beatriz Gouveia
 * @date Oct 20st, 2024
 * @file listaAdjacenciaBia.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

/*!
 * This function reads the file input and based on the reading 
 * fills the adjacency list.
 *
 * @param adjList Address of the map that represents the adjacency list
 * @return A boolean indicating whether the read was successful 
 * (there were no out-of-bounds connections)
 */
bool readGraph(map<int, vi>& adjList){
    int vertices, connections,  x, y;

    cout << "Leitura de vértices e conexões..." << endl;
    
    //Amount of vertices and connections of the matrix
    cin >> vertices >> connections;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << connections << endl;

    for(auto i{1u}; i<=vertices; ++i) adjList[i];

    cout << "Lendo conexões..." << endl;


    while(connections > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        adjList[x].push_back(y);
        adjList[y].push_back(x);

        cout << "Conexão lida com sucesso." << endl;

        connections--;
    }
    
    return true;
}

/*!
 * This function prints the resultant adjacency list on the terminal.
 *
 * @param adjList The map that represents the adjacency list
 */
void printAdjList(map<int, vi> listaAdj){
    cout << endl;
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=listaAdj.size(); ++i){
        cout << i << " ->";
        if(listaAdj[i].size() == 0) cout << " Sem adjacentes";
        else {
            for(auto j{0u}; j < listaAdj[i].size(); ++j){
                cout << " " <<  listaAdj[i][j];
            }
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

/*!
 * Main function
 */
int main(){
    //Initialization of the map that represents the adjacency list
    map<int, vi> AdjList;
    
    if(readGraph(AdjList)) printAdjList(AdjList);

    return 0;
}