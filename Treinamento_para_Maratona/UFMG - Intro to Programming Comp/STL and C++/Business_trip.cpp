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
    int k; cin >> k;

    vi growth(13);
    int sum = 0, res = 0;

    for(auto i{0}; i<12; ++i){
        cin >> growth[i];
        sum += growth[i];
    }

    if(sum < k) {
        cout << -1 << endl;
        return 0;
    }

    sort(growth.begin(), growth.end(), greater<>());

    sum = 0;
    while(sum < k){
        sum += growth[res++];
    }

    cout << res << endl;

    return 0;
}

//Codeforces Round 106 (Div. 2) - A>