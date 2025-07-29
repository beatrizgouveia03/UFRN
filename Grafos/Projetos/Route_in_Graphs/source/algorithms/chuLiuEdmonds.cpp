#include "simulation.h"

using namespace sml;

struct Edge {
  int from, to, weight;
  Edge(int f, int t, int w) : from(f), to(t), weight(w) {}
};

/* Busca ciclos no grafo `graph` de tamanho `n`,
 * Retorna um par onde o primeiro elemento indica se foram encontrados ciclos
 * e o segundo elemento é um vetor com todos os ciclos encontrados.
 */

pair<bool, vector<int>> findCycle(vector<vector<int>> &graph, int n) {
  vector<bool> visited(n, false);
  vector<bool> inStack(n, false);
  vector<int> cycle;

  for (int start = 0; start < n; start++) {
    if (visited[start])
      continue;

    stack<pair<int, int>> st;
    vector<int> path;
    st.push({start, 0});
    inStack[start] = true;
    path.push_back(start);

    while (!st.empty()) {
      int current = st.top().first;
      int &neighborIndex = st.top().second;

      visited[current] = true;

      bool foundNext = false;
      for (; neighborIndex < n; neighborIndex++) {
        if (graph[current][neighborIndex] > 0) {
          if (!visited[neighborIndex]) {
            st.push({neighborIndex, 0});
            inStack[neighborIndex] = true;
            path.push_back(neighborIndex);
            foundNext = true;
            break;
          } else if (inStack[neighborIndex]) {
            auto it = find(path.begin(), path.end(), neighborIndex);
            cycle = vector<int>(it, path.end());
            return {true, cycle};
          }
        }
      }

      if (!foundNext) {
        inStack[current] = false;
        path.pop_back();
        st.pop();
      }
    }
  }
  return {false, cycle};
}

void Simulation::chuLiuEdmonds(void) {
  int n = this->graph.n;
  int root = 0; // Assume que o nó raiz sempre será 0
  vector<vector<int>> adj = this->graph.adj;
  vector<bool> visited(n, false);
  vector<vector<int>> tmp(n, vector<int>(n));
  vector<vector<int>> idx(n + 1, vector<int>(n + 1));
  vector<Edge> s;
  Graph aux;
  aux.n = n;
  aux.dictionary = this->graph.dictionary;

  /* Passo 1:
   * Descarte os arcos que entram na raiz, se houver; Para cada nó
   * diferente da raiz, selecione o arco de entrada com o menor custo;
   * Defina os n-1 arcos selecionados como o conjunto S.
   */
  for (int i = 0; i < n; i++) {
    if (i != root) {
      int min_weight = numeric_limits<int>::max();
      int min_from = -1;

      for (int j = 0; j < n; j++) {
        if (adj[j][i] > 0 && adj[j][i] < min_weight) {
          min_weight = adj[j][i];
          min_from = j;
        }
      }

      if (min_from != -1) {
        s.push_back(Edge(min_from, i, min_weight));
      }
    }
  }

  // Passo 2
  while (true) {
    vector<vector<int>> cycle_graph(n, vector<int>(n, 0));
    for (const Edge &e : s) {
      cycle_graph[e.from][e.to] = e.weight;
    }
    auto [hasCycle, cycle] = findCycle(cycle_graph, n);

    // Se nenhum ciclo for formado, G = (N, S) é uma árvore geradora mínima
    if (!hasCycle)
      break;

    // Caso contrário, continue
    vector<bool> inCycle(n, false);

    for (int v : cycle) {
      inCycle[v] = true;
    }

    vector<Edge> k;
    vector<Edge> new_s;
    int k_id = -10;

    // Passo 3:
    for (const Edge e : s) {
      if (inCycle[e.from] && inCycle[e.to]) {
        k.push_back(e);
      } else {
        new_s.push_back(e);
      }
      //  for (const Edge &e : new_s) {
      // 	printf("%d -> %d: %d", e.from, e.to, e.weight);
      // }

      //  for (int i = 0; i < n; i++) {
      //    if (inCycle[i])
      //      continue;
      //    for (int v : cycle) {
      //      if (adj[i][v] > 0) {
      //        int w = adj[i][v];
      //        new_s.push_back(Edge(i, k_id, w));
      //      }
      // idx[i][k_id] = v;
      //    }
      //  }
      /* Passo 4:
       * Para cada pseudo-nó, selecione o arco de entrada que tem o menor custo
       * modificado; Substitua o arco que entra no mesmo nó real em S pelo novo
       * arco selecionado.
       */

      // int min_w = INT_MAX;
      // int min_idx = -1;
      // Edge min_e = Edge(-1,-1,-1);
      // for(auto e : new_s){
      // 	if(e.to == k_id && e.weight < min_w){
      // 		min_idx = idx[e.from][e.to];
      // 		min_w = e.weight;
      // 		min_e = e;
      // 	}
      // }
      //  	vector<Edge> final_s;
      //
      // final_s = new_s;
      // final_s.push_back(Edge(min_e.from, min_idx, min_w));
      //
      s = new_s;
    }

    // Limpa matriz antiga
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        adj[i][j] = 0;
      }
    }

    // Atualiza com os valores das arestas
    for (const Edge &e : s) {
      adj[e.from][e.to] = e.weight;
    }

    aux.adj = adj;

    cout << "Grafo novo gerado: " << endl;
    cout << aux;
  }
}
