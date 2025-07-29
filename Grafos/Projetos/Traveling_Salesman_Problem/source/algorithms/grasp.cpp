#include "simulation.h"
using namespace sml;


/**
 * Implementa o algoritmo GRASP para encontrar uma solução aproximada para o problema do caixeiro-viajante (TSP).
 * O método consiste em múltiplas iterações, onde cada iteração passa pelas seguintes fases:
 * 
 * 1. Construção: Gera uma solução inicial de forma gulosa e randomizada usando uma Lista Restrita de Candidatos (RCL).
 * 2. Busca Local: Melhora a solução gerada aplicando heurísticas de otimização local, como troca de cidades ou reversão de subcaminhos.
 * 3. Avaliação: Calcula o custo da solução após a melhoria.
 * 4. Atualização: Armazena a melhor solução encontrada ao longo das iterações.
 * 
 * No final, a melhor rota e seu custo são exibidos e retornados.
 */
pair<double, vector<int>> Simulation::grasp(int numCities, int localSearch) 
{
    //obtem a matriz de distancias do grafo
    const vector<vector<double>> distMatrix = this->graph.adj;
    
    //variaveis que armazenam melhor custo e melhor solução
    vector<int> bestTour;  
    double bestCost = numeric_limits<double>::infinity(); 
   
    //parametros do algorimo grasp
    int maxIterations = 100;   //vai rodar 100 vezes
    int rcl_size = 3;   //controlando o nivel da aleatoriedade   
    
   
    for (int iter = 0; iter < maxIterations; iter++)
    {
        //Fase 1: Construção da solução inicial usando método guloso randomizado
        vector<int> tour(numCities, -1); 
        vector<bool> visited(numCities, false);  
        
        
        int currentCity = rand() % numCities;
        tour[0] = currentCity;
        visited[currentCity] = true;
        
        for(int i = 1; i < numCities; i++)
        {
            vector<pair<double, int>> candidates; 
            
            for(int j = 0; j < numCities; j++)
            {
                if (!visited[j])
                {
                    candidates.push_back({distMatrix[currentCity][j], j});
                }
            }
            
            sort(candidates.begin(), candidates.end());
            
            int rcl_current_size = min(rcl_size, (int)candidates.size());
            
            int random_index = rand() % rcl_current_size;
            currentCity = candidates[random_index].second;
            
            tour[i] = currentCity;
            visited[currentCity] = true;
        }
        
        //Fase 2: Melhoria da solução usando busca local
        vector<int> improvedTour = tour;
        if(localSearch == 1)
        {
            swapLocalSearch(improvedTour, distMatrix);
        }else
        {
            subpathReversion(improvedTour, distMatrix);
        }
        
        //Fase 3: Avaliação da solução melhorada
        double currentCost = 0;
        for(int i = 0; i < numCities - 1; i++)
        {
            currentCost += distMatrix[improvedTour[i]][improvedTour[i + 1]];
        }
        currentCost += distMatrix[improvedTour[numCities - 1]][improvedTour[0]];
        
        //Fase 4: Atualização da melhor solução
        if (currentCost < bestCost)
        {
            bestCost = currentCost;
            bestTour = improvedTour;
            
        }
    }

    cout << "Melhor solução final: ";
    for (size_t i = 0; i < bestTour.size(); ++i)
    {
        cout << bestTour[i];
            
        if (i != bestTour.size() - 1) 
        {
            cout << " -> ";
        }

    }
    cout << "\n";

    cout << "Custo final: " << bestCost << "\n";

    return make_pair(bestCost, bestTour);
}
