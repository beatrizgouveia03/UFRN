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

signed main(){ _ 
    ll n, x; in n >> x;
    pair<ll, ll> arr[n];

    REP(i, 0, n){
        in arr[i].F;
        arr[i].S = i+1; 
    }
    
    sort(arr, arr+n);
    
    ll a=0, b=n-1;
    
    while(a != b){
        if(arr[a].F+arr[b].F == x){
            out arr[a].S << ' ' << arr[b].S end;
            return 0;
        } else if (arr[a].F+arr[b].F>x) {
            b--;
        } else{ a++;}
    }

    out "IMPOSSIBLE" end;
}