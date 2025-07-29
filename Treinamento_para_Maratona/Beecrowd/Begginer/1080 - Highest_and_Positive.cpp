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
#define precise setprecision(1) 

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    ll aux, hst = 0, idx = -1;

   for(auto i{0}; i<100; ++i){
        cin >> aux;
        (aux > hst)? hst = aux, idx = i+1: 0;
    }

    cout << hst << endl << idx << endl;

    return 0;
}