#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second 
#define ii pair<int,int> 
#define v vector<int> 
#define ll long long unsigned
#define endl "\n"

int main(){
    v entry(2, 0);

    for(int i{0}; i<3; ++i){
        int a; cin >> a;
        if(a == 5) entry[0]++;
        else if(a == 7) entry[1]++;
    }

    if(entry[0] == 2 && entry[1] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;

    exit(0);
}