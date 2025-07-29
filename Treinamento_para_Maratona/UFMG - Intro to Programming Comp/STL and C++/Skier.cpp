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

struct node{
    bool n, s, e, w;
};


int main(){ _ 
    int n; cin >> n;

    for(auto i{0}; i<n; ++i){
        string path; cin >> path;
        int x = 0, y = 0, time = 0;
        map<ii, node> visited;

        for(auto i{0u}; i< path.size(); ++i){
            char way = path[i];

            switch (way)
            {
            case 'N':
                visited[{x, y}].s = true;
                x++;
                if(!visited[{x, y}].n){
                    time += 5;
                    visited[{x, y}].n = true;
                } else time += 1;
                break;
            case 'S':
                visited[{x, y}].n = true;
                x--;
                if(!visited[{x, y}].s){
                    time += 5;
                    visited[{x, y}].s = true;
                } else time += 1;
                break;
            case 'E':
                visited[{x, y}].w = true;
                y++;
                if(!visited[{x, y}].e){
                    time += 5;
                    visited[{x, y}].e = true;
                } else time += 1;
                break;
            case 'W':
                visited[{x, y}].e = true;
                y--;
                if(!visited[{x, y}].w){
                    time += 5;
                    visited[{x, y}].w = true;
                } else time += 1;
                break;
            default:
                break;
            }     
        }

        cout << time << endl;
    }

    return 0;
}

//Testing Round 16 (Unrated) - C