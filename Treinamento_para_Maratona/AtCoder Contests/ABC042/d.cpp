#include <bits/stdc++.h>

using namespace std;

#define f first 
#define s second 
#define ii pair<int,int> 
#define v vector<bool> 
#define ll long long unsigned
#define endl "\n"

int main(){ 
   int n, k; cin>>n>>k;
   v d(11, true);

   for(auto i{0}; i<k; ++i){
    int a; cin >> a;
    d[a] = false;
   }

   while(true){
    int temp = n;
    bool flag = true;
    while(temp>0){
        if(!d[temp%10]){
            flag = false; break;
        }
        temp/=10;
    }
    if(flag) break;
    n++;
   }

    cout << n << endl;

    exit(0);
}