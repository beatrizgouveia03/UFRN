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

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    ll n, p; in n >> p;
    ll l{0}, r{INT_MAX};
    ll times[n];

    REP(i,0,n) in times[i];
    
    while(l <= r){
        ll idx = ((r+l)/2);
        ll tp{0};

        REP(i,0,n) tp += idx/times[i];

        if(tp > p) r = idx-1;
        else if(tp < p) l = idx+1;
        else { r = idx;}
    }

    out r end;
     
}