#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)

int main() {
    dd x;

    cin >> x;

    cout << "VOLUME = " << precise << (4.0/3.0)*3.14159*pow(x, 3) << "\n";

    return 0;
}