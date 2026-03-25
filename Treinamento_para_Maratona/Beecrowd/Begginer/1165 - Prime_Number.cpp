#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << endl
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    int cases;
    in cases;

    while(cases--){
        int n;
        in n;

        bool prime = true;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){
                prime = false;
                break;
            }
        }

        out n;
        (prime && n > 1) ?  out " eh primo" end : out " nao eh primo" end;
    }
}