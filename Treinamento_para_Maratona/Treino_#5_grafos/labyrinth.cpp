#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define MAX_SIZE 1000

int n, m;
bool res = false;
vector<string> lab;
vector<int> dx = {1, 0, -1, 0};
vector<char> moves = {'D', 'L', 'U', 'R'}; 
vector<vector<bool>> visitado (MAX_SIZE,vector<bool>(MAX_SIZE, false)); 
map<pair<int, int>, string> path;

bool canVisit(int l, int c){
  if(l < 0 || l >= n || c < 0 || c >= m || lab[l][c] == '#') return false;
  return true;
}

void find_path(int l, int c){
  int start_x = l;
  int start_y = c;
  queue<pair<int,int>> fila;
  fila.push(make_pair(start_x, start_y));
  visitado[start_x][start_y] = true;
  path[make_pair(start_x, start_y)] = "";

  while(!fila.empty()){ 
    auto curr = fila.front();
    fila.pop();

    int x = curr.first;
    int y = curr.second;
  
    if(lab[x][y] == 'B'){
      cout << "YES\n" + to_string(path[{x, y}].length()) + "\n" + path[{x,y}] + "\n";
      return;
    }

    for(int i=0; i<4; ++i){
      int next_x = x + dx[i];
      int next_y = y + dx[3-i];

      if(canVisit(next_x, next_y) && !visitado[next_x][next_y]){
        path[{next_x, next_y}] = path[{x, y}] + moves[i];
        fila.push({next_x, next_y});
        visitado[next_x][next_y] = true;
      }
    }
  }

  cout << "NO\n";
  return;
}


int main() {
   cin >> n >> m;

   for(int i=0; i<n; ++i){
    string s;
    cin >> s;
    lab.push_back(s);
   }

    for (int i=0; i<n; ++i){
      for(int j=0; j<m; ++j){
        if(lab[i][j] == 'A') find_path(i, j);
      }
    }


  return 0;
}