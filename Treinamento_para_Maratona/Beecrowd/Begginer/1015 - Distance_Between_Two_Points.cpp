#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(4)

int main() {
    dd x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    cout << precise << sqrt(pow(x2-x1, 2)+pow(y2-y1,2)) << "\n";

    return 0;
}