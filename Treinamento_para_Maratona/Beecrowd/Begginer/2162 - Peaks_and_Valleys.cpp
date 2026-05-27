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
#define precise fixed << setprecision(10)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ 
    ll n; in n;
    ll a, b; in a >> b;

    if (a==b) {
        out 0 end;
        return 0;
    }

    ll s;
    if(a>b) s = 1;
    else s = -1;

    a=b;

    REP(i,2,n){
        in b;

        if (a==b) {
            out 0 end;
            return 0;
        }   

        ll new_s;
        if(a>b) new_s = 1;
        else new_s = -1;

        if(new_s == s) {
            out 0 end;
            return 0;
        }

        a=b;
        s=new_s;
    }

    out 1 end;
}