#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in cin >>
#define out cout << 
#define end << endl
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

pair<string,ll> romans[] = {{"CM", 900},{"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10},{"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

signed main(){ _ 
   ll number; in number;

   string res = "";

   REP(i,0,12){
      while (number >= romans[i].S)
      {
         res += romans[i].F;
         number -= romans[i].S;
      }  

      if(number == 0) break;
   }

   out res end;
}