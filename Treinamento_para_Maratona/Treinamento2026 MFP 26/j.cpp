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

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    ll a; in a;
    bool pg = true;
    vector<bool> v(26, false);

    if(a < 24) out "NO" end;
    else{
        char letter;
        for(auto i{0}; i<a; i++) {
            in letter;
            v[tolower(letter)-97]=true;
        }

        for(auto i{0}; i<26; i++){
            if(!v[i]) {
                pg = false;
                break;
            }
        }

        out ((pg)?"YES":"NO") end;
    }    
}