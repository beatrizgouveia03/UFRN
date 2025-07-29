#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll long long int
#define str string
#define ct cout << 
#define l << endl
#define precise fixed << setprecision(1)

int main() {
    dd a, b, c;

    cin>>a>>b>>c;

    (a+b > c && b+c > a && a+c > b) ?
     ct "Perimetro = " << precise << a+b+c l :
     ct "Area = " << precise << (a+b)*c/2 l;


    return 0;
} 