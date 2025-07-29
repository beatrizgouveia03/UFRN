/*!
 * Algorithm that transforms an adjacency list 
 * to an adjacency matrix
 * @author Beatriz Gouveia
 * @date Oct 20st, 2024
 * @file listaAdjParaMatrizAdjBia.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

/*!
 * This function reads an adjancency list of the file input and based 
 * on the reading fills the adjacency matrix.
 *
 * @param adjMatrix Address of the vector that represents the adjacency matrix
 * @return A boolean indicating whether the read was successful 
 * (there were no no out-of-bounds connections)
 */
bool readList(vector<vi>& adjMatrix){
    int x, vertices;

    cout << "Leitura de vértices..." << endl;
    
    //mount of vertices of the matrix
    cin >> vertices;

    cout << "Leitura concluída: Vértices - " << vertices << endl;

    adjMatrix = vector<vi>(vertices, vi(vertices, 0));

    cout << "Lendo lista..." << endl;

    for(auto i{0u}; i<vertices; ++i){
        string str;
        cin >> str;

        if(str == "/0") cout << "Fim de linha" << endl;

        cout << str[0] - '0';

        cout << "Lendo adjacentes do vértice " << i+1 << ": ";


       //while(str != '\0'){
       //    int x = str - '0';

       //    cout << x << " ";

       //    if(x<1||x>vertices){
       //        cout << "Erro: Vértice fora do intervalo." << endl;
       //        return false;
       //    }
       //    
       //    adjMatrix[--x][i] = 1;
       //    adjMatrix[i][x] = 1;

       //    cin >> str;
       //}
       cout << endl;
    }

    return true;
}

/*!
 * This function prints the resultant adjacency matrix on the terminal.
 *
 * @param adjMatrix The vector that represents the adjacency matrix
 */
void printAdjMatrix(vector<vi> adjMatrix){
    cout << endl;
    cout << "Matriz de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

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


    if(readList(adjMatrix)) printAdjMatrix(adjMatrix);

    return 0;
}