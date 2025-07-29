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

    while(x != 2){
        double a, sum = 0;
        bool flagb = false;
        
        while(!(!flagb && sum != 0)){
        cin >> a;
        
        if(a >= 0 && a <= 10){
            sum += a;
            flagb = !flagb;
        } else {
            cout << "nota invalida" << endl;
        }

        }

        cout << "media = " << precise << sum/2 << endl;
        x = 0;
        while(x != 1 && x != 2){
            cout << "novo calculo (1-sim 2-nao)" << endl;
            cin >> x;
        }
    }

    return 0;
}