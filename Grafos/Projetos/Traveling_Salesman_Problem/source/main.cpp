/**!
 *  Este programa implementa os algoritmos de rotas em grafos.
 *
 *  @author Beatriz Gouveia
 *
 *  Para compilar: use o script do CMake.
*/

#include <iostream>

#include "simulation.h"

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
