#ifndef GRAPH_H
#define GRAPH_H

/*!
 * @file graph.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
*/

#include <map>
using std::map;

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <sstream>
using std::istringstream;

#include <string>
using std::stoi;
using std::string;

#include <utility>
using std::pair;
using std::make_pair;

#include <algorithm>
using std::remove;
namespace sml {
    class Graph {
        //== Private Members
        private:
            int numNodes;                  //!< The amount of vertices of the graph;
            map<int, string> dictionary;   //!< The list that keeps the name of each vertex;
            map<int, vector<int>> adjList; //!< The adjacency list that represents the graph;
            vector<vector<int>> adjMatrix; //!< The adjacency matrix that represents the graph;
            vector<vector<int>> incMatrix; //!< The incidence matrix that represents the graph;

        //== Public Membes
        public:
            Graph(void);
            Graph(int numNodes);
            int getNumNodes(void);
            void printGraph(void);
            void printAdjList(void);
            void printAdjMatrix(void);
            void printIncMatrix(void);
            int getVertexIdx(string v);
            string getVertexName(int idxV);
            map<int, string> getDictionary(void);
            map<int,vector<int>> getAdjList(void);
            vector<vector<int>> getAdjMatrix(void);
            vector<vector<int>> getIncMatrix(void);
            void updateDictionary(map<int, string> dictionary);
            void updateAdjList(map<int, vector<int>> adjList);
            void updateAdjMatrix(vector<vector<int>> adjMatrix);
            void updateIncMatrix(vector<vector<int>> incMatrix);
            void runMenu(void);
    
        //== Aux Methods
        private:
            void pause(void);
            void displayMenu(void);
            void addVertex(string v);
            void addEdge(pair<string, string> vs);
            void removeVertex(string v);
            void removeEdge(pair<string,string> vs);
            string manageVertex(void);
            pair<string,string> manageEdge(void);
    };    
}

#endif //GRAPH_H