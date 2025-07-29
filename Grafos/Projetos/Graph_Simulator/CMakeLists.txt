cmake_minimum_required(VERSION 3.10)

project(snaze VERSION 1.0 LANGUAGES CXX)

include_directories ( include )

add_executable( Simulation
                source/main.cpp
                source/graph.cpp
                source/digraph.cpp
                source/operations.cpp
                source/simulation.cpp)
set_property(TARGET Simulation PROPERTY CXX_STANDARD 20)
