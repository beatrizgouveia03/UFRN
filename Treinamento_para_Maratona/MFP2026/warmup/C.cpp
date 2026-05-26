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

signed main(){ _ 
    ll n; in n;

    REP(i,0,n){
        string s; in s;
        if(s.size() <= 10){
            out "N" end; continue;
        }
        
        ll c = 0, num = 0;

        REP(i,0,s.size()){
            ll x = (int)s[i];
            if(x >= '0' && x <='9'){
                if(x < c){
                    out "N" end;
                    break;
                }
                c = x;
            }
            else if (x >= 'a' && x <= 'z'){
                if(x < num){
                    out "N" end;
                    break;
                }
                num = x;
            }
        }

        out "S" end;
    }
}