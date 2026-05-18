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
    ll multiple[6] = {0};

    REP(i,0,n){
        ll x; in x;
        if(x%2 == 0) multiple[2]++;
        if(x%3 == 0) multiple[3]++;
        if(x%4 == 0) multiple[4]++;
        if(x%5 == 0) multiple[5]++;
    }

    REP(i,2,6){
        out multiple[i] << " Multiplo(s) de " << i end;
    }
}