#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)


int main() {
    int x;
    int age[3];

    cin >> x;

    age[0] = x/365;
    x %= 365;

    age[1] = x/30;
    x%=30;


    age[2] = x;

    cout << age[0] << " ano(s)\n";
    cout << age[1] << " mes(es)\n";
    cout << age[2] << " dia(s)\n";    
   
    return 0;
}