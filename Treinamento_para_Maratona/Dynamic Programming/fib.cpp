#include <bits/stdc++.h>

using namespace std;

// memoization
map<int, int> fib_res;

int fib(int n)
{
  if (fib_res[n])
    return fib_res[n];
  if (n <= 2)
    return 1;

  fib_res[n] = fib(n - 1) + fib(n - 2);

  return fib_res[n];
}

int main()
{
  int n;

  fib_res[1] = 1;
  fib_res[2] = fib_res[1];

  cin >> n;

  cout << fib(n) << endl;

  return 0;
}