#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    string a;
    double b, c;
    cin >> a >> b >> c;
    cout << "TOTAL = R$ " << fixed << setprecision(2) << b + (c * 0.15) << endl;
}