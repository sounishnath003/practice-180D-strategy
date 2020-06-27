// Merge two sorted Arrays without extra space
#include<bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void mergesort(vector<int>::iterator start, vector<int>::iterator end){
    if(end - start > 1) {
        vector<int>::iterator mid = start + (end - start) / 2 ;
        mergesort(start, mid ) ;
        mergesort(mid , end) ;
        inplace_merge(start, mid, end) ;
    }
}

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> v1 {2,3,5,6,8} ;
    vector<int> v2 {-10,-5,-3,-2,0,7,100} ;
    copy(v2.begin(), v2.end(), back_inserter(v1));
    mergesort(v1.begin(), v1.end()) ;
    for(auto &&i : v1){
        cout << i << " " ;
    }

    return 0;
}
