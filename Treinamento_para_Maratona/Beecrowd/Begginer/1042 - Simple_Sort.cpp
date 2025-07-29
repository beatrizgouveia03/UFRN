#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll long long int
#define str string
#define ct cout << 
#define l << endl
#define precise fixed << setprecision(1)

int main() {
    set<ll> list;
    ll res[3], s=0;

    for(auto i{0u}; i<3u; ++i) {
        ll aux;
        cin >> aux;
        list.insert(aux);
        res[s++] = aux;
    }

    for(auto r : list) ct r l;

    ct endl;

    for(auto r : res) ct r l;


    return 0;
} 