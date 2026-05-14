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
    int n; in n;
    map<pair<int, int>,int> coord;
    
    int x=0, y=0;
    coord[{x,y}]++;

    while(n--){
        char m; in m;

        if(m == 'R') x++; 
        else if(m == 'L') x--;
        else if(m == 'U')  y++;
        else y--;

        coord[{x,y}]++;

        if(coord[{x,y}] > 1){ out "Yes" end; return 0; }
    }

    out "No" end;


}