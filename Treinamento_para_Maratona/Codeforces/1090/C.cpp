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
   ll x; in x;

   while (x--)
   {
    ll n; in n;
    ll min = 1, max = n*3;

    out max-- << " " << max-- << " " << min++;

    while(min < max){
        out " " << max-- << " " << max-- << " "<< min++;
    }
    out endl;

   }  
}