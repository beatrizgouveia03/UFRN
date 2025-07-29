#include <bits/stdc++.h>

using namespace std;


int main(){
  int n;
  cin >> n;

  vector<int> dp(10001, INT_MAX);

  while(n--){
    int entry;
    cin >> entry;

    dp[0] = 0;

    for(int i = 1; i <= entry; ++i){
      if(dp[entry] != INT_MAX) break;
      if(dp[i] != INT_MAX) continue;
      for(int j = 1; j * j <= i; ++j){
        dp[i] = min(dp[i], dp[i - j*j] + 1);
      }
    }

    cout << dp[entry] << endl;
  }

  return 0;
}