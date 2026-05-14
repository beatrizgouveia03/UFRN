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
    ll n, m; 

    while(in n >> m){
        set<ll> coef;
        bool res;
        
        REP(i, 0, n){
            ll c; in c;
            coef.insert(c);
        }
        
        ll a = *coef.begin();
        ll b = *coef.begin()+1;
        ll c = *coef.begin()+2;
        
        if(n == 1 || m == 1) res = true;
        else if(m>1 && coef.size() != n) res = false;
        else if(n==3 && a+b==c) res = false;
        else res = true;

        out ((res)?"Lucky Denis!":"Try again later, Denis...") end;
    }
}