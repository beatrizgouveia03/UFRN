#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define MAX 100

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _
    int n;
    cin >> n;

    while (n--)
    {
        int a, b;
        cin >> a >> b;

        for(int i=0; i<a; ++i){
            for(int j=0; j<b; ++j){
                if(!i && !j) cout << 'W';
                else cout << 'B';
            }
            cout << endl;
        }
    }

    return 0;
}

//Codeforces Round 632 (Div. 2) - A>