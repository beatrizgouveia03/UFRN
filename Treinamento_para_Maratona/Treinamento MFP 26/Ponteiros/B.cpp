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

void subsum(ll arr[], ll n, ll sum, ll x){
    ll count = 0;

    REP(i,0,x){
        ll *f = &arr[i], *last = &arr[n];
        ll tsum = sum;
        
        while(tsum > x){
            
        }

    }
}

signed main(){ 
    ll n, x; in n >> x;
    ll arr[n], sum = 0;

    REP(i,0,n){
        in arr[i]; sum += arr[i];
    }

    subsum(arr, n, sum, x);
    
}