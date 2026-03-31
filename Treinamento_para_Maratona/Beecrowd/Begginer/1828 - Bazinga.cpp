#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define in cin >>
#define out cout << 
#define end << '\n'
#define dd double
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define precise fixed << setprecision(1)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

string play[5] = {"pedra", "papel", "tesoura", "lagarto", "Spock"};

int res[5][5] = {{  0, -1,  1,  1, -1},
                 {  1,  0, -1, -1,  1},
                 { -1,  1,  0,  1, -1},
                 { -1,  1, -1,  0,  1},
                 {  1, -1,  1, -1,  0}
                };

int play_to_int(string p){
    for(auto i{0}; i<5; i++){
        if(p == play[i]) return i;
    }

    return 0;
}


signed main(){ _ 
    int n; in n;

    for(auto i{0}; i<n; ++i){
        string sheldon, raj; in sheldon >> raj;

        out "Caso #" << i+1 << ": ";

        int ires = res[play_to_int(sheldon)][play_to_int(raj)];
        
        if(ires == -1){ out "Raj trapaceou!" end;}
        else if (ires == 0){ out "De novo!" end;}
        else{ out "Bazinga!" end;}
    }
    
}