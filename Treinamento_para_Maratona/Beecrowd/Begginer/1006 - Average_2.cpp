#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(1)

int main() {
    dd x, y, z, media;

    cin >> x >> y >> z;

    media = (x*2.0 + y*3.0 + z*5.0)/10.0;

    cout << "MEDIA = " << precise << media << "\n";

    return 0;
}