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

signed main(){ _     
    int n, m; in n >> m;
    vector<string> plates;
    vector<string> colors;
    map<string, int> values;
    
    while(n--) {
        string x; in x; plates.PB(x); values.insert({x, -1});
    }
    

    while (m--)
    {
        string x; in x; colors.PB(x); 
    }

    
    int other; in other;
    
    REP(i,0,colors.size()){
        int x; in x; values[(colors[i])] = x;
    }

    int sum = 0;

    REP(i,0,plates.size()){
        if(values[plates[i]] != -1) sum+=values[plates[i]];
        else sum += other;
    }

    out sum end;

}