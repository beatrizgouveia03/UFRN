#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int, int>
#define vi vector<int>
#define  precise fixed << setprecision(2) 

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    int x = 1;
    int inter = 0, gremio = 0, emp = 0; 

    while(x != 2){
        int i, g; cin >> i >> g;

        (i > g)? inter++ : (i == g)?emp++ : gremio++;

        x = 0;
        while(x != 1 && x != 2){
            cout << "Novo grenal (1-sim 2-nao)" << endl;
            cin >> x;
        }
    }

    cout << inter+gremio+emp << " grenais" << endl;
    cout << "Inter:" << inter << endl;
    cout << "Gremio:" << gremio << endl;
    cout << "Empates:" << emp << endl;

    int maxV = max({inter, gremio, emp});

    ( maxV == inter)?cout << "Inter venceu mais" << endl:
        (maxV == gremio)? cout << "Gremio venceu mais" << endl : cout << "Não houve vencedor" << endl;

    return 0;
}