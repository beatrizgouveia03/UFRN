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

bool verify(ll a, ll b,ll c){
    if(a>=b+c) return false;
    if(b>=a+c) return false;
    if(c>=a+b) return false;

    return true;
}

void solve(){
  ll a, b, c, d;
  in a >> b >> c >> d;

  out ((verify(a,b,c)|| verify(b,c,d) || verify(c, d, a) || verify(d, a, b))? "S" : "N") end;
}

signed main(){ _
    solve();
}