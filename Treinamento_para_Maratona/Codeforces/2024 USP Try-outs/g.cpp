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
    ll lastTP = 0, minDist = 0;

    ll pos; cin >> pos;
    minDist += pos;
    
    for(auto i{1}; i<n; ++i){
        ll nextPos; cin >> nextPos;
        if(abs(nextPos-lastTP) <= abs(nextPos-pos)){
            minDist += abs(nextPos-lastTP);
            lastTP = pos;
        }else minDist += abs(nextPos-pos);

        pos = nextPos;
    }

    cout << minDist << endl;

    return 0;

    //WRONG
}