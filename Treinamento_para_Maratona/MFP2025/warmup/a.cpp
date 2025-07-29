#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    ii p1, p2, p3, p4;
    cin >> p1.f >> p1.s;

    int auxX, auxY, h=0, w=0;

    while(cin>>auxX>>auxY){
        if(auxX == p1.f){
            w = abs(abs(auxY) - abs(p1.s));
        } else if(auxY == p1.s){
            h = abs(abs(auxX) - abs(p1.f));
        } else {
           continue;
        }

        if(h != 0 && w != 0) break;
    }
    
    cout << w*h << endl;
   
}