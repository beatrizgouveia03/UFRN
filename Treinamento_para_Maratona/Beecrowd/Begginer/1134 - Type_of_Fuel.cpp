#include <bits/stdc++.h>

using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
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

    vi fuel(3, 0);
    int x; cin >>x;

    while(x != 4){
        (x >0 && x<4)? fuel[x-1]++ : 0; 
        cin >> x;
    }

    cout << "MUITO OBRIGADO" << endl;
    cout << "Alcool: " << fuel[0] << endl;
    cout << "Gasolina: " << fuel[1] << endl;
    cout << "Diesel: " << fuel[2] << endl;

    return 0;
}