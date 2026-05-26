#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define in cin >>
#define out cout <<
#define end << endl
#define vi vector<int>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(10) <<

typedef unsigned long long int ll;



signed main(){
    ll n, k; in n >> k;
    double f = 1.0;

    REP(i,0,n){
        ll d; in d;
        f *= min(1.0, (double)(k-1)/d);
    }

    out precise (1.0-f) end;
}