/*!
 * Algorithm that transforms an adjacency matrix 
 * to an adjacency list
 * @author Beatriz Gouveia
 * @date Oct 20st, 2024
 * @file matrizAdjParaListaAdjBia.cpp
 */

#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

/*!
 * This function reads an adjancency matrix of the file input and based 
 * on the reading fills the adjacency list.
 *
 * @param adjList Address of the map that represents the adjacency list
 * @return A boolean indicating whether the read was successful 
 * (there were no unexpected values)
 */
bool readMatrix(map<int, vi>& adjList){
    int x, vertices;

    cout << "Leitura de vértices..." << endl;
    
    //mount of vertices of the matrix
    cin >> vertices;

    cout << "Leitura concluída: Vértices - " << vertices << endl;

    for(auto i{1u}; i<=vertices; ++i) adjList[i];

    cout << "Lendo matriz..." << endl;

    for(auto i{0u}; i<vertices; ++i){
        for (auto j(0u); j<vertices;++j){
            cin >> x;

            cout << x << " ";

            if(x!=0 && x != 1){
                cout << "Erro: Valor inválido." << endl;
                return false;
            }


            if(x && j >= i){
                if(i == j) {
                    adjList[i+1].push_back(j+1);
                } else {                
                    adjList[i+1].push_back(j+1);
                    adjList[j+1].push_back(i+1);
                }
            }
        }
        cout << endl;
    }

    return true;
}

/*!
 * This function prints the resultant adjacency list on the terminal.
 *
 * @param adjList The map that represents the adjacency list
 */
void printAdjList(map<int, vi> adjList){
    cout << endl;
    cout << "Lista de Adjacência resultante: " << endl; 
    cout << "---------------------------------" << endl;

    for(auto i{1u}; i<=adjList.size(); ++i){
        cout << i << " ->";
        for(auto j{adjList[i].begin()}; j != adjList[i].end(); ++j){
            cout << " " <<  *j;
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
    map<int, vi> adjList;


    if(readMatrix(adjList)) printAdjList(adjList);

    return 0;
}