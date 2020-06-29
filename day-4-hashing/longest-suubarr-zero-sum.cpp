// Longest Subarray with 0 sum 
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> nums {15, -2, 2, -8, 1, 7, 10, 23};
    int n = nums.size() ;
    int prefsum = 0, answer = 0 ;
    unordered_map<int, int> cache ;
    cache[0] = 0 ;
    fo(i, n){
        int x = nums[i];
        prefsum += x ;
        if(prefsum == 0) { answer = i + 1 ; }
        auto f = cache.find(prefsum);
        if(f != cache.end() ){
            answer = max(answer, i - cache[prefsum]);
        }
        else{ cache[prefsum] = i ; }
    }
    cout << answer << endl ;

    return 0;
}
