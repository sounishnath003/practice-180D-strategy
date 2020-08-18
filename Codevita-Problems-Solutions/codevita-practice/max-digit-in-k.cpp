#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void go(long long &n, int &k) {
    vector<int> nums;
    if (nums.size() == k) {cout << n ; return ;}
    while(n) { nums.push_back(n%10) ; n/= 10 ; }
    auto start = nums.begin(), end = nums.end() ;
    while(k>0) {
        int maxV = *max_element(start, end - k +1) ;
        cout << maxV ;
        start = find(start, end - k + 1, maxV) ;
        start++ ; k-- ;
    }
}   


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    long long num = 71829873395 ;
    int k = 3 ;

    go(num, k) ;
    return 0;
}
