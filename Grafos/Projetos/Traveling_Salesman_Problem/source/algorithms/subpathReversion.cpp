#include "simulation.h"

using namespace sml;

/**
 * @brief Realiza uma busca local em um tour utilizando a estratégia de reversão de subcaminhos
 * 
 * Essa função busca otimizar de forma iterativa o custo de uma viagem revertendo a ordem dos caminhos dos índices i ao j
 * Seja [i, i+1, i+2, i+3, ... , j] um caminho, esta função irá testar o custo de percorrer o caminho [j, j-1, j-2, j-3, ..., i], caso o custo seja menor, o tour é substituido
 * @param tour O tour representado como um vetor de índices das cidades.
 * @param distMatrix A matriz de distâncias que representa os pesos entre as cidades.
 *                   distMatrix[i][j] fornece a distância entre a cidade i e a cidade j.
 * 
 * @return um vetor de inteiros representando o tour otimizado após a busca local.
 */

vector<int> Simulation::subpathReversion(const vector<int>& tour, const vector<vector<double>>& distMatrix) {
	vector<int> currTour = tour;
	double currCost = calculateTourCost(currTour, distMatrix);

	bool improved = true;
	while(improved){
		improved = false;
		for(int i = 0; i < tour.size() - 1; i++){
			for(int j = i + 2; j < tour.size(); j++){
				vector<int> newTour = currTour;
				reverse(newTour.begin() + i, newTour.begin() + j + 1);
				double newCost = calculateTourCost(newTour, distMatrix);
				if(newCost < currCost){
					currTour = newTour;
					currCost = newCost;
					improved = true;
				}
			}
		}
	}

	return currTour;
}
