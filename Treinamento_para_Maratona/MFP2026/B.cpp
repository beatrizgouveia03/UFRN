#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in cin >>
#define out cout << 
//#define end << endl
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

signed main(){ _ 
    ll fa[26]{0}, fp[26]{0};

    string a, p; in a >> p;

    REP(i,0,a.size()) fa[a[i]-'a']++;
    REP(i,0,p.size()) fp[p[i]-'a']++;

    ll n; in n;
    REP(i,0,n){
        ll op; in op;
        switch (op) {
            case 1:{
                ll k; 
                string s;
                in k >> s;
                REP(j,0,s.size()) fa[s[j]-'a']+=k;
                break;
            }
            case 2:{
                ll k; 
                string s;
                in k >> s;
                REP(j,0,s.size()) fp[s[j]-'a']+=k;
                break;
            }
            case 3:{
                bool eq = true;
                ll la{-1}, lp{-1};

                REP(i,0,26){
                    if(fa[i]>0)la=i;
                    if(fp[i]>0)lp=i;
                }

                REP(i,0,26){
                    if(fa[i]<fp[i]){
                        eq = false;
                        out ((la<=i)?"ADA":"PY") << endl;
                        break;
                    } else if(fa[i]>fp[i]){
                        eq=false;
                        out ((lp<=i)?"PY":"ADA") << endl;
                        break;
                    }
                }

                if(eq) out "EMPATE" << endl;
                break;
            }
        }
    }   
}