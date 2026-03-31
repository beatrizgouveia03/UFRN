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

signed main(){ _ 
    int n; 

    while(in n){
        int m = n/2, t = n/3;

        for(auto i{0}; i<n; i++){
            for(auto j{0}; j<n; j++){
                if(i == m && j == m){ out 4; } 
                else if(i >= t && i < n-t && j >= t && j < n-t){ out 1;}
                else if(i == j){ out 2;}
                else if(i+j == n-1){ out 3;}
                else{ out 0;}
            }
            out endl;
        }   
        out endl;  
    }
}