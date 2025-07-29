#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define MAX 100

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    ll n; cin >> n;
    while (n--)
    {
        ll m; cin >> m;
        vector<ll> res(m+1);
        for(auto i{0}; i<m; ++i){
            cin >> res[i];           
        }

        sort(res.begin(), res.begin()+m);


        ll mid = m/2;

        cout << res[mid] << " ";

        for(auto i{1}; i <= m/2; ++i){
            if (mid - i >= 0) cout << res[mid-i] << " ";
            if(mid+i < m) cout << res[mid+i] << " ";
        }
        cout << endl;

    }

    return 0;
}

//Codeforces Round 633 (Div. 2) - B>