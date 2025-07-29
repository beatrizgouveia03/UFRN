#include <bits/stdc++.h>

using namespace std;

map<string, bool> canConst;

bool canConstruct(string target, vector<string> base){
  if(canConst.count( target ) > 0) return canConst[ target ];
  if(target == "") return true;

  for (string word : base) {
    if(target.find(word) == 0){
      string new_target = target;
      new_target.erase(0, word.size());
      if( canConstruct( new_target, base ) )
      {
        canConst[ target ] = true;
        return true;
      }
    }
  }

  canConst[ target ] = false;
  return false;
}

int main(){
  cout << boolalpha;
  cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
  cout << canConstruct("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
  cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
  cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"}) << endl;

  return 0;
}