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
    int c; cin >> c; 

    while(c > 0){
        int x, y; cin >> x >> y;
        int sum = 0;

        if(x%2 == 0) x++;

        for(auto i{0u}; i<y; ++i){
            sum += x;

            x+=2;
        }

        cout << sum << endl;
    
        --c;
    }

    return 0;
}