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

signed main(){ _ 
   string s;
   vi alphabet(25, 0);

   in s;

   REP(i, 0, s.size()){
        alphabet[s[i]-97]++;
   }

   int even = 0;

   REP(i, 0, 25){
    (alphabet[i]%2 == 0) ? 0 : even++;    
   }

   out ((even >=2)? "no" : "yes") end; 
  
}