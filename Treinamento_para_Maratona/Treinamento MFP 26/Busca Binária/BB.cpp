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
 
int bb(int interval[], int size, int x){
    int first = 0, last = size-1, mid = 0;

    while(last >= first){
        mid = first + (last-first)/2;

        if(x > interval[mid]){
            first = mid+1;
        } else{
            last = mid-1;
        }
    }

    return first;
}

signed main(){
    int array[] = {1, 2, 3, 4, 5, 6, 7};
    int target = 4;

    out bb(array, 7, target) end;
}