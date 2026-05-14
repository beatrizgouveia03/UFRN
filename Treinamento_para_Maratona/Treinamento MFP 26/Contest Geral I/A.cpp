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
    ifstream iarq("bcount.in");
    ofstream oarq("bcount.out");

    if(iarq.is_open()){    
        int n, q; iarq >> n >> q;
    
        int t[n+1][3];
        int c[3] = {0,0,0};

        t[0][0] = 0;
        t[0][1] = 0;
        t[0][2] = 0;

        REP(i,1,n+1) {
            int x; iarq >> x;
            c[x-1]++;

            t[i][0] = c[0];
            t[i][1] = c[1];
            t[i][2] = c[2];
        }

        while(q--){
            int a, b; iarq >> a >> b;

            if(oarq.is_open()){
                oarq << t[b][0]-t[a-1][0] << " " << t[b][1]-t[a-1][1] << " " << t[b][2]-t[a-1][2] end;
            }
        }
        oarq.close();
        iarq.close();
    } 


}