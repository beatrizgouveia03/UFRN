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
    dd a, b, c;

    cin >> a >> b >> c;

    if(a < b){ dd aux = a; a = b; b=aux; }

    if(a < c){ dd aux = a; a = c; c=aux; }

    if(a >= b+c) ct "NAO FORMA TRIANGULO" end;
    else if(pow(a,2) == pow(b,2) + pow(c,2)) ct "TRIANGULO RETANGULO" end;
    else if(pow(a,2) > pow(b,2) + pow(c,2)) ct "TRIANGULO OBTUSANGULO" end;
    else if(pow(a,2) < pow(b,2) + pow(c,2)) ct "TRIANGULO ACUTANGULO" end;

    if(a == b && b == c) ct "TRIANGULO EQUILATERO" end;
    else if( (a == b) | (b == c) | (a == c)) ct "TRIANGULO ISOSCELES" end;

    return 0;
} 