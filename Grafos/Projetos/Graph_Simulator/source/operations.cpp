#include "operations.hpp"
#include <queue>

using namespace sml;

/**!
 * Constructor default of the operations class
 */
Operations::Operations()
{
  // Initialize the operations
  this->graph = Graph();
  this->digraph = Digraph();
}

/**!
 * Constructor of the operations class that initializes the
 * graph and the digraph basead on the values passed on the
 * parameters
 * @param g A copy of the graph to be initialized;
 * @param d A copy of the digraph to be initialized;
 */
Operations::Operations(Graph g, Digraph d)
{
  this->graph = g;
  this->digraph = d;
}

string Operations::handleSearch(string v)
{
  string str, x;

  cout << "Insert the index of the vertex to start the search: " << endl;
  getline(cin, str);

  istringstream ss(str);
  getline(ss, x);

  if (x == " ")
  {
    cout << "Insert a valid index." << endl;
    return handleSearch(string());
  }
  else
  {
    return x;
  }
}

pair<string, string> Operations::handleSearch(pair<string, string> v)
{
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
    return handleSearch(pair<string, string>());
  }
  else
  {
    return make_pair(x, y);
  }
}

/**!
 * This function loops around the operations menu calling the
 * functions related to them, until the user chooses to return
 * to the main menu.
 */
void Operations::runMenu()
{
  int opt = -1;
  string str;

  while (opt != 0)
  {
    displayMenu();
    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);
    switch (opt)
    {
    case 0:
      break;
    case 1:
      dfs(graph, handleSearch(string()));
      pause();
      break;
    case 2:
      bfs(graph, handleSearch(string()));
      pause();
      break;
    case 3:
      countEdges(graph);
      pause();
      break;
    case 4:
      countVertices(graph);
      pause();
      break;
    case 5:
      connected(graph);
      pause();
      break;
    case 6:
      bipartite(graph);
      pause();
      break;
    case 7:
      calculateDegrees(graph);
      pause();
      break;
    case 8:
      adjacentsVertex(graph, handleSearch(pair<string, string>()));
      pause();
      break;
    case 9:
      articulationsAndBlocks(graph, handleSearch(string()));
      pause();
      break;
    case 10:
      adjListToAdjMatrix(graph);
      pause();
      break;
    case 11:
      adjMatrixToAdjList(graph);
      pause();
      break;
    case 12:
      dfs(digraph, handleSearch(string()));
      pause();
      break;
    case 13:
      application();
      pause();
      break;
    case 14:
      subjacentGraph(digraph);
      pause();
      break;
    case 15:
      incMatrixToDirectStar(digraph);
      pause();
      break;
    case 16:
      directStarToIncMatrix();
      pause();
      break;
    case 17:
      adjMatrixToIndirectStar(digraph);
      pause();
      break;
    case 18:
      indirectStarToAdjMatrix();
      pause();
      break;
    default:
      cout << "Select a valid option." << endl;
      break;
    }
  }
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Operations::pause()
{
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}

/**!
 * This function displays the digraph menu of the
 * simulation.
 */
void Operations::displayMenu()
{
  cout << "============================================" << endl;
  cout << "               OPERATIONS MENU              " << endl;
  cout << "============================================" << endl;
  cout << "---------------Graph Operations-------------" << endl;
  cout << "1. Run a DFS" << endl;
  cout << "2. Run a BFS" << endl;
  cout << "3. Count the edges" << endl;
  cout << "4. Count the vertices" << endl;
  cout << "5. Check if is connected" << endl;
  cout << "6. Check if is bipartite" << endl;
  cout << "7. Calculate the degrees of the vertex" << endl;
  cout << "8. Check if two vertices are adjacents" << endl;
  cout << "9. Determinate the articulations and the block" << endl;
  cout << "10. Convert adjacency list to an adjacency matrix" << endl;
  cout << "11. Convert adjacency matrix to an adjacency list" << endl;
  cout << "--------------Digraph Operations------------" << endl;
  cout << "12. Run a DFS" << endl;
  cout << "13. Show the application" << endl;
  cout << "14. Determinate the subjacent graph" << endl;
  cout << "15. Convert incidence matrix to a direct star" << endl;
  cout << "16. Convert direct star to an incidence matrix" << endl;
  cout << "17. Convert adjacency matrix to an indirect star" << endl;
  cout << "18. Convert indirect star to an adjacency matrix" << endl;
  cout << "0. Exit to the main menu" << endl;
  cout << "============================================" << endl;
}

/**!
 * This function converts the adjacency list of the graph to an
 * adjacency matrix and displays the matrix resultant in the terminal
 * @param g The graph of the simulation
 */
void Operations::adjListToAdjMatrix(Graph g)
{

  map<int, string> dictionary = g.getDictionary();
  map<int, vector<int>> adjList = g.getAdjList();

  // Initialize the adjacency matrix
  int numNodes = adjList.size();
  vector<vector<int>> adjMatrix = vector(numNodes, vector(numNodes, 0));

  // Run throw the list updating the edges in the matrix
  for (auto it = adjList.begin(); it != adjList.end(); ++it)
  {
    // Check if the vertex has been deleted
    if (it->second[0] == -1)
    {
      for (size_t i{0}; i < numNodes; ++i)
      {
        adjMatrix[(it->first) - 1][i] = -1;
      }
    }
    else
    {
      for (size_t i{0}; i < it->second.size(); ++i)
      {
        adjMatrix[(it->first) - 1][(it->second[i]) - 1] = 1;
      }
    }
  }

  // Create a aux graph o print the sides of the conversion
  Graph aux = Graph(g.getNumNodes());

  aux.updateAdjList(adjList);
  aux.updateAdjMatrix(adjMatrix);
  aux.updateDictionary(dictionary);

  aux.printAdjList();
  aux.printAdjMatrix();
}

/**!
 * This function converts the adjacency matrix of the graph to an
 * adjacency list and displays the list resultant in the terminal
 * @param g The graph of the simulation
 */
void Operations::adjMatrixToAdjList(Graph g)
{
  map<int, string> dictionary = g.getDictionary();
  vector<vector<int>> adjMatrix = g.getAdjMatrix();

  // Initialize the adjacency list
  int numNodes = adjMatrix.size();
  map<int, vector<int>> adjList;

  for (int i(0); i < numNodes; ++i)
  {
    adjList[i];
  }

  // Run throw the matrix updating the edges in the list
  for (int i = 1; i <= numNodes; i++)
  {
    for (int j = 1; j <= numNodes; j++)
    {
      if (j < i)
      {
        continue;
      }
      else if (j > i)
      {
        if (adjMatrix[i - 1][j - 1] == -1)
        {
          adjList[i].push_back(-1);
          adjList[j].push_back(-1);
        }
        else if (adjMatrix[i - 1][j - 1])
        {
          adjList[i].push_back(j);
          adjList[j].push_back(i);
        }
      }
      else
      {
        if (adjMatrix[i - 1][j - 1] == -1)
        {
          adjList[i].push_back(-1);
        }
        else if (adjMatrix[i - 1][j - 1])
        {
          adjList[i].push_back(j);
        }
      }
    }
  }

  // Create a aux graph o print the sides of the conversion
  Graph aux = Graph(g.getNumNodes());

  aux.updateAdjList(adjList);
  aux.updateAdjMatrix(adjMatrix);
  aux.updateDictionary(dictionary);

  aux.printAdjMatrix();
  aux.printAdjList();
}

/**!
 * This function calculates the degree of each vertex and displays
 * on the terminal
 * @param g The graph to be calculated
 */
void Operations::calculateDegrees(Graph g)
{
  // acessa a lista de adjacência que representa o grafo
  auto adjList = g.getAdjList();

  map<int, string> dictionary = g.getDictionary();

  map<int, vector<int>>::iterator it;

  for (it = adjList.begin(); it != adjList.end(); ++it)
  {
    cout << "Vertex " << dictionary[it->first] << " has ";

    int current_vertex_degree = 0;

    for (const int &edge : it->second)
    {
      current_vertex_degree++;
    }

    cout << current_vertex_degree << " degrees" << endl;
  }
}

/**!
 * This function checks if two vertices of the graph are adjacents
 * @param g The graph to be checked
 * @param vs A pair of strings indicating the "names" of the vertices
 */
void Operations::adjacentsVertex(Graph g, pair<string, string> vs)
{
  string vsu = vs.first, vsv = vs.second;
  int u = -1, v = -1;
  map<int, string> dictionary = g.getDictionary();

  for (int i{0}; i < g.getNumNodes(); ++i)
  {
    if (dictionary[i] == vsu)
    {
      u = i + 1;
    }
    else if (dictionary[i] == vsv)
    {
      v = i + 1;
    }
  }

  if (u == -1 || v == -1)
  {
    cout << "One of the vertices does not exist." << endl;
    return;
  }

  const auto &adjList = g.getAdjList();

  auto uAdj = adjList.find(u);
  auto vAdj = adjList.find(v);

  if ((uAdj != adjList.end() && find(uAdj->second.begin(), uAdj->second.end(), v) != uAdj->second.end()) ||
      (vAdj != adjList.end() && find(vAdj->second.begin(), vAdj->second.end(), u) != vAdj->second.end()))
  {
    cout << vsu << " and " << vsv << " are adjacents." << endl;
  }
  else
  {
    cout << vsu << " and " << vsv << " are not adjacents." << endl;
  }
}

/**!
 * This function counts the amount of the vertices of the graph and displays it
 * on the terminal
 * @param g The graph to be calculated
 * @returns The amount of vertices of the graph
 */
void Operations::countVertices(Graph g)
{
  auto adjList = g.getAdjList();

  int totalVertices = adjList.size();

  cout << "The amount of vertices of the graph is " << totalVertices << endl;
}

/**!
 * This function counts the amount of edges of the graph and displays it
 * on the terminal
 * @param g The graph to be calculated
 * @returns The amount of edges of the graph
 */
void Operations::countEdges(Graph g)
{
  auto incMatrix = g.getIncMatrix();

  cout << "The total amount of edges is " << incMatrix.size() << endl;
}

/**!
 * This function checks if the graph is connected and displays the result
 * in the terminal
 * @param g The graph to be checked
 */
void Operations::connected(Graph g){

  auto adjList = g.getAdjList();
  int numNodes = g.getNumNodes();

  int startVertexIdx = -1;
  for (auto it = adjList.begin(); it != adjList.end(); ++it) {
    startVertexIdx = it->first;
    break;
  }

  if (startVertexIdx == -1) {
    cout << "O grafo está vazio." << endl;
    return;
  }

  vector<bool> visited(numNodes + 1, false);

  std::queue<int> q;
  visited[startVertexIdx] = true;
  q.push(startVertexIdx);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    for (int adj : adjList[curr]) {
      if (!visited[adj]) {
        visited[adj] = true;
        q.push(adj);
      }
    }
  }

  bool isConnected = true;
    for (int i = 1; i <= numNodes; ++i) {
      if (!visited[i] && adjList.find(i) != adjList.end()) {
        isConnected = false;
        break;
      }
    }

  if (isConnected) {
    cout << "O grafo é conexo." << endl;
  } 
  else {
    cout << "O grafo é desconexo." << endl;
  }

}

/**!
 * This function checks if the graph is bipartite and displays the result
 * in the terminal
 * @param g The graph to be checked
 */
void Operations::bipartite(Graph g)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function does a Depth-First Search(DFS) in the graph beggining
 *  in the vertex "v" and displays the result in the terminal
 * @param g The graph to be checked
 * @param v The "name" of the initial search vertex
 * @return The search result to be displayed
 */
void Operations::dfs(Graph g, string v)
{
  int idxV = g.getVertexIdx(v) + 1;

  auto numNodes = g.getNumNodes();

  auto adjList = g.getAdjList();

  vector<bool> visited = vector(numNodes + 1, false);
  vector<int> pred = vector(numNodes + 1, -1);
  vector<vector<int>> backEdges(numNodes + 1);
  stack<int> s;

  visited[idxV] = true;
  s.push(idxV);

  while (!s.empty())
  {
    int curr = s.top();
    s.pop();

    for (auto adj : adjList[curr])
    {
      if (!visited[adj])
      {
        visited[adj] = true;
        pred[adj] = curr;
        s.push(adj);
      }
      else if (pred[curr] != adj)
      {
        // the current node (`curr`) has been previously visited
        // but is being visited again since its adjacent to `adj`
        // so we generate a back edge to it

        // back edge from `curr` to `adj`
        // backEdges.push_back({curr, adj});
        backEdges[curr].push_back(adj);
      }
    }
  }

  SearchResult result = SearchResult{
      .numNodes = numNodes,
      .initialNode = idxV,
      .predecessors = pred,
      .visited = visited,
      .backEdges = backEdges,
      .dictionary = g.getDictionary()};

  cout << result;
}

/**!
 * This function does a Breadth-First Search(BFS) in the graph beggining
 *  in the vertex "v" and displays the result in the terminal
 * @param g The graph to be checked
 * @param v The "name" of the initial search vertex
 */
void Operations::bfs(Graph g, string v)
{
  int idxV = g.getVertexIdx(v) + 1;

  auto numNodes = g.getNumNodes();

  auto adjList = g.getAdjList();

  if (idxV == -1)
  {
    cout << "Vertice " << v << " does not exist." << endl;
    return;
  }

  vector<bool> visited(numNodes + 1, false);
  vector<int> pred(numNodes + 1, -1);
  vector<vector<int>> backEdges(numNodes + 1);

  std::queue<int> q;
  visited[idxV] = true;
  q.push(idxV);

  while (!q.empty())
  {
    int curr = q.front();
    q.pop();

    cout << "Visiting vertex " << g.getVertexName(curr - 1) << endl;

    for (int adj : adjList[curr])
    {
      if (!visited[adj])
      {
        visited[adj] = true;
        pred[adj] = curr;
        q.push(adj);
      }
    }
  }

  SearchResult result = SearchResult{
      .numNodes = numNodes,
      .initialNode = idxV,
      .predecessors = pred,
      .visited = visited,
      .backEdges = backEdges,
      .dictionary = g.getDictionary()};

  cout << result;
}

// auxiliary function to calculate minimum between two integers
int min(int a, int b)
{
  return (a < b) ? a : b;
}

// auxiliary function to verify if a subtree have a articulation(used to identify blocks)
bool hasArticulationInSubtree(int node, const SearchResult &result, const map<int, vector<int>> &adjList, vector<bool> articulations)
{
  stack<int> dfsStack;
  vector<bool> visitedSubtree(result.numNodes + 1, false);
  dfsStack.push(node);
  visitedSubtree[node] = true;

  while (!dfsStack.empty())
  {
    int v = dfsStack.top();
    dfsStack.pop();

    // if `v` its a articulation and is not the root node of the subtree
    if (articulations[v] && v != node)
    {
      return true;
    }
    // iterate the elements of subtree
    for (int w : adjList.at(v))
    {
      if (!visitedSubtree[w] && result.predecessors[w] == v)
      {
        visitedSubtree[w] = true;
        dfsStack.push(w);
      }
    }
  }

  return false;
}

// function to identify the blocks according to demarcators and articulations vectors
vector<vector<int>> identifyBlocks(const SearchResult &result, const map<int, vector<int>> &adjList, vector<bool> demarcators, vector<bool> articulations)
{
  vector<vector<int>> blocks;
  vector<bool> visited(result.numNodes + 1, false);

  for (int v = 1; v <= result.numNodes; ++v)
  {
    if (demarcators[v] && !visited[v])
    {
      vector<int> currentBlock;
      stack<int> stack;
      bool hasArticulation = false;

      // verify if the subtree has articulations
      hasArticulation = hasArticulationInSubtree(v, result, adjList, articulations);

      if (!hasArticulation)
      {
        stack.push(v);
        visited[v] = true;

        while (!stack.empty())
        {
          int u = stack.top();
          stack.pop();
          currentBlock.push_back(u);

          // mark u how visited and explore the neighbors
          for (int w : adjList.at(u))
          {
            if (!visited[w] && result.predecessors[w] == u)
            {
              visited[w] = true;
              stack.push(w);
            }
          }
        }
        blocks.push_back(currentBlock);
      }
    }
  }

  return blocks;
}

/**!
 * This function determinates the articulations and the blocks of the graph
 * and displays in the terminal
 * @param g The graph to be checked
 * @param v The vertex to create the tree depth
 */
void Operations::articulationsAndBlocks(Graph g, string v)
{

  int idxV = g.getVertexIdx(v) + 1;
  auto numNodes = g.getNumNodes();
  auto adjList = g.getAdjList();

  // its necessary calculate a dfs search
  vector<bool> visited = vector(numNodes + 1, false);
  vector<int> pred = vector(numNodes + 1, -1);
  vector<vector<int>> backEdges(numNodes + 1);
  vector<int> lowpt = vector(numNodes + 1, -1);
  vector<bool> demarcators = vector(numNodes + 1, false);
  vector<bool> articulations = vector(numNodes + 1, false);
  vector<bool> inStack(numNodes + 1, false);
  vector<int> discoveryTime = vector(numNodes + 1, -1);
  stack<int> q;

  SearchResult dfsResult;

  q.push(idxV);
  visited[idxV] = true;
  inStack[idxV] = true;
  discoveryTime[idxV] = lowpt[idxV] = 1;

  while (!q.empty())
  {
    int v = q.top();
    bool backtracked = true;

    for (int w : adjList[v])
    {
      if (!visited[w])
      {
        // found new node not visited, updates predecessors and continue DFS
        visited[w] = true;
        pred[w] = v;
        discoveryTime[w] = lowpt[w] = w;

        q.push(w);
        inStack[w] = true;
        backtracked = false;
        break;
      }
      else if (w != pred[v] && inStack[w])
      {
        // found backedge, updates lowpt
        backEdges[v].push_back(w);
        lowpt[v] = min(lowpt[v], discoveryTime[w]);
      }
    }

    if (backtracked)
    {
      // backtracking process. Here we updates the lowpt of parent according to backEdges
      q.pop();
      inStack[v] = false;

      int parent = pred[v];
      if (parent != -1)
      {
        // updates lowpt from parent considering the lowpt of the son
        lowpt[parent] = min(lowpt[parent], lowpt[v]);

        // verify conditions of demarcator
        if (lowpt[v] == v || lowpt[v] == parent)
        {
          demarcators[v] = true;
        }
        // verify conditions of articulation
        if (demarcators[v])
        {
          articulations[parent] = true;
        }
      }
    }
  }

  SearchResult result = SearchResult{
      .numNodes = numNodes,
      .initialNode = idxV,
      .predecessors = pred,
      .visited = visited,
      .backEdges = backEdges,
      .dictionary = g.getDictionary(),
      .lowpt = lowpt,
      .demarcators = demarcators,
      .articulations = articulations};

    vector<vector<int>> blocks = identifyBlocks(result, adjList, demarcators, articulations);
  cout << result;
  cout << "Blocos:" << endl;
  for (const auto &block : blocks)
  {
    cout << "{ ";
    for (int v : block)
    {
      cout << v << " ";
    }
    cout << "}" << endl;
  }
}

// THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS

/**!
 * This function determinates the subjacent graph of the digraph
 * @param d The digraph to be used
 */
void Operations::subjacentGraph(Digraph d)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function converts the incidence matrix of the digraph to an
 * direct star and displays the list resultant in the terminal
 * @param adjMatrix The incidence matrix to be converted
 */
void Operations::incMatrixToDirectStar(Digraph d)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function converts the direct star of the digraph to an
 * incidence matrix and displays the list resultant in the terminal
 * @param dirStar The direct star to be converted
 */
void Operations::directStarToIncMatrix(/*Dont know*/)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function converts the adjacency matrix of the digraph to an
 * indirect star and displays the list resultant in the terminal
 * @param adjMatrix The adjacency matrix to be converted
 */
void Operations::adjMatrixToIndirectStar(Digraph d)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function converts the indirect star of the digraph to an
 * adjacency matrix and displays the list resultant in the terminal
 * @param dirStar The indirect star to be converted
 */
void Operations::indirectStarToAdjMatrix(/*Dont know*/)
{
  /*TO-DO*/
  cout << "To be implemented" << endl;
}

/**!
 * This function does a Depth-First Search(DFS) in the digraph beggining
 *  in the vertex "v" and displays the result in the terminal
 * @param d The digraph to be checked
 * @param v The index of the initial search vertex
 */
void Operations::dfs(Digraph d, string v)
{
  int idxV = d.getVertexIdx(v) + 1;

  auto numNodes = d.getNumNodes();

  auto adjList = d.getAdjList();

  vector<bool> visited = vector(numNodes + 1, false);
  vector<int> pred = vector(numNodes + 1, -1);
  vector<vector<int>> backEdges(numNodes + 1);
  stack<int> s;

  visited[idxV] = true;
  s.push(idxV);

  while (!s.empty())
  {
    int curr = s.top();
    s.pop();

    for (auto adj : adjList[curr])
    {
      if (!visited[adj])
      {
        visited[adj] = true;
        pred[adj] = curr;
        s.push(adj);
      }
      else if (pred[curr] != adj)
      {
        // the current node (`curr`) has been previously visited
        // but is being visited again since its adjacent to `adj`
        // so we generate a back edge to it

        // back edge from `curr` to `adj`
        // backEdges.push_back({curr, adj});
        backEdges[curr].push_back(adj);
      }
    }
  }

  SearchResult result = SearchResult{
      .numNodes = numNodes,
      .initialNode = idxV,
      .predecessors = pred,
      .visited = visited,
      .backEdges = backEdges,
      .dictionary = d.getDictionary()};

  cout << result;
}

void Operations::application()
{
  //*TO-DO*/
  cout << "To be implemented" << endl;
}
