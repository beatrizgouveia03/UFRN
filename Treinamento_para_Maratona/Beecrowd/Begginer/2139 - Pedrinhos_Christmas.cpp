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

ll calendar[] = {31,29,31,30,31,30,31,31,30,31,30,31};

signed main(){ _ 
    ll m, d;

    while(in m >> d){
        ll res = 0;
        
        REP(i,0,m-1)res += calendar[i];

        res += d;

        if(res > 360) out "Ja passou!" end;
        else if(res == 359) out "E vespera de natal!" end;
        else if(res == 360) out "E natal!" end;
        else out "Faltam " << (360-res) << " dias para o natal!" end;
    }
}