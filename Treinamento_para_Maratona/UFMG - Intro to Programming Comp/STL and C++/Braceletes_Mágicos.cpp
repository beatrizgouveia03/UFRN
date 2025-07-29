#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define ii pair<int,int>
#define vi vector<int>
#define vb vector<bool>

typedef long long unsigned ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main(){ _ 
    int n; cin>>n;

    for(int i{0}; i<n; ++i){
        string proib, brac; cin >> proib >> brac;

        brac += brac;

        ll seq = 0, antiseq = 0;
        bool flag{true};

        for(auto i{0u}; i<brac.size(); ++i){
            if(brac[i] == proib[seq]) seq++;
            else seq = 0;

            if(brac[brac.size()-i] == proib[antiseq])antiseq++;
            else antiseq = 0;

            if(seq == proib.size() || antiseq == proib.size()){
                cout << "S" << endl;
                flag = false;
                break;
            }

        }

        if(flag) cout << "N" << endl;
    }

    return 0;


//SPOJ BRACELMG
}