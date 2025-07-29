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
#define precise fixed << setprecision(1) 

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    double a; cin >> a;

    for(auto i{0}; i<a; ++i) {
        double aux, sum = 0.0;
        vector<double> w = {2.0, 3.0, 5.0};
        for(auto j{0}; j<3; ++j){
            cin >> aux;
            sum += (aux*w[j]);        
        }
        cout << fixed << precise << sum/10.0 << endl;
    }    

    return 0;
}