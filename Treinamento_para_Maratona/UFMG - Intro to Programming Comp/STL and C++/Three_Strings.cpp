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
    int n; cin >> n;

    for(auto i{0}; i<n; ++i){
        string a, b, c; cin >>a>>b>>c;
        bool flag = false;

        for(auto i{0u}; i<c.size(); ++i){
            if(c[i] != a[i] && c[i] != b[i]){
                cout << "NO" << endl;
                flag = true;
                break;
            } 
        }

        if(!flag) cout << "YES"<< endl;

    }

    return 0;
}

//Codeforces Round 619 (Div. 2) - A