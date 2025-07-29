#include <bits/stdc++.h>

using namespace std;

map<int, vector<int> *> sums;

vector<int> *best_sum(int targetSum, vector<int> array){
  if( sums[targetSum] != nullptr ) return sums[targetSum];
  if( targetSum == 0 ) return new vector<int> ();
  if( targetSum < 0 ) return nullptr;

  vector<int> *shortestComb = nullptr;

  for(int a : array){
    int remainder = targetSum - a;
    vector<int> *remComb = best_sum(remainder, array);

    if (remComb != nullptr)
    {
      vector<int> *currComb = new vector<int>(*remComb);
      currComb->push_back(a);
      if (shortestComb == nullptr || currComb->size() < shortestComb->size() )
      {
        delete shortestComb;
        shortestComb = currComb;
      }
      else
      {
        delete currComb;
      }
    }
  }
  
  sums[ targetSum ] = shortestComb;
  return shortestComb;
}

int main(){
  vector<int> *res = best_sum( 8, { 2, 3, 5 } );

  cout << "Res : [ ";
  for(int num : *res){
    cout << num << " ";
  }
  cout << "]" << endl;

  sums.clear();

  vector<int> *res2 = best_sum(7, {5, 3, 4, 7});

  cout << "Res2 : [ ";
  for (int num : *res2)
  {
    cout << num << " ";
  }
  cout << "]" << endl;

  sums.clear();

  vector<int> *res3 = best_sum(8, {1, 4, 5});

  cout << "Res3 : [ ";
  for (int num : *res3)
  {
    cout << num << " ";
  }
  cout << "]" << endl;

  sums.clear();

  vector<int> *res4 = best_sum(100, {1, 2, 5, 25});

  cout << "Res4 : [ ";
  for (int num : *res4)
  {
    cout << num << " ";
  }
  cout << "]" << endl;

  return 0;
}
