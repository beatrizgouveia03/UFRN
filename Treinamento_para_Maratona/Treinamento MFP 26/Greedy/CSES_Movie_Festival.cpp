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
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool compare(pi a, pi b) { return a.S < b.S; }

signed main(){ _ 
    ll n; in n;

    pi movies[n];

    REP(i,0,n) in movies[i].F >> movies[i].S;

    sort(movies, movies+n, compare);

    //REP(i,0,n) out i << ": " << movies[i].F << ", " << movies[i].S end;     

    ll track = 0, count = 0;

    REP(i,0,n){
        if(movies[i].F >= track) {
            track = movies[i].S;
            count++;
        }
    }

    out count end;
}