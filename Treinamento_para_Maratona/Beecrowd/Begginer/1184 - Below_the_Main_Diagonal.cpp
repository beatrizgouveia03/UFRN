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
#define precise fixed << setprecision(1)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    char o;
    dd sum = 0.0, n;

    in o;

    for(auto i{0};i<12; ++i){
        for(auto j{0}; j<12; ++j){
            in n;

            if(i>j) sum+=n;
        }
    }

    out precise;
    (o == 'S') ? out sum end : out sum/66 end;
    

}