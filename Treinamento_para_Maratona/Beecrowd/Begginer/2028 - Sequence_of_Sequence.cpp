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
#define precise fixed << setprecision(2)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ //_ 
    ll number, count = 1;
    while(in number){
        vi res;

        res.PB(0);
        
        REP(i,1,number+1){
            REP(j,0,i){
                res.PB(i);
            }
        }
        
        out "Caso " << count << ": " << res.size();
        out ((number>0)? " numeros" : " numero") end;

        out res[0];
        REP(i,1,res.size()) out ' ' << res[i];
        out endl end;

        count++;
    }
}