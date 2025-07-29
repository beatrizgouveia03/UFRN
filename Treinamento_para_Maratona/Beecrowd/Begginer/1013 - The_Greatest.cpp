#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define str string
#define precise fixed << setprecision(3)

int maiorAB(int a, int b){
    return (a+b+abs(a-b))/2;
}

int main() {
    int x, y, z;

    cin >> x >> y >> z;

    if(maiorAB(x, y) == x) cout << maiorAB(x, z) << " eh o maior\n";
    else cout << maiorAB(y, z) << " eh o maior\n";
   
    return 0;
}