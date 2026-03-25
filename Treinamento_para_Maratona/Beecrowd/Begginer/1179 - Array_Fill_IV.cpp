#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << endl
#define dd double
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    int ec = 0, oc = 0;
    vi e(5, 0), o(5, 0);

    for(int i{0}; i<15; ++i){
        int x; in x;
        if(x%2) o[oc++] = x;
        else e[ec++] = x;

        if(ec == 5){
            for(int j{0}; j<5; ++j) out "par[" << j << "] = " << e[j] end;
            ec = 0;
        }
        if(oc == 5){
            for(int j{0}; j<5; ++j) out "impar[" << j << "] = " << o[j] end;
            oc = 0;
        }
    }

   
    if(oc){
        for(int j{0}; j<oc; ++j) out "impar[" << j << "] = " << o[j] end;
    }
    if(ec){
        for(int j{0}; j<ec; ++j) out "par[" << j << "] = " << e[j] end;
    } 
    
}