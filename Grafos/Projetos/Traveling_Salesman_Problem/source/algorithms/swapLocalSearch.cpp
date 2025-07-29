#include "simulation.h"

using namespace sml;


/**
 * @brief Realiza uma busca local em um tour utilizando a estratégia de troca de vizinhança.
 * 
 * Esta função explora iterativamente a vizinhança de um tour dado, trocando as posições
 * de duas cidades e avaliando o custo do tour resultante. O processo continua até que
 * não sejam encontradas melhorias.
 *
 * @param tour O tour inicial representado como um vetor de índices das cidades.
 * @param distMatrix A matriz de distâncias que representa os pesos entre as cidades.
 *                   distMatrix[i][j] fornece a distância entre a cidade i e a cidade j.
 * 
 * @return Um vetor de inteiros representando o tour otimizado após a busca local.
 */
vector<int> Simulation::swapLocalSearch(const vector<int>& tour, const vector<vector<double>>& distMatrix) {
  vector<int> currTour = tour;
  double currCost = calculateTourCost(currTour, distMatrix);
  
  bool improved = true;
  while (improved) {
    improved = false;
    for (int i = 0; i < tour.size() - 1; i++) {
      for (int j = i + 1; j < tour.size(); j++) {
        vector<int> newTour = currTour;
        int aux = newTour[i];
        newTour[i] = newTour[j];
        newTour[j] = aux;
        double newCost = calculateTourCost(newTour, distMatrix);
        if (newCost < currCost) {
          currTour = newTour;
          currCost = newCost;
          improved = true;
        }
      }
    }
  }
  return currTour;
}


/**
 * @brief Calcula o custo total de um tour.
 * 
 * Esta função calcula o custo total de um tour dado com base na matriz de distâncias.
 * O tour é considerado como um ciclo, então o custo inclui a distância da última cidade
 * de volta para a primeira.
 * 
 * @param tour O tour representado como um vetor de índices das cidades.
 * @param distMatrix A matriz de distâncias que representa os pesos entre as cidades.
 *                   distMatrix[i][j] fornece a distância entre a cidade i e a cidade j.
 * 
 * @return Um valor double representando o custo total do tour.
 */
double Simulation::calculateTourCost(const vector<int>& tour, const vector<vector<double>>& distMatrix) {
  double cost = 0;
  for (int i = 0; i < tour.size() - 1; i++) cost += distMatrix[tour[i]][tour[i + 1]];
  cost += distMatrix[tour[tour.size() - 1]][tour[0]];
  return cost;
}