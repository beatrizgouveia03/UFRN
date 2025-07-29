#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ll n; cin >> n;

    vb sadP(n+1, false);
    set<ll> order;
    vector<ll> entry(n+1);
    queue<pair<ll,ll>> playlist;
    map<ll, pair<ll, ll>> inter;    

    for (auto i{0}; i < n; i++)
    {
        ll time, music, skip;
        cin >> time >> music >> skip;

        entry[i] = time;
        order.insert(time);
        inter[time] = {music, skip}; 
    }

    ll time = *order.begin(), sad = 0;
    playlist.push({time,inter[time].f});
    order.erase(order.begin());

    ll aux = inter[time].f;

    for (auto i{1}; i < n; i++)
    {
        time = *order.begin();
        order.erase(order.begin());
        while(time > playlist.front().s){
            playlist.pop();
            if(playlist.empty()) break;
        }
        if(inter[time].s == 1 && !playlist.empty()){
            sad++;
            sadP[playlist.front().f] = true;
            playlist.pop();
        }

        aux += inter[time].f;
        playlist.push({time, aux});
    }

    cout << sad << endl;

    for(auto i{0}; i<n; ++i) (sadP[entry[i]])?cout << i+1 << " ": cout;

    cout << endl;

    return 0;

    //WRONG
}