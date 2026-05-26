#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n,soma=0;
    cin >> n;
    int v[n];
    for (int i=0; i<n; i++){cin >> v[i];soma += v[i];}
    sort(v, v+n);
    int min = v[0];
    for (int i=0; i<n; ++i)if(v[i]%min != 0){i=-1;min--;}
    cout << soma/min;
}