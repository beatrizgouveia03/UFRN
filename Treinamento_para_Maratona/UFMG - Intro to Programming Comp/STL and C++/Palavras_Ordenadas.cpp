#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _ 
    int n; cin>>n;

    for(int i{0}; i<n; ++i){
        string a; cin >> a;
        if(a.size() == 1) {
            cout << a << ": O" << endl;
            continue;
        }

        bool flag{true};

        for(auto i{1u}; i< a.size();  ++i){   
            if(tolower(a[i]) <= tolower(a[i-1])){
                cout << a << ": N" << endl;
                flag = false;
                break;
            }
        }

        if(flag) cout << a << ": O" << endl;
    }

    return 0;
}

//SPOJ PALAVRMG