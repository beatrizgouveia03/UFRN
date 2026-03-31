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

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    int n; 

    while(in n){
        int lvl = 1;

        for(auto i{0}; i<n; ++i){
            int sp; in sp;
            if(sp >= 10) lvl = max(lvl, 2);
            if(sp >= 20) lvl = max(lvl, 3);
        }

        out lvl end;        
    }
}