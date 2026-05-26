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
   ll n,m; in n >> m;

   ll sounds[m];

   REP(i,0,n) in sounds[i];

   sort(sounds, sounds+n);

   ll sums[m];

   sums[0] = 0;

   ll wait {0};
   ll other{n-1};

   for(auto i{m-1}; i>=0; --i){
    while(other >= 0 && sounds[other] >= i+1){
        ++wait;
        --other;
    }
    sums[i] = wait;
   }

   out sums[0];
   REP(i,1,m) out " " << sums[i];
   out endl;
   
}