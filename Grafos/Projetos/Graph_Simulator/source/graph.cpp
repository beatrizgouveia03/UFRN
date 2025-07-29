#include "graph.hpp"


using namespace sml;


/**!
 * Constructor default of the graph class
 */
Graph::Graph(void){/*EMPTY*/}

/**!
 * Constructor of the graph class that initializes the
 * adjacency list and matrix basead on the value passed
 * in the parameter
 * @param numNodes The number of nodes on the graph
 */
Graph::Graph(int numNodes){
    this->numNodes = numNodes;

   // Inicialize the adjancency list
    cout << "Initializing the adjacency list..." << endl;

    for(size_t i{1}; i <= numNodes; ++i){
        adjList[i];
    }
    cout << "Adjacency list initialized succefully" << endl;
    
    //Inicialize the adjacency matrix
    cout << "Initializing the adjacency matrix..." << endl;

    adjMatrix = vector<vector<int>> (numNodes, vector<int>(numNodes, 0));


    cout << "Adjacency matrix initialized succefully" << endl;

}

/**!
 *  This function calls all the printing functions of the graph.
*/ 
void Graph::printGraph(void){
    printAdjList();
    printAdjMatrix();
    printIncMatrix();
}

/**!
 *  This function prints the adjacency list.
*/   
void Graph::printAdjList(void){
    cout << endl;
    cout << "============================================" << endl;
    cout << "               ADJACENCY LIST                " << endl;
    cout << "============================================" << endl;
    for(int i = 0; i < numNodes; i++){
        
        cout << "Adjacency list of node " << dictionary[i] << " : ";
        for(int j = 0; j < adjList[i+1].size(); j++){
            cout << dictionary[adjList[i+1][j]-1] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
 *  This function prints the adjacency matrix.
*/  
void Graph::printAdjMatrix(void){
    cout << endl;
    cout << "============================================" << endl;
    cout << "              ADJACENCY MATRIX              " << endl;
    cout << "============================================" << endl;
    cout << "\\ ";
    for(int i = 0; i < numNodes; i++){
        cout << " " << dictionary[i];
    }
    cout << endl;

    cout << "  ";
    for(int j = 0; j < numNodes; j++){
        cout << "--";
    }
    cout << endl;

    for(int i = 0; i < numNodes; i++){
        cout << dictionary[i] << "| ";
        for(int j = 0; j < numNodes; j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
 *  This function prints the incidence matrix.
*/        
void Graph::printIncMatrix(void){
    cout << endl;
    cout << "============================================" << endl;
    cout << "              INCIDENCE MATRIX              " << endl;
    cout << "============================================" << endl;
    cout << "\\ ";
    for(int i = 0; i < numNodes; i++){
        cout << " " << dictionary[i];
    }
    cout << endl;

    cout << "  ";
    for(int i = 0; i < numNodes; i++){
        cout << "--";
    }
    cout << endl;

    for(int i = 0; i < incMatrix.size(); i++){
        cout << i+1 << "| ";
        for(int j = 0; j < numNodes; j++){
            cout << incMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "============================================" << endl;
}

/**!
    This function returns the numbers of node.
  *
  *
  * @return Number of nodes
 */

int Graph::getNumNodes(void){
    return numNodes;
}

/**!
 *  This function returns the dictionary map.
 *
 *  @return The dictionary list.
*/
map<int, string> Graph::getDictionary(void){
    return dictionary;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency list.
*/
map<int,vector<int>> Graph::getAdjList(void){
    return adjList;
}

/**!
 *  This function returns the adjacency list.
 *
 *  @return The adjacency matrix.
*/
vector<vector<int>> Graph::getAdjMatrix(void){
    return adjMatrix;
}

/**!
 *  This function returns the incidence matrix.
 *
 *  @return The incidence matrix.
*/
vector<vector<int>> Graph::getIncMatrix(void){
    return incMatrix;
}

/**!
 * This function updates the dictionary map by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param dictionary The new version of the dictionary map to be
 * updated
*/
void Graph::updateDictionary(map<int, string> dictionary){
    this->dictionary = dictionary;
}

/**!
 * This function updates the adjacency list by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjList The new version of the adjacency list to be
 * updated
*/
void Graph::updateAdjList(map<int, vector<int>> adjList){
    this->adjList = adjList;
}

/**!
 * This function updates the adjacency matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param adjMatrix The new version of the adjacency matrix to be
 * updated
*/
void Graph::updateAdjMatrix(vector<vector<int>> adjMatrix){
    this->adjMatrix = adjMatrix;
}

/**!
 * This function updates the incidence matrix by replacing the 
 * actual one with the one passed as parameter.
 *
 *  @param incMatrix The new version of the incidence matrix to be
 * updated
*/
void Graph::updateIncMatrix(vector<vector<int>> incMatrix){
    this->incMatrix = incMatrix;
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Graph::pause(void) {
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}

/**!
 * This function collects the "name" of the vertex that is 
 * wanted to be removed/inserted and returns it to the
 * caller.
 * @return A string indication the "name" of the vertex
 */
string Graph::manageVertex(void){
    string str, x;

    cout << "Insert the index of the vertex: " << endl;
    getline(cin, str);
    
    istringstream ss(str);
    getline(ss, x);

    if (x == " ")
    {
        cout << "Insert a valid index." << endl;
        return manageVertex();
    }
    else {
        return x;
    }
}

/**!
 * This function collects the "names" of the vertices of the edge
 * that is wanted to be removed/inserted and returns it to the
 * caller.
 * @return A pair of strings indication the "names" of the vertices
 */
pair<string,string> Graph::manageEdge(void){
    string str, x, y;

    cout << "Insert the index of the first vertex: " << endl;
    getline(cin, str);
    
    istringstream ss(str);
    getline(ss, x);
    
    cout << "Insert the index of the second vertex: " << endl;
    getline(cin, str);
    
    istringstream ss2(str);
    getline(ss2, y);

    if (x == " " || y == " ")
    {
        cout << "Insert a valid index." << endl;
        return manageEdge();
    }
    else {
        return make_pair(x, y);
    }
}


/**!
 * This function loops around the graph menu calling the
 * functions related to them, until the user chooses to return
 * to the main menu.
 */
void Graph::runMenu(void) {
  int opt = -1;
  string str;

  while (opt != 0) {
    displayMenu();
    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);
    switch (opt) {
        case 0:
            break;
        case 1:
            addEdge(manageEdge());
            pause();
            break;
        case 2:
            addVertex(manageVertex());
            pause();
            break;
        case 3:
            removeEdge(manageEdge());
            pause();
            break;
        case 4:
            removeVertex(manageVertex());
            pause();
            break;
        case 5:
            printAdjList();
            pause();
            break;
        case 6:
            printAdjMatrix();
            pause();
            break;
        case 7:
            printIncMatrix();
            pause();
            break;
        default:
            cout << "Select a valid option." << endl;
        break;
    }
  }  
}

/**!
 * This function displays the graph menu of the
 * simulation.
 */
void Graph::displayMenu(void) {
  cout << "============================================" << endl;
  cout << "               GRAPH MENU                 " << endl;
  cout << "============================================" << endl;
  cout << "1. Add edge" << endl;
  cout << "2. Add vertex" << endl;
  cout << "3. Remove edge" << endl;
  cout << "4. Remove vertex" << endl;
  cout << "5. Display as adjacency list" << endl;
  cout << "6. Display as adjacency matrix" << endl;
  cout << "7. Display as incidence matrix" << endl;
  cout << "0. Exit to the main menu" << endl;
  cout << "============================================" << endl;
}

/**!
 * This function adds a new vertex to the graph.
 * @param v The "name" of the vertex to be added
*/
void Graph::addVertex(string v) {
    int idxV = getVertexIdx(v);

    if (idxV != -1 && adjMatrix[idxV][0] != -1 ) {
        cout << "Vertex " << v << " already exists." << endl;
        return;
    }

    if(idxV == -1){
        adjList[idxV]; 

        for (auto &row : adjMatrix) {
            row.push_back(0); 
        }
        adjMatrix.push_back(vector<int>(numNodes + 1, 0)); 

        for (auto &row : incMatrix) {
            row.push_back(0); 
        }

        dictionary[numNodes] = v;
        numNodes++;
    } else{
        adjList[idxV+1].clear();
        for(int i{0}; i<numNodes; ++i){
            adjMatrix[idxV][i] = 0;
            adjMatrix[i][idxV] = 0;
        }
    }

    cout << "Vertex " << v << " added successfully." << endl;

    printGraph();
}


/**!
 * This function adds a new edge to the graph.
 * @param vs A pair of strings representing the "names"
 * of the vertices to be connected
*/
void Graph::addEdge(pair<string,string> vs){
    int idxV = getVertexIdx(vs.first), idxU = getVertexIdx(vs.second);

    if (idxV == -1 || idxU == -1) {
        cout << "One of the vertices does not exist." << endl;
        return;
    }

    if(adjMatrix[idxV][idxU] == 1){
        cout << "Edge already exists." << endl;
        return;
    }

    int idx = incMatrix.size();

    adjList[idxV+1].push_back(idxU+1);
    adjList[idxU+1].push_back(idxV+1);

    adjMatrix[idxV][idxU] = 1;
    adjMatrix[idxU][idxV] = 1;

    incMatrix.push_back(vector<int>(idx, 0));
    incMatrix[idx][idxV] = 1;
    incMatrix[idx][idxU] = 1;

   cout << "Edge added sucessfully on the graph." << endl;

   printGraph();
}

/**!
 * This function removes a vertex to the graph along with its edges
 * @param v The "name" of the vertex to be removed
*/
void Graph::removeVertex(string v) {
    int idxV = getVertexIdx(v);

    if (idxV == -1) {
        cout << "Vertex " << v << " does not exist." << endl;
        return;
    }


    for(int i{0}; i<numNodes; ++i){
        //Removed edges from de adjList
        auto &aux = adjList[i];
        aux.erase(remove(aux.begin(), aux.end(), idxV+1), aux.end());

        //Remove the edge from the adjMatrix
        adjMatrix[idxV][i] = -1;
        adjMatrix[i][idxV] = -1;
    }
    adjList[idxV+1] = {0};

   for(int i{0}; i<incMatrix.size();++i){
        if(incMatrix[i][idxV] == 1){
            incMatrix.erase(incMatrix.begin()+i);
            i--;
        }
   }
   
    dictionary[-1] = "Deleted";
    
    cout << "Vertex " << v << " removed successfully from the graph." << endl;

    printGraph();
}

/**!
 * This function removes an edge to the graph.
 * @param vs  A pair of strings representing the "names"
 * of the vertices to be disconnected
*/
void Graph::removeEdge(pair<string,string> vs){
    int idxV = getVertexIdx(vs.first), idxU = getVertexIdx(vs.second);
    for(int i{0}; i<numNodes; ++i){
        if(dictionary[i] == vs.first){
            idxV = i;
        } 
        if(dictionary[i] == vs.second){
            idxU = i;
        }
    }

    if (idxV == -1 || idxU == -1) {
        cout << "One of the vertices does not exist." << endl;
        return;
    }

    auto &aux = adjList[idxV+1];
    auto &aux2 = adjList[idxU+1];

    aux.erase(remove(aux.begin(), aux.end(), idxU+1), aux.end());
    aux2.erase(remove(aux2.begin(), aux.end(), idxV+1), aux.end());

    adjMatrix[idxV][idxU] = 0;
    adjMatrix[idxU][idxV] = 0;

    for(int i{0}; i<incMatrix.size();++i){
      if(incMatrix[i][idxV] == 1 && incMatrix[i][idxU] == 1){
          incMatrix.erase(incMatrix.begin()+i);
          i--;
      }
   }

   cout << "Edge removed sucessfully from the graph." << endl;

   printGraph();
}

/**!
 * This function locates on the dictionary of the graph
 * the vertex with the index passed as argument and returns its name.
 * @param idxV The index of the vertex to be located
*/
string Graph::getVertexName(int idxV){
    if(idxV < numNodes){
        return dictionary[idxV];
    } else{
        return " ";
    }
}


/**!
 * This function locates on the dictionary of the graph
 * the vertex with the name  passed as argument and returns its index.
 * @param v The "name" of the vertex to be located
*/
int Graph::getVertexIdx(string v){
    int idxV = -1;

    for(int i{0}; i<numNodes; ++i){
        if(dictionary[i] == v){
            idxV = i;
            break;
        }
    }

    return idxV;
}
