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

signed main(){ _ 
    ll n; in n;

    REP(i,0,n){
        string s; in s;
        double max_score = -1.0, min_score = 11.0;
        double sum = 0.0, dif;

        in dif;

        REP(j,0,7){
            double x; in x;
            sum += x;
            max_score = max(max_score, x);
            min_score = min(min_score, x);
        }

        out precise << s << " ";
        out (sum-(max_score+min_score))*dif end;
    }
}