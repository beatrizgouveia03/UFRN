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
    ll n, x; in n >> x;
    vector<ll> arr(n);

    REP(i, 0, n) in arr[i];


    
    vector<ll> sorted = arr;
    
    sort(sorted.begin(), sorted.begin()+n);
    
    auto a = &sorted[0];
    auto b = &sorted[n-1];
    
    while(*a+*b != x && a<b){
        if(*a+*b < x){ a++;}
        else b--;
        
        if(a == b) a++;
    }
    
    
    out *a << " " << *b << " " << *a+*b end;
    
    if(*a+*b != x){ out "IMPOSSIBLE" end; return 0;}

    ll idxA = -1, idxB = -1;

    REP(i, 0, n){
        if(arr[i] == *a) idxA = i+1;
        if(arr[i] == *b) idxB = i+1;
        if(idxA != -1 && idxB != -1) break;
    }

    out min(idxA, idxB) << " " << max(idxA,idxB) end;   
}