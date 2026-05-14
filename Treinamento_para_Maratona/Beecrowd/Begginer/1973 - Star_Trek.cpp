#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in cin >>
#define out cout << 
#define end << endl
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(2)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    ll n; in n;

    ll stars[n], total_sheep = 0;
    bool visited[n] = {false};

    REP(i,0,n){
        in stars[i];
        total_sheep+=stars[i];
    }

    ll idx = 0, count = 0;

    while(true){
        ll next_idx = (stars[idx]%2 == 0)? idx-1 : idx+1;
        
        if(stars[idx]>0) {
            total_sheep--;
            stars[idx]--;
        }

        if(!visited[idx]){
            visited[idx] = true;
            count++;
        }

        if(next_idx < 0 || next_idx >= n) break;
        idx = next_idx;
    }

    out count << " " << total_sheep end;
}