#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define precise fixed << setprecision(2)

int main() {
    ll a, b, c, d;
    str res;

    cin >> a >> b >> c >> d;

    res = (b>c && d>a && (c+d)>(a+b) && c>0 && d>0 && a%2 == 0) ? "Valores aceitos" : "Valores nao aceitos";

    cout << res << endl;

    return 0;
}