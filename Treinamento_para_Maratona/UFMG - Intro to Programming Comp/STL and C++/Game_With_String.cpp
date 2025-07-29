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
    string entry; cin >> entry;
    int c = 0;
    vb inGame(entry.size(), true);

    for(auto i{1u}; i<entry.size(); ++i){
       if(entry[i] == entry[i - (1 + (2 * c))] && inGame[i - (1 + (2 * c))]) {
        inGame[i] = false;
        inGame[i - (1 + (2 * c))] = false;
        c++;
       }
       }

    (c%2 == 0)?cout << "No" << endl : cout << "Yes" << endl;

    return 0;
}

//Codeforces Round 534 (Div. 2) - B>