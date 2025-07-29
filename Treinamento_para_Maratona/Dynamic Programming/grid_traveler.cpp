#include <bits/stdc++.h>

using namespace std;

#define ll long long

map<pair<int, int>, ll> amount_of_ways;

ll gridTraveler(int m, int n){
  if(amount_of_ways[{m, n}]) return amount_of_ways[{m, n}];
  if (m == 1 && n == 1) return 1;
  if(m == 0 || n == 0) return 0;

  amount_of_ways[{m, n}] = gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
  amount_of_ways[{n, m}] = amount_of_ways[{m, n}];

  return amount_of_ways[{m, n}];
}


int main(){
  cout << gridTraveler(1, 1) << endl;
  cout << gridTraveler(0, 1) << endl;
  cout << gridTraveler(1, 0) << endl;
  cout << gridTraveler(2, 3) << endl;
  cout << gridTraveler(18, 18) << endl;

  return 0;
}