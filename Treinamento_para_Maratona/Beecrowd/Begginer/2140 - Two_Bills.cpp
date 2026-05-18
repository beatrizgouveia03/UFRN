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

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll bills[] = {2,5,10,20,50,100};

signed main(){ _ 
    ll a, b; in a >> b;

    while(a+b != 0){
        ll c = b-a;
        ll x = 0, y = 5;
        bool possible = false;

        while(x<y){
            ll amount = bills[x] + bills[y];
            if(amount == c){
                possible = true;
                break;
            } 
            else if(amount > c) y--;
            else x++;
        }

        if(possible) out "possible" end;
        else out "impossible" end;

        in a >> b;
    }
}