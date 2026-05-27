#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in cin >>
#define out cout << 
#define end << endl
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(10)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

double sroot(ll n){
    if(n == 0) return 0;
    if(n == 1) return 0.5;

    return 1/(2+sroot(n-1));
}

signed main(){ _ 
    ll n; in n;

    out precise << 1+sroot(n) end;
}