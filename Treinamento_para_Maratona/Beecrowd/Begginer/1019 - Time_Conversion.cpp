#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)


int main() {
    int x;
    int time[3];

    cin >> x;

    time[2] = x%60;
    x /= 60;

    time[1] = x%60;
    x/=60;


    time[0] = x;

    cout << time[0] << ":" << time[1] << ":" << time[2] << "\n";    
   
    return 0;
}