#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

// 1 1 1 3 2 2 2
// 1 1 2 2

int longestSubarray(vector<int>& nums ) {
    int n = nums.size() ;
    int answer = 0 ;
    unordered_set<int> cache ;
    int j = 1 ;
    for(int i = 0; i < n ; i++ ) {
        int el = nums[i] ;
        cache.insert(el) ;
        while(j < n and abs(el - nums[j]) < 2 ){
            if(!(cache.count(nums[j]))) {
                if(cache.size() == 2) break ;
                else { cache.insert(nums[j]) ; }
            }
            j++ ;
        }
        answer = max(answer, j - i) ;
        j = i + 1 ;
        cache.clear() ;
    }
    return answer ;
}



int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> nums{1,1,1,3,3,2,2} ;
    cout << longestSubarray(nums) << endl ;

    return 0;
}
