#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX_SIZE 100000

int n, m;
vector<vector<int>> adj(MAX_SIZE);
vector<int> path; 
vector<int> dist;
vector<bool> visited(MAX_SIZE, false);

void find_path(){
  queue<int> fila;
  int len = 0;

  fila.push(0);
  visited[0] = true;

  while(!fila.empty()){
    int curr = fila.front();
    fila.pop();

    for(int a : adj[curr]){
      if(!visited[a]){
        fila.push(a);
        visited[a] = true;
      }
    }
  }

}


int main(){
  cin >> n >> m;

  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  find_path();

  return 0;
}