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
    string a, b; in a >> b;
    ll cont = 0;

    REP(i,0,a.size()){
        (a[i] <= b[i])?cont += b[i]-a[i]: cont += b[i]-'a'+'z'-a[i]+1;
    }
    out cont end;
}

signed main(){ _ 
    ll x; in x;
    while(x--) solve();    
}