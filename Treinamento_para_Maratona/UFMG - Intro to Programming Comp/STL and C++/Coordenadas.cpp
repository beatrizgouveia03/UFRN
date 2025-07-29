#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define mi map<int, int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin >> n;
    vi v(n), ordv(n);

    for(auto i{0}; i< n; ++i){cin>>v[i]; ordv[i] = v[i];}

    sort(ordv.begin(), ordv.end());

    mi novoidx;

    for(auto i{0}; i<n; ++i) novoidx[ordv[i]] = i;

    for(auto i{0}; i<n; ++i) v[i] = novoidx[v[i]];

    for(auto i{0}; i<n; ++i) cout << v[i] << " ";
    cout << endl;

    return 0;
}