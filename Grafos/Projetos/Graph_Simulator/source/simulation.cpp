#include "simulation.hpp"

using namespace sml;


/**!
 * Constructor default of the simulation class
 */
Simulation::Simulation(void) {
  // Initialize the simulation
  this->graph = Graph();
  this->digraph = Digraph();
  this->operations = Operations();
}

/**!
 * This function waits for any entry from the terminal to end.
 */
void Simulation::pause(void){
  cout << "To return to the main menu, press Enter...";
  cin.get(); // Waits an entry
  cout << endl;
}

/**!
 * This function displays the main menu of the
 * simulation.
 */
void Simulation::displayMainMenu(void) {
  cout << "============================================" << endl;
  cout << "                MAIN MENU                   " << endl;
  cout << "============================================" << endl;
  cout << "1. Graph options" << endl;
  cout << "2. Digraph options" << endl;
  cout << "3. Operations options" << endl;
  cout << "0. Exit the simulation" << endl;
  cout << "============================================" << endl;
}


/**!
 * This function loops around the main menu calling the
 * functions related to them, until the user chooses to end the program.
 */
void Simulation::run(void) {
  int opt = -1;
  string str;

  cout << "Initializing simulation..." << endl;

  while (opt != 0) {
    displayMainMenu();

    cout << "Enter your option: " << endl;
    getline(cin, str);
    opt = stoi(str);

    switch (opt) {
      case 0:
        break;
      case 1:
        graph.runMenu();
        break;
      case 2:
        digraph.runMenu();
        break;
      case 3:
        operations.runMenu();
        break;
      default:
        break;
      }
  }
}

/**!
 *  This function initializes the simulation by reading the input
 * file and creating representations of the graph as an adjancency
 *  list, as an adjacency matrix and as an incidence matrix.
 *
 * @param argc An integer indicating the amount of arguments passed on the
 * terminal
 * @param argv The list of the arguments passed on the terminal
 * @return  A struct indicating if was successful the initialization
 */
SimulationResult Simulation::initialize(int argc, char *argv[]) {
  // Initialize the simulation
  // Process command line arguments
  if (argc <= 1) {
    return usage("Error: Missing filename");
  } else {
    string filename = argv[1];
    ifstream file(filename);

    cout << "Initializing the simulation..." << endl;

    if (!file.is_open()) {
      return usage("Error: unable to open file");
    } else {

      // Read the graph from the file
      string v1, v2;
      int numNodes, numConnection = 0;

        string line;
        char trash;

        cout << "Reading number of nodes..." << endl;

        file >> numNodes;

      cout << "Numbers of nodes read: " << numNodes << endl;

      this->graph = Graph(numNodes);
      this->digraph = Digraph(numNodes);

      map<int, string> dictionary = graph.getDictionary();
      map<int, vector<int>> adjList = graph.getAdjList();
      vector<vector<int>> adjMatrix = graph.getAdjMatrix();
      vector<vector<int>> incMatrix = graph.getIncMatrix();

      map<int, vector<int>> diAdjList = digraph.getAdjList();
      vector<vector<int>> diAdjMatrix = digraph.getAdjMatrix();

      // Read the connections from the file
      while (getline(file, line)) {
        if (line == string())
          continue;

        istringstream ss(line);
        getline(ss, v1, ',');
        getline(ss, v2);


        cout << "Reading connection " << v1 << " " << v2 << endl;
        
        int x = -1, y = -1;

        //Update the dictionary
        for(auto i{0}; i<dictionary.size();++i){
          if(dictionary[i] == v1){
            x = i;
          }
          else if(dictionary[i] == v2){
            y = i;
          }
        }
        
        if(x == -1){
          x = dictionary.size();
          dictionary[x] = v1;
        }
        cout << x << " " << dictionary[x] << endl;
        
        if(y == -1){
          y = dictionary.size();
          dictionary[y] = v2;
        }
        cout << y << " " << dictionary[y] << endl;

        if (dictionary.size() > numNodes) {
          return usage("Error: Node out-of-index");
        }

        // Update the adjacency list
        adjList[x+1].push_back(y+1);
        adjList[y+1].push_back(x+1);
				
				diAdjList[x+1].push_back(y+1);

        cout << "Sucessfully addded connection in the adjacency list" << endl;

        // Update the adjancency matrix
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;

				diAdjMatrix[x][y] = 1;

        cout << "Sucessfully addded connection in the adjacency matrix" << endl;

        // Update the incidence matrix
        incMatrix.push_back(vector<int>(numNodes, 0));

        incMatrix[numConnection][x] = 1;
        incMatrix[numConnection][y] = 1;

        cout << "Sucessfully addded connection in the incidence matrix" << endl;

        numConnection++;
      }
      cout << "Sucessfully read all connections from the file" << endl << endl;

      graph.updateAdjList(adjList);
      graph.updateAdjMatrix(adjMatrix);
      graph.updateIncMatrix(incMatrix);
      graph.updateDictionary(dictionary);


      digraph.updateAdjList(diAdjList);
      digraph.updateAdjMatrix(diAdjMatrix);
      digraph.updateDictionary(dictionary);

      operations = Operations(graph, digraph);

      cout << "Sucessfully initialized" << endl;

      return SimulationResult("", simulation_result_e(0));
    }
  }
}

/**!
 *  This function shows in the terminal the usage options.
 *
 * @param message The usage error description message to be display 
 * @return  A struct indicating that the reading failed and the error message
 */
SimulationResult Simulation::usage(string message){
  if(message == "")
  {
    string usage = ">>> Usage: graph <input_entry_file>";

    return SimulationResult(usage, simulation_result_e(1));
  }

  return SimulationResult(">>> "+ message + "\n", simulation_result_e(1));
}
