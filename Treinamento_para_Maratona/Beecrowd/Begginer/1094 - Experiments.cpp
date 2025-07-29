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

    ll total = 0;
    ll a; cin >> a;
    map<char, int> animals;

    for(auto i{0}; i<a;++i){
        char idx; int amt;
        cin >> amt >> idx;

        total+=amt;
        animals[idx]+=amt;
    }

    cout << "Total: " << total << " cobaias" << endl;
    cout << "Total de coelhos: " << animals['C'] << endl;
    cout << "Total de ratos: " << animals['R'] << endl;
    cout << "Total de sapos: " << animals['S'] << endl;
    cout << precise;
    cout << "Percentual de coelhos: " << (animals['C']/(double)total)*100 << " %" << endl;
    cout << "Percentual de ratos: " << (animals['R']/(double)total)*100 << " %" << endl;
    cout << "Percentual de sapos: " << (animals['S']/(double)total)*100 << " %" << endl;

    return 0;
}