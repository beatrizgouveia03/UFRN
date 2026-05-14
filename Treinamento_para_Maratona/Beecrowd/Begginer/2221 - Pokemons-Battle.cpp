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

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


signed main(){ _ 
    int cases; in cases;

    while(cases--){
        int bonus; in bonus;
        int a1,a2,d1,d2,l1,l2; 
        in a1 >> d1 >> l1;
        in a2 >> d2 >> l2;

        int t1 = (a1+d1)/2, t2=(a2+d2)/2;

        if(l1%2 == 0) t1+=bonus;
        if(l2%2 == 0) t2+=bonus;

        if(t1==t2) out "Empate" end;
        else if(t1>t2) out "Dabriel" end;
        else out "Guarte" end;
    }
}