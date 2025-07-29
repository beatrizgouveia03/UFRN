#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int, int>
#define vi vector<int>
#define vs vector<string>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){_
    vs month = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int n; cin >> n;
    cout << month[n-1] << endl;

    return 0;
}