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
#define vs vector<string>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int count = 0;
    for (auto i{0}; i < 6; ++i){
        double aux; cin >> aux;
        (aux>0)?count++:0;
    }

    cout << count << " valores positivos" << endl;

    return 0;
}