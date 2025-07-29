#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define end << endl
#define precise fixed << setprecision(1)

int main() {
    dd x, y;

    cin >> x >> y;

    if(x == 0 || y == 0){
        if(x+y == 0) ct "Origem" end;
        else if(x == 0) ct "Eixo Y" end;
        else ct "Eixo X" end; 

        return 0;   
    } 
    
    if(x > 0){
        (y > 0) ? ct "Q1" end : ct "Q4" end;

    } else {
        (y > 0) ? ct "Q2" end : ct "Q3" end;

    }

    return 0;
} 