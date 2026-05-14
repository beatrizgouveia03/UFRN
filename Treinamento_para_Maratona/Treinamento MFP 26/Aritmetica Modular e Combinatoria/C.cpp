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
    string x; in x;
    ll res = 1;

    if(x[0] == '0') res = 0;
    else{        
        ll rep = count(x.cbegin(), x.cend(), '?');  
        if(x[0] == '?'){ res = 9; rep--;}
        res *= pow(10, rep);    
    }

    out res end;
}

signed main(){ _ 
    ll n; in n;

    while(n--){
        solve();
    }
}