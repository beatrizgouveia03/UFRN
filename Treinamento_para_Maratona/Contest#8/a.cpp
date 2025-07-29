#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
  vector<string> entry;
  map<string, bool> base;

  int n, m;

  cin >> n >> m;

  for(int i=0; i<n; ++i){
    string s;
    cin >> s;
    base[s] = false;
    entry.push_back(s);
  }

  for(int i=0; i<m; ++i){
    string s;
    cin >> s;
    base[s] = true;
  }

  for(string s : entry){
    if(base[s] == true) cout << "Yes\n";
    else cout << "No\n";
  }



  return 0;
}