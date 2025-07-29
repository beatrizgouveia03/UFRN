#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define ci cin >>
#define l << endl
#define precise fixed << setprecision(2)

int main() {
   map<int, string> ddd;

   ddd[61] = "Brasilia";
   ddd[71] = "Salvador";
   ddd[11] = "Sao Paulo";
   ddd[21] = "Rio de Janeiro";
   ddd[32] = "Juiz de Fora";
   ddd[19] = "Campinas";
   ddd[27] = "Vitoria";
   ddd[31] = "Belo Horizonte";

   ll in;

   ci in;

   if(ddd.find(in) != ddd.end()) ct ddd[in] l;
   else ct "DDD nao cadastrado" l;
   
    return 0;
} 