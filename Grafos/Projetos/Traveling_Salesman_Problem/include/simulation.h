#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.h
 * @author Beatriz Gouveia
 * @date Jan 19nd, 2025
 */

#include <string>
using std::stoi;
using std::string;
using std::to_string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::min;
using std::reverse;

#include <map>
using std::map;

#include <queue>
using std::queue;

#include <vector>
using std::vector;
using std::reverse;

#include <climits>

#include <exception>
using std::exception;

#include <ostream>
using std::ostream;
using std::operator<<;

#include <queue>
using std::queue;

#include <limits>
using std::numeric_limits;

#include <stack>
using std::stack;

#include <set>
using std::set;

#include <utility>
using std::pair;

#include <chrono>
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::high_resolution_clock;

namespace sml {
  /// Enum para representar o resultado da simulação
  enum simulation_result_e
  {
    OK = 0,     //!< Todas as entradas estão como esperado.
    ERROR       //!< Alguma entrada está faltando ou possui erro.
  };

  /// Estrutura para armazenar o resultado da simulação
  struct SimulationResult
  {
    string msg;                 //!< Mensagem a ser exibida
    simulation_result_e type;   //!< Tipo de resultado da simulação

    SimulationResult(string msg, simulation_result_e state): msg(msg), type(state){};
  };

  /// Estrutura para representar um grafo
  struct Graph
  {
    int n;                          //!< Número de vértices
    vector<vector<double>> adj;     //!< Matriz de adjacência

    friend ostream &operator<<(ostream &cout, const Graph g)
    {
      int numNodes = g.n;
      vector<vector<double>> adj = g.adj;

      cout << endl;
      cout << "====================================================" << endl;
      cout << "                MATRIZ DE ADJACENCIA                " << endl;
      cout << "====================================================" << endl;
      cout << "  \\  ";
      
      for (int i{0}; i<numNodes; ++i) {
        cout << i+1 <<"  ";
      }
      cout << endl;

      cout << "    ";
      for (int i{0}; i<numNodes; ++i) {
        cout << "____";
      }
      cout << endl;

      for(int i{0}; i<numNodes; ++i){
        cout << i+1 << "| ";
        for(int j{0}; j<numNodes; ++j){
          cout << adj[i][j] << " ";
        }
        cout << endl;
      }
      cout << endl;
      cout << "====================================================" << endl;

      return cout;
    }
  };

  class Simulation {
    //== Membros privados
    private:
      Graph graph;            //!< O grafo da simulação

    //=== Membros públicos
    public:
      Simulation(void);
      void run(void);
      SimulationResult initialize(int argc, char *argv[]);

    //=== Métodos auxiliares
    private:
      void pause(void);
      void  showAlgMenu(void); //!< Mostra o menu de algoritmos
      void  showProbMenu(void);  //!< Mostra o menu de problemas
      void runProblem(int problem, int algorithm);
      SimulationResult usage(string = "");
      
      //! Algoritmos do problema do caixeiro viajante
      pair<double, vector<int>> tspGreedy(int numCities);//!< Algoritmo Guloso
      pair<double, vector<int>> tspCheapestInsertion(int numCities); //!< Inserção mais barata 
      pair<double, vector<int>> grasp(int numCities, int localSearch); //!< GRASP
      vector<int> swapLocalSearch(const vector<int>& tour, const vector<vector<double>>& distMatrix); //!< Busca Local 1 (Swap)
      vector<int> subpathReversion(const vector<int>& tour, const vector<vector<double>>& distMatrix); //!< Busca Local 2 (Reversão de Subcaminho)

      //! Funções auxiliares
      double calculateTourCost(const vector<int>& tour, const vector<vector<double>>& distMatrix);
  };
} // namespace sml

#endif // SIMULATION_H
