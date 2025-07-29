/**!
 *  This program implements the Graphs Simulation.
 *
 *  @author Beatriz Gouveia
 *
 *  To compile: use cmake script.
*/

#include <iostream>

#include "simulation.hpp"

int main(int argc, char *argv[]) {
    sml::Simulation simulation;

    auto result = simulation.initialize(argc, argv);
    if(result.type == sml::simulation_result_e::ERROR){
      cerr << result.msg << "\n";
      return EXIT_FAILURE;
    }
    
    simulation.run();

  return EXIT_SUCCESS;
}
