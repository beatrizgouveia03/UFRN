#ifndef OPERATIONS_H
#define OPERATIONS_H

/*!
 * @file operations.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
 */

#include <algorithm>
#include <iomanip>

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <stack>
using std::stack;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::left;
using std::ostream;
using std::setfill;
using std::setw;

#include "graph.hpp"
#include "digraph.hpp"

namespace sml
{
  struct SearchResult
  {
    int numNodes;
    int initialNode;
    vector<int> predecessors;
    vector<bool> visited;
    vector<vector<int>> backEdges;
    map<int, string> dictionary;
    vector<int> lowpt;
    vector<bool> demarcators;
    vector<bool> articulations;

    friend ostream &operator<<(ostream &os, const SearchResult &result)
    {
      map<int, string> dic = result.dictionary;
      int numOfSeparator = 60;
      os << left; // Align to the left

      // Print header
      os << setw(15) << "Node" << setw(15) << "Visited" << setw(15)
         << "Predecessor" << setw(15);

      if (!result.lowpt.empty())
      {
        os << "Lowpt" << setw(15);
        numOfSeparator += 15;
      }
      if (!result.demarcators.empty())
      {
        os << "Demarcators" << setw(15);
        numOfSeparator += 15;
      }
      if (!result.articulations.empty())
      {
        os << "Articulations" << setw(15);
        numOfSeparator += 15;
      }

      os << "Backedges" << '\n';
      // Print separator
      os << setfill('-') << setw(numOfSeparator) << "" << setfill(' ') << '\n';

      // Print each node's information
      for (int i = 1; i <= result.numNodes; ++i)
      {
        os << setw(15) << dic[i - 1]                       // Node number
           << setw(15) << result.visited[i]                // Visited status
           << setw(15) << dic[result.predecessors[i] - 1]; // Predecessor

        if (!result.lowpt.empty())
        {
          os << setw(15) << result.lowpt[i];
        }
        if (!result.demarcators.empty())
        {
          os << setw(15) << result.demarcators[i];
        }
        if (!result.articulations.empty())
        {
          os << setw(15) << result.articulations[i];
        }

        if (!result.backEdges[i].empty())
        {
          // os << setw(30);
          for (const auto &edge : result.backEdges[i])
          {
            os << edge << " ";
          }
        }
        else
        {
          os << setw(30) << "No backedges";
        }
        os << '\n'; // Ensure that each node's info starts on a new line
      }

      return os;
    }
  };

  class Operations
  {
    //== Private Members
  private:
    Graph graph;      //!< A copy of the initial graph
    Digraph digraph;  //!< A copy of the initial digraph

    //== Public Members
  public:
    // Constructors
    Operations();
    Operations(Graph g, Digraph d);

    // Menu
    void runMenu();

    // Update(set) methods
    void updateGraph();
    void updateDigraph();

    //== Aux Members
  private:
    void pause();
    void displayMenu();
    string handleSearch(string v);
    pair<string, string> handleSearch(pair<string, string> v);

    // THE MATH AND SEARCH OPERATIONS FROM GRAPHS
    void adjListToAdjMatrix(Graph g);
    void adjMatrixToAdjList(Graph g);
    void calculateDegrees(Graph g);
    void adjacentsVertex(Graph g, pair<string, string> vs);
    void countVertices(Graph g);
    void countEdges(Graph g);
    void connected(Graph g);
    void bipartite(Graph g);
    void dfs(Graph g, string v);
    void bfs(Graph g, string v);
    void articulationsAndBlocks(Graph g, string v);

    // THE MATH AND SEARCH OPERATIONS FROM DIGRAPHS
    void subjacentGraph(Digraph d);
    void incMatrixToDirectStar(Digraph d);
    void directStarToIncMatrix(/*Dont know*/);
    void adjMatrixToIndirectStar(Digraph d);
    void indirectStarToAdjMatrix(/*Dont know*/);
    void dfs(Digraph d, string v);
    void application();
  };
} // namespace sml

#endif // OPERATIONS_H