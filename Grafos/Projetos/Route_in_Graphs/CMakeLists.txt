cmake_minimum_required(VERSION 3.10)

project(rotasEmGrafos VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( Route_in_Graphs
                source/main.cpp
                source/simulation.cpp
                source/algorithms/prim.cpp
                source/algorithms/kruskal.cpp
                source/algorithms/dijkstra.cpp
                source/algorithms/hierholzer.cpp
                source/algorithms/edmondsKarp.cpp
                source/algorithms/bellmanFord.cpp
                source/algorithms/floydWarshall.cpp
                source/algorithms/chuLiuEdmonds.cpp
                source/algorithms/fordFulkerson.cpp 
                source/algorithms/hierholzerPaths.cpp)

set_property(TARGET Route_in_Graphs PROPERTY CXX_STANDARD 20)
