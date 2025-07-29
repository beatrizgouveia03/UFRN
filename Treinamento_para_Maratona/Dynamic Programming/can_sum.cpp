#include <bits/stdc++.h>

using namespace std;

vector<int> numbers = {2, 4, 5, 7};
map<int, bool> possible_sum;

bool can_sum(int targetSum){
  if(possible_sum[targetSum]) return possible_sum[targetSum];
  if(targetSum == 0) return true;
  if(targetSum < 0) return false;

  for(int n : numbers){
    int sum = targetSum - n;

    if (can_sum(sum)) {
      possible_sum[targetSum] = true;
      return true;
    }
  }

  possible_sum[targetSum] = false;
  return false;
}

int main(){
  cout << can_sum(7) << endl;
  cout << can_sum(3) << endl;
  cout << can_sum(10000) << endl;
  cout << can_sum(500) << endl;

  return 0;
}