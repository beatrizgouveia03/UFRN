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
#define vs vector<string>

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){ _
    string aux; 
    int d1, d2, h1, m1, s1, h2, m2, s2;
    int df, hf, mf, sf;

    cin >> aux >> d1 >> h1 >> aux >> m1 >> aux >> s1;
    cin >> aux >> d2 >> h2 >> aux >> m2 >> aux >> s2;

    (s1 > s2)? sf = 60-s1+s2, mf = 1 : sf = s2-s1, mf = 0;
    (m1 > m2)? mf += 60-m1+m2, hf = 1: mf += m2-m1, hf = 0;
    (h1 > h2)? hf += 24-h1+h2, df = 1: hf += h2-h1, df = 0;
    (d1 < d2)? df += d2-d1-1 : df += 0;


    cout << df << " dia(s)" << endl;
    cout << hf << " hora(s)" << endl;
    cout << mf << " minuto(s)" << endl;
    cout << sf << " segundo(s)" << endl;

    return 0;

    //WRONG
}