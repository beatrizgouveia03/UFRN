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

ll bb(ll interval[], ll size, ll x){
    ll first = 0, last = size-1, mid = 0;

    while(last >= first){
        mid = first + (last-first)/2;

        if(x >= interval[mid]){
            first = mid+1;
        } else{
            last = mid-1;
        }
    }

    return first;
}

void solve(ll size){
    vi valid;
    ll arr[size+1];

    REP(i, 1, size+1){
        in arr[i];
        if(i<arr[i]){ valid.PB(i); }
    }

   for(auto i{0}; i<valid.size(); i++){
        out bb(arr, size, valid[i]) end;      
   }

}

signed main(){ 
  ll cases; in cases;

  while(cases--){
    ll size; in size;

    solve(size);
  }
}