#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define precise fixed << setprecision(5)

int main() {
    ff x, inter[] = {0,25,50,75,100};

    cin >> x;

    if (x < inter[0] || x > inter[4]) {
        cout << "Fora de intervalo\n";
        return 0;
    }
    for(auto i{1}; i<5; ++i){
        if(x <= inter[i]){
            if(inter[i] == 25) cout << "Intervalo [";
            else cout << "Intervalo (";
            cout  << (int)inter[i-1] << "," << (int) inter[i] << "]\n";
            break;
        }
    }
     

    

    return 0;
} 