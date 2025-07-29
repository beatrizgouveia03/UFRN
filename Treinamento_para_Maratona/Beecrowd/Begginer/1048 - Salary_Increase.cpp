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
   dd s, r;
   ll p;

   ci s;

   if(s <= 400) p=15;
   else if(s<=800) p=12;
   else if(s<=1200) p=10;
   else if(s <= 2000) p=7;
   else p=4;

   r = p/100.0*s;


   ct "Novo salario: " << precise << s+r end; 
   ct "Reajuste ganho: " << r end;
   ct "Em percentual: " << p << " %" end;

    return 0;
} 