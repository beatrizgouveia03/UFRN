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
   ll p = 0;

   ci s;
   
   if(s <= 2000) p = 1;
   else {
    if(s <= 3000) r = (s-2000) * 0.08;
    else if(s <= 4500) r = 80 + (s-3000) * 0.18;
    else r = 350 + (s-4500) * 0.28;
   }

   (p) ? ct "Isento" end : ct "R$ " << precise << r end;
  
    return 0;
} 