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

    ll x, y; cin >> x >> y;

    for(ll i{1u}; i<=y;) {
        cout << i++;
        for(auto j{1}; j<x; ++j){
            cout << " " << i++;
        }
        cout << endl;
    }

    return 0;
}