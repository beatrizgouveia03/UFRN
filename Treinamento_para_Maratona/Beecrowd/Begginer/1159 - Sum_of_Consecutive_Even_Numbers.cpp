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
    int x; cin >> x; 

    while(x != 0){
        int sum = 0;

        if(x%2 != 0) x++;

        for(auto i{0u}; i<5; ++i){
            sum += x;

            x+=2;
        }

        cout << sum << endl;
    
        cin >> x;
    }

    return 0;
} 