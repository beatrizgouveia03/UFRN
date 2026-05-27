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

typedef unsigned long long int ll;

ll mtx[110][110];

string check(ll x, ll y){
    ll safe = mtx[x][y]+mtx[x][y+1]+mtx[x+1][y]+mtx[x+1][y+1];

    if(safe >= 2) return "S";
    else return "U";
}


signed main(){ _ 
    ll n; in n;

    REP(i,0,n+1){
        REP(j,0,n+1){
           in mtx[i][j];
        }
    }
    
    REP(i,0,n){
        REP(j,0,n){
            out check(i,j);
        }
        out endl;
    }
}