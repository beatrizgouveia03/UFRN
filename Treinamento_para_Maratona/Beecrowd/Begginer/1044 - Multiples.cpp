#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define end << endl
#define precise fixed << setprecision(1)

int main() {
    ll a, b;

    cin >> a >> b;

    (a%b == 0 || b%a == 0) ? ct "Sao Multiplos" end :
    ct "Nao sao Multiplos" end;

    return 0;
} 