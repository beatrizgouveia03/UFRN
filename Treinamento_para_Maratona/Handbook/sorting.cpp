#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define in cin >>
#define out cout << 
#define end << endl
#define pi pair<int,int>
#define vi vector<int>
#define vb vector<bool>
#define REP(i,a,b) for(auto i{a}; i<b; i++)
#define precise fixed << setprecision(4)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef unsigned long long int ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int arr[] = {1,3,8,2,9,2,5,6};
int arr2[] = {1,3,8,2,9,2,5,6};
int arr3[] = {1,3,8,2,9,2,5,6};
int arr4[] = {1,3,8,2,9,2,5,6};

void bubble_sort(){
   int n = 8;

   out "BUBBLE SORT: " end;

   REP(i, 0, n){
    REP(j, 0, n-1){
        if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }

    REP(i,0,8){ out arr[i] << " ";}
    out endl;
   }
}


void merge_sort(){
    int n = 8;

    out "MERGE SORT: " end;


}

void lower_bound(){

}

void binary_search1(int x){
    int a = 0, b = 8;

    while(a<=b){
        int k = (a+b)/2;

        if(arr[k] == x){out k end; return;}

        if(arr[k] > x) b = k-1;
        else a = k+1;
    }
}

void binary_search2(int x){
    int k = 0, n = 8;

    for(int b = n/2; b>=1; b/=2){
        while(k+b < n && arr[k+b] <= x) k+=b;
    }

    if(arr[k] == x) out k end;
}

void counting_sort(){
    int n = 8;
    int arr_count[] = {0,0,0,0,0,0,0,0,0,0};

   out "COUNTING SORT: " end;

   REP(i, 0, n){arr_count[arr4[i]]++;}
   
    
    REP(i,1,10){ out arr_count[i] << " ";}
    out endl;

    int i = 1;

    while(i<=9){
        if(arr_count[i] == 0) {i++; continue;}

        out i << " ";
        arr_count[i]--;
    }

    out endl;
}

signed main(){ _ 
    int n = 8, x = 2;

    bubble_sort();  
    counting_sort();

   
    binary_search1(x);
    binary_search2(x);

    auto k = lower_bound(arr, arr+n, x)-arr;
    if(k<8 && arr[k] == x) out k end; // First element x

    auto a = lower_bound(arr, arr+n, x);
    auto b = upper_bound(arr, arr+n, x);
    out (b-a) end; // Number of elements x

    auto r = equal_range(arr, arr+n, x);
    out (r.S - r.F) end; // Number of elements x but shorter
}