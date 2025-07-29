#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _ 
    int m; cin >> m;
    int z = 0, n = 0;

    for(auto i{0}; i<m; ++i) 
    {
        char a; cin >> a;
        if(a == 'z') z++;
        if(a == 'n') n++;
    }
        
    for(auto i{0}; i<n; ++i) cout << 1 << " ";
    for(auto i{0}; i<z; ++i) cout << 0 << " ";
    cout << endl;

    return 0;
}

//Codeforces Round 586 (Div.1 + Div. 2) - A>