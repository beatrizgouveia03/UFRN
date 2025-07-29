#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.h
 * @author Beatriz Gouveia
 * @date Nov 29nd, 2024
 */

#include <string>
using std::stoi;
using std::string;
using std::to_string;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <algorithm>
using std::min;

#include <map>
using std::map;

#include <queue>
using std::queue;

#include <vector>
using std::vector;

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

  /// Enum para representar o tipo de grafo
  enum graph_type_e
  {
    DIRECTED = 0,  //!< Grafo direcionado
    UNDIRECTED     //!< Grafo não direcionado
  };

  /// Estrutura para representar um grafo
  struct Graph
  {
    int n;                          //!< Número de vértices
    graph_type_e type;              //!< Tipo do grafo
    vector<vector<int>> adj;        //!< Matriz de adjacência
    map<int, string> dictionary;    //!< Lista que mantém o nome de cada vértice


    friend ostream &operator<<(ostream &cout, const Graph g)
    {
      int numNodes = g.n;
      map<int, string> dic = g.dictionary;
      vector<vector<int>> adj = g.adj;

      cout << endl;
      cout << "====================================================" << endl;
      cout << "                MATRIZ DE ADJACENCIA                " << endl;
      cout << "====================================================" << endl;
      cout << "  \\  ";
      
      for (int i{0}; i<numNodes; ++i) {
        if(dic[i].length() == size_t(1)) cout << " ";
        cout << dic[i] <<"  ";
      }
      cout << endl;

      cout << "    ";
      for (int i{0}; i<numNodes; ++i) {
        cout << "____";
      }
      cout << endl;

      for(int i{0}; i<numNodes; ++i){
        if(dic[i].length() == 1) cout << " ";
        cout << dic[i] << "| ";
        for(int j{0}; j<numNodes; ++j){
          if(adj[i][j] < 10 && adj[i][j] >= 0) cout << "  ";
          else if(adj[i][j] < 100) cout << " ";
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
      void showMenu(void);
      SimulationResult usage(string = "");
      
      //! Algoritmos de rotas em redes
      void prim(void);
      void kruskal(void);
      void dijkstra(void);
      void hierholzer(void);
      void edmondsKarp(void);
      void floydWarshall(void);
      void fordFulkerson(void);
      void chuLiuEdmonds(void);
      void hierholzerPaths(void);
      void bellmanFord(int inicio);

      //! Algoritmos auxiliares
      bool bfs(vector<int> &parent, vector<vector<int>> residual, int src, int snk);

  };
} // namespace sml

#endif // SIMULATION_H
