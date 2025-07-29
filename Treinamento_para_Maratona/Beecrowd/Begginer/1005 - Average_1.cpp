#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(5)

int main() {
    dd x, y, media;

    cin >> x >> y;

    media = (x*3.5 + y*7.5)/11.0;

    cout << "MEDIA = " << precise << media << "\n";

    return 0;
}