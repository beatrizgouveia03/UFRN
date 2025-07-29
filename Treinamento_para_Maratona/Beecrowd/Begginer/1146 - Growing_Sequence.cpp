#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f first
#define s second
#define ii pair<int, int>
#define vi vector<int>
#define  precise fixed << setprecision(2) 

typedef long long unsigned ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _
    
    ll x; cin >> x;

    while(x != 0){
        cout << 1;
        for(auto i{2u}; i<=x; ++i) cout << " " << i;
        cout << endl;
        cin >> x;
    }

    return 0;
}