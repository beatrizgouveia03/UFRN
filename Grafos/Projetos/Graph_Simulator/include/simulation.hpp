#ifndef SIMULATION_H
#define SIMULATION_H

/*!
 * @file simulation.hpp
 * @author Beatriz Gouveia
 * @date Oct 22nd, 2024
 */


#include <string>
using std::stoi;
using std::string;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;

#include <iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "graph.hpp"
#include "digraph.hpp"
#include "operations.hpp"

namespace sml {
  /// Simulation result machine
  enum simulation_result_e
  {
    OK = 0,     //!< All the entries are as expect.
    ERROR       //!< Some entry is missing something.
  };

  /// Game result machine
  struct SimulationResult
  {
    string msg;                 //!< The message to be printed
    simulation_result_e type;   //!< The simulation result

    SimulationResult(string msg, simulation_result_e state): msg(msg), type(state){};
  };

  class Simulation {
    //== Private Members
    private:
      Graph graph;            //!< The graph of the simulation
      Digraph digraph;        //!< The digraph of the simulation
      Operations operations;  //!< The operations of the simulation

    //=== Public Members
    public:
      Simulation(void);
      void run(void);
      SimulationResult initialize(int argc, char *argv[]);

    //=== Aux methods
    private:
      void pause(void);
      SimulationResult usage(string = "");
      void displayMainMenu(void);      
  };
} // namespace sml

#endif // SIMULATION_H
