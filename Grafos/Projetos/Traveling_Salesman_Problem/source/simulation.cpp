#include "simulation.h"

using namespace sml;

const int INF = numeric_limits<int>::max();

/**!
 * Construtor padrão da classe Simulation
 */
Simulation::Simulation(void) {
  // Inicializa a simulação
}

/**!
 * Esta função espera por uma entrada no terminal para finalizar.
 */
void Simulation::pause(void){
  cout << "Para retornar ao menu principal, pressione Enter...";
  cin.get(); // Aguarda uma entrada
  cout << endl;
}

/**! 
 * Essa função exibe o menu dos algoritmos da simulação no terminal.
 * 
 * Esse menu serve como ponto de partida para o usuário
 * interagir com as funcionalidades da simulação. Nele o usuário pode escolher
 * qual algoritmo deseja testar para resolver o problema do caixeiro viajante.
 */
void Simulation::showAlgMenu(void){
  cout << "============================================" << endl;
  cout << "              Menu de Algoritmos            " << endl;
  cout << "============================================" << endl;
  cout << "1. Algoritmo Guloso" << endl;
  cout << "2. Insercao mais barata" << endl;
  cout << "3. GRASP + Troca (Swap)" << endl;
  cout << "4. GRASP + Reversão de Subcaminho"<< endl;
  cout << "0. Encerrar programa" << endl;
}

/**!
 * Essa função exibe o menu dos problemas da simulação no terminal.
 * 
 * Esse menu serve como ponto de partida para o usuário
 * interagir com as funcionalidades da simulação. Nele o usuário pode escolher
 * qual dos problema deseja resolver com a simulação.
 */
void Simulation::showProbMenu(void){
  cout << "============================================" << endl;
  cout << "              Menu de Problemas            " << endl;
  cout << "============================================" << endl;
  cout << "1. Problema 1 - 48 cidades " << endl;
  cout << "2. Problema 2 - 36 cidades " << endl;
  cout << "3. Problema 3 - 24 cidades " << endl;
  cout << "4. Problema 4 - 12 cidades " << endl;
  cout << "5. Problema 5 - 7 cidades " << endl;
  cout << "6. Problema 6 - 6 cidades " << endl;
  cout << "0. Retornar ao menu de algoritmos" << endl;
}


/**!
 * Esta função percorre o menu principal chamando as
 * funções relacionadas a ele, até que o usuário escolha encerrar o programa.
 */
void Simulation::run(void) {
  int algOption = -1, probOption = -1;
  string str;

  while(true){
    showAlgMenu();
    cout << "Digite a opcao escolhida: " << endl;
    getline(cin, str);
    algOption = stoi(str);

    if(algOption == 0) break;

    showProbMenu();
    cout << "Digite a opcao escolhida: " << endl;
    getline(cin, str);
    probOption = stoi(str);

    if(probOption == 0) continue;

    runProblem(algOption, probOption);
    pause();
  }
}

/**!
 * Esta função executa o problema escolhido pelo usuário
 * com o algoritmo escolhido.
 *
 * @param problem O problema escolhido pelo usuário
 * @param algorithm O algoritmo escolhido pelo usuário
 */
void Simulation::runProblem(int algorithm, int problem) {
  int numCities = 0;

  switch(problem){
    case 1:
      numCities = 48;
      break;
    case 2:
      numCities = 36;
      break;
    case 3:
      numCities = 24;
      break;
    case 4:
      numCities = 12;
      break;
    case 5:
      numCities = 7;
      break;
    case 6:
      numCities = 6;
      break;
    default:
      break;
  }

  auto start = high_resolution_clock::now();
  pair<double, vector<int>> bestTour;

  ofstream file("output.txt");
  if(!file.is_open()){
    cout << "Erro ao abrir o arquivo de saida" << endl;
    return;
  }

  file << "Cidades: " << numCities << endl;
  file << "Iteração | Tempo | Custo | Solução " << endl;

  if(algorithm == 1){
    file << "1 |" ;

    auto start = high_resolution_clock::now(); //Começa a contagem do tempo 

    bestTour = tspGreedy(numCities);

    auto end = high_resolution_clock::now();  //Termina a contagem do tempo
    auto duration = duration_cast<seconds>(end - start); //Calcula a diferença entre o tempo de início e o tempo de término

    file << duration.count() << "s | " << bestTour.first << " | "; //Adiciona o tempo de execução, o custo e a solução ao arquivo de saída
    for(int i = 0; i < numCities; i++){
      file << bestTour.second[i] << " ";
    }
  } 
  
  else if(algorithm == 2){
    file << "1 |";

    auto start = high_resolution_clock::now(); //Começa a contagem do tempo

    bestTour = tspCheapestInsertion(numCities);

    auto end = high_resolution_clock::now();  //Termina a contagem do tempo
    auto duration = duration_cast<seconds>(end - start);  //Calcula a diferença entre o tempo de início e o tempo de término
    
    
    file << duration.count() << "s | " << bestTour.first << " | "; //Adiciona o tempo de execução, o custo e a solução ao arquivo de saída
    for(int i = 0; i < numCities; i++){
      file << bestTour.second[i] << " ";
    }
  } 
  
  else if(algorithm == 3){
    int64_t sum = 0;

    for(int i=0; i<30; ++i){
      file << i+1 << " | "; //Adiciona o número da iteração ao arquivo de saída

      auto start = high_resolution_clock::now();  //Começa a contagem do tempo

      bestTour = grasp(numCities, 1);

      auto end = high_resolution_clock::now();  //Termina a contagem do tempo
      auto duration = duration_cast<seconds>(end - start);  //Calcula a diferença entre o tempo de início e o tempo de término

      sum += duration.count();
      
      file << duration.count() << "s | " << bestTour.first << " | "; //Adiciona o tempo de execução, o custo e a solução ao arquivo de saída
      for(int i = 0; i < numCities; i++){
        file << bestTour.second[i] << " ";
      };
    }

    cout << "Tempo medio de execucao: " << sum/30 << "s" << endl;
  } 
  
  else if(algorithm == 4){ 
    int64_t sum = 0;

    for(int i=0; i<30; ++i){
      file << i+1 << " | "; //Adiciona o número da iteração ao arquivo de saída

      auto start = high_resolution_clock::now();  //Começa a contagem do tempo

      bestTour = grasp(numCities, 2);

      auto end = high_resolution_clock::now();   //Termina a contagem do tempo
      auto duration = duration_cast<seconds>(end - start);  //Calcula a diferença entre o tempo de início e o tempo de término
      
      sum += duration.count(); 
      
      file << duration.count() << "s | " << bestTour.first << " | "; //Adiciona o tempo de execução, o custo e a solução ao arquivo de saída
      for(int i = 0; i < numCities; i++){
        file << bestTour.second[i] << " ";
      };
    }
    
    cout << "Tempo medio de execucao: " << sum/30 << "s" << endl;
  }

  file.close();
}

/**!
 * Esta função inicializa a simulação lendo o arquivo de entrada
 * e criando representações do grafo como lista de adjacência,
 * matriz de adjacência e matriz de incidência.
 *
 * @param argc Um inteiro indicando a quantidade de argumentos passados no terminal
 * @param argv A lista de argumentos passados no terminal
 * @return Uma estrutura indicando se a inicialização foi bem-sucedida
 */
SimulationResult Simulation::initialize(int argc, char *argv[]) {
  // Inicializa a simulação
  // Processa os argumentos da linha de comando
  if (argc <= 1) {
    return usage("Erro: Nome do arquivo ausente");
  } 
  
  string filename = argv[1];
  ifstream file(filename);

  cout << "Inicializando a simulacao..." << endl;

  if (!file.is_open()) {
    return usage("Erro: Nao foi possivel abrir o arquivo");
  }

  // Leitura da entrada
  while(!file.eof()){
    cout << filename << endl;
    
    cout << "Lendo numero de vertices..." << endl;
    string numNodesStr;
    getline(file, numNodesStr);
    int numNodes = stoi(numNodesStr);
    cout << "Numero de vertices: " << numNodes << endl;

    this->graph.n = numNodes;

    string line;
    vector<vector<double>> adj = vector<vector<double>>(this->graph.n, vector<double>(this->graph.n, -1)); //!< Matriz de adjacência


    cout << "Lendo matriz de adjacencia..." << endl;
    for (int i = 0; i < this->graph.n; i++) {
      getline(file, line);
      istringstream iss(line);
      for (int j = 0; j < this->graph.n; j++) {
        iss >> adj[i][j];
        cout << i << " " << j << " -> " << adj[i][j] << endl;
      }
    }

    this->graph.adj = adj;
  }


  cout << "Inicializacao concluida com sucesso" << endl;
  cout << this->graph << endl;

  return SimulationResult("", simulation_result_e(0));
}

/**!
 * Esta função exibe no terminal as opções de uso.
 *
 * @param message A mensagem de descrição do erro de uso a ser exibida
 * @return Uma estrutura indicando que a leitura falhou e a mensagem de erro
 */
SimulationResult Simulation::usage(string message){
  string usage = ">>> Uso: Traveling_Salesman_Problem <arquivo_de_entrada>\n";

  if(message != "")
  {
    usage = ">>> " + message + "\n" + usage;
  }

  return SimulationResult(usage, simulation_result_e(1));
}
