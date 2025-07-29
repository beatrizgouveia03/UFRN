# Graphs Simulation Project

Welcome to the Graphs Simulation project! This project provides a collection of graph algorithms implemented in C++. It serves as a comprehensive resource for learning and applying key operations on both graphs and directed graphs (digraphs).

## Table of Contents

1. [Introduction](#introduction)
2. [Algorithms](#algorithms)
3. [Usage](#usage)
4. [Compiling Methods](#compiling-methods)
5. [Contributing](#contributing)
6. [Documentation](#documentation)
7. [License](#license)

## Introduction

This project delves into the implementation of various graph algorithms, serving as a fundamental resource for learning and applying key operations on both graphs and directed graphs (digraphs). Through this project, we explore different methods of graph representation, traversal techniques, and other important graph-related functions.

The exercises cover a wide range of topics, from basic representations like adjacency lists and matrices to more advanced concepts such as Prüffer codes, articulation points, and bipartiteness. Additionally, we implement essential algorithms for digraphs, including conversions between incidence and adjacency matrices and in-depth search techniques.

Each function and algorithm in this project aims to build a strong foundation in graph theory, helping to understand the relationships between vertices and edges, both in theoretical contexts and practical applications. 

## Algorithms
  Here is the adapted text in English:

 - **A. For GRAPHS** (optional functions are marked with the abbreviation "OPT" at the end of the function)
   - [x] (1) Graph representation from the Adjacency List. [Beatriz]
   - [x] (2) Graph representation from the Adjacency Matrix. [Beatriz]
   - [x] (3) Graph representation from the Incidence Matrix. [Beatriz]
   - [x] (4) Conversion from adjacency matrix to adjacency list and vice versa. [Beatriz]
   - [x] (5) Function to calculate the degree of each vertex. [Anny]
   - [x] (6) Function to determine if two vertices are adjacent. [Anny]
   - [x] (7) Function to determine the total number of vertices. [Anny]
   - [x] (8) Function to determine the total number of edges. [Anny]
   - [x] (9) Addition of a new vertex. [Davi]
   - [x] (10) Deletion of an existing vertex. [Davi]
   - [x] (11) Function to determine if a graph is connected or not. [Davi]
   - [ ] (12) Determine if a graph is bipartite (OPT = 1.0 point). [Alisson]
   - [ ] (13) Given a tree representation by adjacency matrix, create an algorithm to generate the Prüffer code and vice versa. (OPT = 1.0 point) [Alisson]
   - [x] (14) Breadth-First Search, starting from a specific vertex. [Davi]
   - [x] (15) Depth-First Search, starting from a specific vertex. [José]
   - [x] (16) Determination of articulations and blocks (biconnectivity), necessarily using the lowpt function. [Alisson]

 - **B. For DIGRAPHS** (optional functions are marked with the abbreviation "OPT" at the end of the function)
   - [x] (17) Digraph representation from the Adjacency Matrix. [José]
   - [x] (18) Digraph representation from the Incidence Matrix. [José]
   - [ ] (19) Determination of the underlying graph (OPT = 0.5 point).
   - [ ] (20) Conversion from incidence matrix to direct star and vice versa (OPT = 0.5 point).
   - [ ] (21) Conversion from adjacency matrix to reverse star and vice versa (OPT = 0.5 point).
   - [x] (22) Depth-First Search, with entry and exit depths for each vertex. [José]
   - [ ] (23) Research and implement an application using depth-first search (OPT = 1.0 point). [José]

## Usage

To use this project, follow the steps below:

1. Clone the repository to your local machine using the command:

   ```shell
   git clone https://github.com/beatrizgouveia03/Grafos.git
   ```

2. Navigate to the project directory:

   ```shell
   cd Grafos/Projetos/Graph_Simulator/
   ```

3. Compile your project according to your preferred method (see [Compiling Methods](#compiling-methods) for more details).

4. Execute the compiled program to see the graphs simulation algorithms in action with the selected source file.

## Compiling Methods

This project uses CMake as the build system, which allows for easy and efficient compilation of the C++ code. To compile the sorting algorithms, follow these steps:

1. Make sure CMake is installed on

 your system.

2. Navigate to the project directory:

   ```shell
   cd Grafos/Projetos/Graph_Simulator/
   ```

3. Create a build directory and generate an Unix Makefile based on the script found on the current level:

   ```shell
   cmake -S . -B build
   ```

4. Compile the project using the generated build files:

   ```shell
   cmake --build build
   ```

6. After successful compilation, you will find the executable file in the build directory, by the name 'Simulation'. Execute the program to see the algorithms in action with the selected entry.

## Contributing

Contributions to this project are welcome! If you'd like to improve an existing algorithm's implementation, add a new sorting algorithm, introduce new scenarios, or fix any issues, please follow these steps:

1. Fork the repository.

2. Create a new branch for your contribution:

   ```shell
   git checkout -b feature/new-algorithm
   ```

3. Make your modifications and additions.

4. Commit your changes:

   ```shell
   git commit -m "Add new algorithm: [Algorithm Name]"
   ```

5. Push your branch:

   ```shell
   git push origin feature/new-algorithm
   ```

6. Open a pull request, describing your changes and the rationale behind them.

## Documentation
The project uses Doxygen for documentation. To generate the documentation, navigate to the project directory and
run the following command:

```shell
doxygen Doxyfile
```
This will create a docs folder (or another directory specified in the OUTPUT_DIRECTORY in Doxyfile) with the generated documentation files. You can view the documentation by opening the [index.html](/docs/html/index.html) file, located inside the html subfolder, in your web browser.

##  License
This project is licensed under the MIT License. See the [LICENSE](/LICENSE.md) file for details.
