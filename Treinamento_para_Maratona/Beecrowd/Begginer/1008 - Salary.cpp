#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(2)

int main() {
    int num, hours;
    dd salary;

    cin >> num >> hours >> salary;

    cout << "NUMBER = " << num;
    cout << "\nSALARY = U$ " << precise << hours*salary << "\n";

    return 0;
}