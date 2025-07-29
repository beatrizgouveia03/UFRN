#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n; cin >> n;
    vector<ll> prices(n+1);
    
    for(auto i{0}; i<n; ++i) cin >> prices[i];

    sort(prices.begin(),prices.begin()+n, greater<>());

    ll maxAmount = 0, maxPrice = 0;

    for(auto i{0}; i<n; ++i){
        if(maxAmount < (i+1)*prices[i]){
            maxAmount = (i+1)*prices[i];
            maxPrice = prices[i];
        }
    }

    cout << maxPrice << " " << maxAmount << endl;

    return 0;
}