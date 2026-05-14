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

bool compare(pi a, pi b){
    return (a.F*b.S > b.F*a.S);
}

signed main(){ _ 
    ll n, k; in n >> k; // n eh a quant de melacias e k eh a quant de quilos 

    pi watermelons[n];

    REP(i,0,n) in watermelons[i].F >> watermelons[i].S; //Semente e depois quilos

    sort(watermelons, watermelons+n, compare);



    ll total = 0, seeds = 0;

    REP(i,0,n){
        if(total >= k) break;

        if(total+watermelons[i].S <= k){
            seeds += watermelons[i].F;
            total += watermelons[i].S;
        } else {
            seeds += (k-total)*watermelons[i].F/watermelons[i].S;
            break;     
        }
    } 

    out seeds end;
}