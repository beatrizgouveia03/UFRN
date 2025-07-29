#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f first
#define s second
#define ii pair<int, int>
#define vi vector<int>
#define si set<int>
#define  precise fixed << setprecision(2) 

typedef long long unsigned ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    ll x; cin >> x;
    si div;

    for(ll i{1u}; i<=sqrt(x); ++i) {
        if(x%i == 0){
            div.insert(i);
            div.insert(x/i);
        }
    }

    for(auto i{div.begin()}; i!=div.end(); ++i){
        cout << *i << endl;
    }

    return 0;
}