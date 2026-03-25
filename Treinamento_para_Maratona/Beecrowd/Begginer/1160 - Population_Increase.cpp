#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << endl
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
   int amount_tests;
   in amount_tests;

   while(amount_tests--){
      int population_a, population_b;
      double growth_a, growth_b;
      in population_a >> population_b >> growth_a >> growth_b;

      int years = 0;
      while(population_a <= population_b){
         population_a += (population_a * growth_a) / 100.0;
         population_b += (population_b * growth_b) / 100.0;
         years++;

         if(years > 100){
            break;
         }
      }

      if(years > 100){
         out "Mais de 1 seculo." end;
      } else {
         out years << " anos." end;
      }
   }
   
}