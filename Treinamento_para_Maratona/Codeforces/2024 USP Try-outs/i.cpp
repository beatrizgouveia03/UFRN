#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n; cin >> n;
    bool flagOdd = false, flagZero = true;
    
    for(auto i{0}; i<n; ++i){
        ll h; cin >> h;
        if(h != 0) flagZero = false;
        if(h > 2 && h%2 != 0) flagOdd = true;
    }

    (flagZero)? cout << 0 << endl : ((flagOdd)? cout << 2 << endl :cout << 1 << endl);

    return 0;
}