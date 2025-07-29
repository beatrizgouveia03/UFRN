#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int, int>
#define vi vector<int>
#define precise setprecision(2) 

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    ll a; cin >> a;
    ll in = 0;
    for(auto i{0}; i<a; ++i) {
        ll aux; cin >> aux;
        (aux>=10 && aux <=20)? in++: 0;
    }

    cout << in << " in" << endl;
    cout << a-in << " out" << endl;
    

    return 0;
}