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


signed main(){ _ 
    ll n; in n;
    ll a; in a;
    
    REP(i,1,n){
        ll b; in b;
        if(b<a){
            out i+1 end;
            return 0;
        }
        a=b;
    }

    out 0 end;    
}