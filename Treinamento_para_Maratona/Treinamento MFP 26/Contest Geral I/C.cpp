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
    ifstream iarq("hps.in");
    ofstream oarq("hps.out");

    if(iarq.is_open()){
        if( oarq.is_open()){
            int n; iarq >> n;
            int plays[] = {0,0,0}; //Hoof, Paper, Scissors

            while(n--){
                char p; iarq >> p;

                if(p == 'H') plays[0]++;
                else if(p == 'P') plays[1]++;
                else plays[2]++;
            }

            sort(&plays[0], &plays[2]);
            
            oarq << (plays[0]+plays[1]) end;

            oarq.close();
            iarq.close();
        }
    }
    
    
}