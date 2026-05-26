#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define in cin >>
#define out cout <<
#define end << endl
#define vi vector<int>
#define REP(i,a,b) for(auto i{a}; i<b; i++)

typedef unsigned long long int ll;

signed main(){
    ll n; in n;

    ll num_max = INT_MAX;
    ll pile[n];

    REP(i,0,n) {
        in pile[i];
        num_max = min(num_max, pile[i]);
    }

    ll num_cards = 0;

    for(auto i{num_max}; i > 0; i--){
        bool div_all = true;

        REP(j,0,n){
            if(pile[j]%i!=0) {
                div_all = false;
                break;
            }
        }

        if(div_all) {
            num_cards = i;
            break;
        }
    }

    ll res = 0;

    
    REP(i,0,n){
        res += pile[i]/num_cards;
    }


    out res end;
}