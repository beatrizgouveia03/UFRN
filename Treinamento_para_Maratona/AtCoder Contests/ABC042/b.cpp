#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second 
#define ii pair<int,int> 
#define v vector<string> 
#define ll long long unsigned
#define endl "\n"

int main(){
   int n, l; cin>> n>>l;
   v list(n+1);
   for(auto i{0}; i<n; ++i){
        cin >> list[i];
   }
   sort(list.begin(), list.end());

   for (auto i{list.begin()}; i != list.end(); ++i)
   {
    cout << *i;
   }

   cout << endl;
   

    exit(0);
}