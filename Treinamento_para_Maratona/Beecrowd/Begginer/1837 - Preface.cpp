#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << '\n'
#define dd double
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(1)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    int a, b; in a >> b;

    int q;

    if(a>=0){
        if(b>=0){ q=a/b;}
        else{ q=ceil((double)a/b);}
    } else {
        if(b>=0){ q=floor((double)a/b);}
        else{ q=ceil((double)a/b);}
    }

    out q << " " << a-(b*q) end;
}