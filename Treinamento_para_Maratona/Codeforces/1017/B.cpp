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
    int x,n,m,l,r;
    in x;

    while(x--){
        in n >> m >> l >> r;

        int a=0, b=0, c=0;

        while(m--){
            (c++%2 == 0)?a--:b++; 
            out a << " " << b << ' ' << c end;
        } 

        ((l>=0 && al) || (l<0 && a<l))  ? a=l : 0;
        (b>r) ? b=r : 0;

        //out a << " " << b end;
    }

}