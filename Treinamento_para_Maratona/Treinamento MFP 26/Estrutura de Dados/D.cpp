#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << '\n'
#define dd double
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(1)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
   ll n, k, count = 0, a,ks;
   in n >> k;


   for(auto i{0}; i<k; i++){
    in a;
    ks=a;
    n--;
    if(a == 0) break;
    count++;
   }

   while(n>0){
    in a;
    if(a == 0 || a != ks) break;
    count++;
    n--;
   }

   out count end;
}