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
    string a, b; 
    ll c = 1;

    while(in a >> b){
        ll count = 0;
        size_t pos = b.find(a, 0);
        size_t last_pos;

        while(pos != string::npos){
            last_pos = pos;
            count++;
            pos = b.find(a, pos+a.length());
        }

        out "Caso #" << c << ":" end;
        if(count == 0) out "Nao existe subsequencia" end;
        else{
            out "Qtd.Subsequencias: " << count end;
            out "Pos: " << last_pos+1 end;
        }
        out endl;

        c++;
    }
}