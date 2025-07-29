#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX_SIZE 1000

int n, m, res = 0;
vector<string> map;
vector<int> dx = {1, 0, -1, 0};
vector<vector<bool>> visitado(MAX_SIZE, vector<bool>(MAX_SIZE, false));

void visit( int l, int c){
  if (l < 0 || l >= n || c < 0 || c >= m || visitado[l][c] || map[l][c] == '#') return;
  visitado[l][c] = true;
  for(int i=0; i<4; ++i){
    int x = l + dx[i];
    int y = c + dx[3-i];
    visit(x, y);
  }
}

int main(){
  cin >> n >> m;

  for(int i=0; i<n; ++i){
    string linha;

    cin >> linha;
    map.push_back(linha);
  }

  for(int i=0; i<n; ++i){
    for(int j=0; j<m; ++j){
      if(map[i][j] == '.' && !visitado[i][j]){
        res++;
        visit(i, j);
      }
    }
  }

  cout << res << endl;

  return 0;
}