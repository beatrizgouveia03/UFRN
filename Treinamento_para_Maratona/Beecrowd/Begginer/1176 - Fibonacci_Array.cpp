#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << endl
#define dd double
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(1)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    vector<ll> v(61);

    v[0] = 0;
    v[1] = 1;

    for(int i{2};i<=60;++i){
        v[i] = v[i-1] + v[i-2];
    }

    int n;
    in n;

    for(int i{0};i<n;++i){
        int x;
        in x;
        out "Fib(" << x << ") = " << v[x] end;
    }
}