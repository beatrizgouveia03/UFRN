#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100001

vector<int> distinct(MAX_SIZE, -1);
vector<int> entry(MAX_SIZE);

int main()
{
  int n, m;
  set<int> sub;

  cin >> n >> m;

  for (int i = 0; i < n; ++i)
  {
    cin >> entry[i];
  }

  for (int i = n - 1; i >= 0; --i)
  {
    sub.insert(entry[i]);
    distinct[i + 1] = sub.size();
  }

  for (int i = 0; i < m; ++i)
  {
    int value;

    cin >> value;

    cout << distinct[value] << endl;
  }
  return 0;
}