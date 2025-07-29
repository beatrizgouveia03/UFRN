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

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _
    
    int x; cin >> x;

    vi fib(46);

    fib[0] = 0;
    fib[1] = 1;

    for(auto i{2u}; i<x; ++i) {
        fib[i] = fib[i-1]+fib[i-2];
    
    }

    cout << fib[0];
    for(auto i{1u}; i<x; ++i) {
        cout << " " << fib[i];
    
    }

    cout << endl;

    return 0;
}