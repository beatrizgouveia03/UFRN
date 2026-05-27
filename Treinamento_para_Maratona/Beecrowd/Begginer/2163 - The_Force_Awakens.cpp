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
#define precise fixed << setprecision(10)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

ll mtx[1001][1001]{-1};
ll dir[3] = {-1,0,1};

bool check (ll x, ll y){
    REP(i,0,3){
        REP(j,0,3){
            if(dir[i]==0 && dir[j]==0) continue;
            if(mtx[x+dir[i]][y+dir[j]] != 7) return false;
        }
    }

    return true;
}

signed main(){ 
    ll n,m; in n>>m;

    REP(i,0,n){
        REP(j,0,m){
            in mtx[i][j];
        }
    }

    REP(i,1,n-1){
        REP(j,1,m-1){
            if(mtx[i][j] == 42) {
                bool saber = check(i,j);
                if(saber) {
                    out i+1 << " " << j+1 end;
                    return 0;
                }
            }
        }
    }

    out "0 0" end;
}