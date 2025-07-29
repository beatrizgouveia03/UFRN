#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)

int main() {
    int x;
    int notas[] = {100, 50, 20, 10, 5, 2, 1};

    cin >> x;

    cout << x << "\n";

    for(int nota : notas){
        cout << x/nota << " nota(s) de R$ " << nota << ",00\n";
        x %= nota;
    } 
    
    return 0;
}