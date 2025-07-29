#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(2)

int main() {
    dd price1, price2;
    int id1, amount1, id2, amount2;

    cin >> id1 >> amount1 >> price1;
    cin >> id2 >> amount2 >> price2;

    cout << "VALOR A PAGAR: R$ " << precise << amount1*price1+amount2*price2 << "\n";

    return 0;
}