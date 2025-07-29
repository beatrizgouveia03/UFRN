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
    ll h0,m0,h1,m1;

    ci h0 >> m0 >> h1 >> m1;
    
    ct "O JOGO DUROU ";

    if(h0 == h1){
        if(m0 > m1) ct "23 HORA(S) E " << (60-m0)+m1;
        else if(m0<m1)ct "0 HORA(S) E " << m1-m0;
        else ct "24 HORA(S) E 0";
    } else if(h0<h1){
        if(m0 > m1) ct  (h1-h0)-1 << " HORA(S) E " << (60-m0)+m1;
        else ct (h1-h0) << " HORA(S) E " << (m1-m0);
    } else{
        if(m0 > m1) ct  ((23-h0)+h1) << " HORA(S) E " << (60-m0)+m1;
        else ct ((24-h0)+h1)<< " HORA(S) E " << (m1-m0);
    }

    ct " MINUTO(S)" end;
    
    return 0;
} 