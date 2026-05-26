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

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ 
    ll n; in n;
    ll r[n];

    ll f; in f;

    r[0]=0;

    REP(i,1,n){
        ll s; in s;
        r[i] = s-f;
        f=s;
    }

    REP(i,1,n) {
        if(r[i] == 0 || r[i+1] == 0){ out 0 end; return 0;}
        if((r[i]>0 && r[i+1] > 0) || (r[i]<0 && r[i+1]<0)){ out 0 end; return 0;}
    }

    out 1 end;
}