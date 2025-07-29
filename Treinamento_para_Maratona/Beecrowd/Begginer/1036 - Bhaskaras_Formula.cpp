#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define precise fixed << setprecision(5)

int main() {
    dd a, b, c;
    dd res;

    cin >> a >> b >> c;

    (a == 0 || (pow(b, 2) - 4*a*c) < 0) ? cout << "Impossivel calcular\n" : 
     cout << precise << "R1 = " <<((-b + sqrt(b*b - 4*a*c))/(2*a)) 
     << "\nR2 = " << ((-b - sqrt(b*b - 4*a*c))/(2*a)) << endl;


    return 0;
} 