#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)

int main() {
    dd x, y, z;

    cin >> x >> y >> z;

    cout << "TRIANGULO: " << precise << (x*z)/2 << "\n";
    cout << "CIRCULO: " << precise << 3.14159*pow(z,2) << "\n";
    cout << "TRAPEZIO: " << precise << ((x+y)*z)/2 << "\n";
    cout << "QUADRADO: " << precise << pow(y, 2) << "\n";
    cout << "RETANGULO: " << precise << x*y << "\n";

    return 0;
}