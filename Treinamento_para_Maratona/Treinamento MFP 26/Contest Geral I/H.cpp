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
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; ll x; in n >> x;
    ll h = 1, c=0;

    ll corals[n];

    REP(i,0,n) { in corals[n]; c+=corals[n]; h = max(h, corals[n]);}


    while((n*h - c) > x){ h++; c+=corals[h];}

    h+=1;

    out h end;
}

signed main(){ //_     
    ll t; in t;

    while(t--){
        solve();
    }    
}