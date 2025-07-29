#include <bits/stdc++.h>

using namespace std;

int main(){
  long long n, best, sum;
  
  cin >> n;

  vector<long long> arr(n);

  for(long long i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  best = 0;
  sum = 0;

  for (long long i = 0; i < n; i++)
  {
    sum = max(sum + arr[i], arr[i]);
    best = max(sum, best);
  }
  
  cout << best << endl;


  return 0;
}