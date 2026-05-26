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

void solve(){
    ll n; in n;
    ll tasters[n], tea[n], consume[n] = {0};

    REP(i,0,n) in tea[i];  
    REP(i,0,n) in tasters[i];

    REP(i,0,n){
        REP(j,i,n){
            ll consumed = min(tasters[j], tea[j-i]);
            consume[j] += consumed;
            tea[j-i] -= consumed;
        }
    }

    out consume[0];
    REP(i,1,n) out " " << consume[i];
    out endl;
}

signed main(){ _ 
    ll n; in n;

    while(n--) solve();
}