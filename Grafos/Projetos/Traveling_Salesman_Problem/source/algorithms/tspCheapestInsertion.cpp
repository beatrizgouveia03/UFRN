#include "simulation.h"

using namespace sml;

pair<double, vector<int>> Simulation::tspCheapestInsertion(int numCities) {
    cout << "Algoritmo da Insercao Mais Barata" << endl;

    const vector<vector<double>> distMatrix = this->graph.adj;
    vector<bool> visitedCities(numCities, false);
    vector<int> finalPath;

    // Inicia com um ciclo de 3 cidades (0, 1, 2)
    finalPath.push_back(0);
    finalPath.push_back(1);
    finalPath.push_back(2);
    visitedCities[0] = visitedCities[1] = visitedCities[2] = true;

  // Enquanto houver cidades não visitadas
  while (finalPath.size() < numCities) {
    double minCostIncrease = numeric_limits<double>::max();
    int cityToInsert = -1;
    size_t insertPosition = 0;

    // Para cada cidade não visitada
    for (int city = 0; city < numCities; ++city) {
      if (!visitedCities[city]) {
        // Para cada posição possível no ciclo atual
        for (size_t i = 0; i < finalPath.size(); ++i) {
          int currentCity = finalPath[i];
          int nextCity = finalPath[(i + 1) % finalPath.size()];

          // Calcula o custo de inserção da cidade entre currentCity e nextCity
          double costIncrease = distMatrix[currentCity][city] + distMatrix[city][nextCity] - distMatrix[currentCity][nextCity];

           // Se o custo de inserção for menor que o mínimo atual, atualiza
          if (costIncrease < minCostIncrease) {
            minCostIncrease = costIncrease;
            cityToInsert = city;
            insertPosition = i + 1;
          }
        }
      }
    }

    // Insere a cidade no ciclo na posição encontrada
    if (cityToInsert != -1) {
      finalPath.insert(finalPath.begin() + insertPosition, cityToInsert);
      visitedCities[cityToInsert] = true;
    } else {
      cerr << "Erro: Nao foi possivel encontrar uma cidade para inserir." << endl;
      break;
   }
  }

  // Calcula o custo total do ciclo final
  double totalCost = 0;
  for (size_t i = 0; i < finalPath.size(); ++i) {
    int currentCity = finalPath[i];
    int nextCity = finalPath[(i + 1) % finalPath.size()];
    totalCost += distMatrix[currentCity][nextCity];
  }

  // Exibe o caminho final e o custo total
  cout << "Caminho final: ";
  for (int v : finalPath) {
    cout << v + 1 << " ";
  }
  cout << endl;
  cout << "Custo total: " << totalCost << endl;

  return pair<double, vector<int>>(totalCost, finalPath);
}