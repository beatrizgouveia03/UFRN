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
   string p0, p1, c0, c1;
   ll v0, v1;

   in p0 >> c0 >> p1 >> c1 >> v0 >> v1;

   if(c0 == "PAR"){
    out (((v0+v1)%2)?p1 : p0) end;
   } else {
    out (((v0+v1)%2)?p0 : p1) end;
   }


}

signed main(){ _
   ll x; in x;
   while(x--){
    solve();
   }
}