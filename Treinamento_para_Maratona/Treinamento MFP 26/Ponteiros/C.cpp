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

void subsum(ll arr[], ll n, ll x){
    bool flag = false;

   
    REP(first, 0, n){
        ll last = n-1;
        while(last > first){
               if(arr[first] + arr[last] == x){ 
                   out (first+1) << " " << (last-1) end; 
                   return;
               } else last--;
        }


        out "IMPOSSIBLE" end;
    }
}


signed main(){ 
    ll n, x; in n >> x;
    ll arr[n];

    REP(i,0,n){
        in arr[i]; 
    }

    subsum(arr, n, x);
    
}