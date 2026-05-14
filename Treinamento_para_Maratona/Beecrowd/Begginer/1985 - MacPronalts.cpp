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

double menu[] = {1.50, 2.50, 3.50,4.50,5.50};

signed main(){ _ 
    ll n; in n;

    ll code, amount;
    double total = 0;

    REP(i,0,n){
        in code >> amount;

        total+=menu[code-1001]*amount;
    }
    
    out precise << total end;
}