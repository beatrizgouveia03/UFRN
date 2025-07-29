/*!
 * Algorithm that represents a graph as an incidence matrix
 * @author Beatriz Gouveia
 * @date Oct 20st, 2024
 * @file matrizIncidenciaBia.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

/*!
 * This function reads the file input and based on the reading 
 * fills the incidence matrix.
 *
 * @param incMatrix Address of the vector that represents the incidence matrix
 * @return A boolean indicating whether the read was successful 
 * (there were no out-of-bounds connections)
 */
bool readGraph(vector<vi>& incMatrix){
    int vertices, connections, x, y;
    
    cout << "Leitura de vértices e conexões..." << endl;

    //Amount of vertices and connections of the matrix
    cin >> vertices >> connections;

    cout << "Leitura concluída: Vértices - " << vertices << ", Conexões - " << connections << endl;

    incMatrix = vector<vi>(connections, vi(vertices, 0));

    cout << "Lendo conexões..." << endl;

    int cnt = 0;

    while(connections > 0){
        cin >> x >> y;

        cout << "Conexão lida: " << x << " " << y << endl;

        if(x<1||x>vertices||y<1||y>vertices){
            cout << "Erro: Vértice fora do intervalo." << endl;
            return false;
        }

        incMatrix[cnt][--x] = 1;
        incMatrix[cnt][--y] = 1;

        cnt++; connections--;
    }

    return true;
}

/*!
 * This function prints the resultant incidence matrix on the terminal.
 *
 * @param adjMatrix The map that represents the incidence matrix
 */
void printIncMatrix(vector<vi> incMatrix){
    cout << endl;
    cout << "Matriz de Incidência resultante: " << endl; 
    cout << "---------------------------------" << endl;
    cout << " ";
    
    for(auto i{0u}; i<incMatrix[0].size(); ++i) cout << " "<< i+1;
    cout << endl;

    for(auto i{0u}; i<incMatrix.size(); ++i){
        cout <<i+1;
        for(auto j{0u}; j<incMatrix[i].size(); ++j){
            cout << " " << incMatrix[i][j];
        }

        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

/*!
 * Main function
 */
int main(){
    //Initialization of the vector that represents the incidence matrix
    vector<vi> incMatrix;

    if(readGraph(incMatrix)) printIncMatrix(incMatrix);

    return 0;
}