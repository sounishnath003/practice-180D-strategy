// Longest Consecutive Sequence 
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

    vector<int> nums{36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42};
    unordered_set<int> cache ;
    int answer = 0 ;
    for(auto &&x : nums){ cache.insert(x) ; }
    for(auto &&x : nums){
        if(cache.count(x - 1)) {
            int el = x ;
            while(cache.count(el++)) {
                answer = max(answer, el - x) ;
            }
        }
    }
    cout << answer + 1 << endl ;

    return 0;
}
