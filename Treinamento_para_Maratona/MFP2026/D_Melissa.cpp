#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v;
    for (int i=0; i<n; i++){
        int a;
        cin >> a;
        v.emplace_back(a);
    }

    sort(v.begin(), v.end());

    if(n == 1){
        cout << 1;
    }    
    else{
        int min = v[0];
        bool b = true;
        while (min>1){
            for (int i=0; i<n; i++){
                if(v[i]%min != 0){
                    i = -1;
                    min--;
                    b = false;
                    continue;
                }
            }

            b = true;
            if (b == true){
                break;
            }
        }

        int soma = 0;
        for (int c: v){
            soma += c;
        }

        cout << soma/min;
    }
}