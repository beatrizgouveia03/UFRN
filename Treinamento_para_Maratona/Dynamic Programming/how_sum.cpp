#include <bits/stdc++.h>

using namespace std;

vector<int> numbers = {2, 4, 7};
map<int, vector<int>*> sums;

vector<int>* how_sum(int targetSum)
{
  if(sums[targetSum] != nullptr) return sums[targetSum];
  if(targetSum == 0) return new vector<int>();
  if(targetSum < 0) return nullptr;

  for(int n : numbers){
    vector<int> *sum = how_sum(targetSum - n);

    if(sum != nullptr){
      sum->push_back(n);
      sums[targetSum] = sum;
      return sum;
    }
  }

  sums[targetSum] = nullptr;
  return nullptr;
}

int main()
{
  vector<int> *res = how_sum(1);

  if(res != nullptr){
    cout << "[ ";
    for (int r : *res)
    {
      cout << r << " ";
    }
    cout << "]\n";
  } else{
    cout << "-1\n";
  }

  delete res;

  return 0;
}