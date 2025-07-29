#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _ 
    int n; cin>> n;
    vector<ii> botas(61, {0,0});

    for(auto i{0u}; i<n; ++i){
        int tam; cin >> tam;
        char pe; cin >> pe;

        (pe == 'E') ? botas[tam].f++ : botas[tam].s++;
    }

    int res = 0;

    for(auto i{0u}; i<botas.size(); ++i){
        res += min(botas[i].f, botas[i].s);
    }

    cout << res << endl;

    return 0;

    //OBI 2017 Fase 1 - A
}