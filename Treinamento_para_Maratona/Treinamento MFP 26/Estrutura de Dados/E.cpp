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
   ll a, b; in a >> b;
   string str; in str;

   while(b--){
    for(auto i{0}; i<str.size()-1; i++){
        if(str[i] == 'B' && str[i+1] == 'G'){
            str[i] = 'G';
            str[i+1] = 'B';
            i++;
        }
    }
   }

   out str end;

}