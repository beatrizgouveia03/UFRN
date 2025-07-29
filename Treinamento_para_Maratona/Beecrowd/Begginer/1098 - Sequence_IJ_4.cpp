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
#define  precise fixed << setprecision(1) 

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main()
{
    _

    double i = 0, j=1;

    do{
        if((int)(j*10)%10 == 0 || (int)(i*10)%10 == 0)  cout << fixed << setprecision(0); 
        else cout << precise;
        cout << "I=" << i << " J=" << j << endl;
        cout << "I=" << i << " J=" << j+1 << endl;
        cout << "I=" << i << " J=" << j+2 << endl;
        i+=0.2; j+=0.2;

    }while(i <= 2.0);
    
    return 0;
}