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

signed main(){
   ll x, a, count = 0; in x;
   vector<ll> arr(x);

   in a; out 0;

   ll min_value = a;

   arr[count] = a;
   x--;
   count++;

   while(x--){
    ll min_pos = 0;     
    in a; 

    if( min_value >= a){
        arr[count] = a;
        count++;
        out " " << min_pos;
        min_value = a;
        continue;
    } 
    
    for(ll i{count-1}; i>=0; i--){
        if(arr[i] < a){
            min_pos = i+1;
            break;
        }
    }

    arr[count] = a;
    count++;

    out " " << min_pos;

   }

   out endl;
   
}