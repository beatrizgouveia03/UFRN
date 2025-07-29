#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(2)
int main() {
    dd x;
    dd notas[] = {100, 50, 20, 10, 5, 2};
    dd moedas[] = {1, 0.5, 0.25, 0.1, 0.05, 0.01};

    cin >> x;

    cout << precise << "NOTAS:\n";

    for(dd nota : notas){
        cout << int(x/nota) << " nota(s) de R$ " << nota << "\n";
        x -= nota * int(x/nota);
    } 

    cout << "MOEDAS:\n";

    for(dd moeda : moedas){
        dd res = x/moeda;
        cout << res << " moeda(s) de R$ " << moeda << "\n";
        x -= moeda * int(x/moeda);
    }

    cout << x << "\n";
    
    return 0;
}