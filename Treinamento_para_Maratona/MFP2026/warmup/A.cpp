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

signed main(){ _ 
    ll n; in n;

    REP(i,0,n){
        ll a, b, c; in a >> b >> c;
        if(a == b) out c end;
        else if(b == c) out a end;
        else out b end;
    }
}