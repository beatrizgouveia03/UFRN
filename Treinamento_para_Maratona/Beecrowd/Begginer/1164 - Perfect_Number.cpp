#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << endl
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
   int amount_cases;
   in amount_cases;

   while(amount_cases--){
    ll number, sum = 0;
    in number;


    for(ll i{1}; i<number;++i){
      if(number%i == 0) sum += i;
    }
    
    out number;
    (sum == number) ? out " eh perfeito" end : out " nao eh perfeito" end;
   }
   
}