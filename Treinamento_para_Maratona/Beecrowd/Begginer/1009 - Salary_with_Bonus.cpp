#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(2)

int main() {
    str name;
    dd salary, sales;

    cin >> name >> salary >> sales;

    cout << "TOTAL = R$ " << precise << salary+(0.15*sales) << "\n";

    return 0;
}