#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define ci cin >>
#define end << endl
#define precise fixed << setprecision(2)

int main() {
    str a,b,c;

    ci a>>b>>c;

    if(a[0] == 'v'){
        if(b[0] == 'a'){
            (c[0] == 'c') ? ct "aguia" end : ct "pomba" end;
        } else {
            (c[0] == 'o') ? ct "homem" end : ct "vaca" end;
        }

    } else{
         if(b[0] == 'i'){
            (c[2] == 'm') ? ct "pulga" end : ct "lagarta" end;
        } else {
            (c[0] == 'h') ? ct "sanguessuga" end : ct "minhoca" end;
        }
    }
   
    return 0;
} 