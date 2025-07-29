/*!
 * Algorithm that represents a graph as an adjacency matrix
 * @author Beatriz Gouveia
 * @date Oct 20st, 2024
 * @file matrizAdjacenciaBia.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

/*!
 * This function reads the file input and based on the reading 
 * fills the adjacency matrix.
 *
 * @param adjMatrix Address of the vector that represents the adjacency matrix
 * @return A boolean indicating whether the read was successful 
 * (there were no out-of-bounds connections)
 */
bool readGraph(vector<vi>& adjMatrix){
    int vertices, connections, x, y;
    
    cout << "Leitura de vértices e conexões..." << endl;

    //Amount of vertices and connections of the matrix
    cin >> vertices >> connections;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << connections << endl;

    adjMatrix = vector<vi>(vertices, vi(vertices, 0));

    cout << "Lendo conexões..." << endl;

    while(connections > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        adjMatrix[--x][--y] = 1;
        adjMatrix[y][x] = 1;

        cout << "Conexão lida com sucesso." << endl;

        --connections;
    }

    return true;
}

/*!
 * This function prints the resultant adjacency matrix on the terminal.
 *
 * @param adjMatrix The map that represents the adjacency matrix
 */
void printAdjMatrix(vector<vi> adjMatrix){
    cout << endl;
    cout << "Matriz de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";

    for(auto i{0u}; i<adjMatrix.size(); ++i) cout << " " << i+1;
    cout << endl;

    for(auto i{0u}; i<adjMatrix.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<adjMatrix.size(); ++j){
            cout << " " << adjMatrix[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

/*!
 * Main function
 */
int main(){
    //Initialization of the vector that represents the adjacency matrix
    vector<vi> adjMatrix;
    
    if(readGraph(adjMatrix)) printAdjMatrix(adjMatrix);

    return 0;
}