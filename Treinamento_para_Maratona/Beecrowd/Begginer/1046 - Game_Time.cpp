#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define ci cin >>
#define end << endl
#define precise fixed << setprecision(1)

int main() {
    ll a, b;

    ci a >> b;

    ct "O JOGO DUROU ";

    if( a == b) ct "24 HORA(S)" end;
    else if(a > b) ct ((24-a)+b) << " HORA(S)" end;
    else ct (b-a) << " HORA(S)" end;
    
    return 0;
} 