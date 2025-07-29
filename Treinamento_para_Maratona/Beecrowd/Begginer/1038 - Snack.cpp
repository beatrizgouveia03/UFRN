#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define precise fixed << setprecision(2)

int main() {
    dd price[] = {4.0,4.5,5.0,2.0,1.5};
    ll x, y;

    cin >> x >> y;

    cout <<  precise << "Total: R$ " << y*price[x-1] << endl;


    return 0;
} 