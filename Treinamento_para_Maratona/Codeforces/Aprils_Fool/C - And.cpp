#include <bits/stdc++.h>

using namespace std;

signed main(){
   int n; cin >> n;

   while(n--){
    int a, b, c, total;
    cin >> a >> b >> c;

    total = a+b+c;
    cout << (total/3 + total%3) << endl; // Wrong
   }
}