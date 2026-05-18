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
#define precise fixed << setprecision(2)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    ll n; in n;
    while(n--){
        string p1, p2; in p1 >> p2;
        
        if(p1 == p2){
            if(p1 == "papel") out "Ambos venceram" end;
            else if(p1 == "pedra") out "Sem ganhador" end;
            else out "Aniquilacao mutua" end;
        } else {
            if(p1 == "papel" || p2 == "ataque") out "Jogador 2 venceu" end;
            else out "Jogador 1 venceu" end;
        }
    }
}