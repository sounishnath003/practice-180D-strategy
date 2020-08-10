#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;
const int inf = 2e9;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    vector<int> nums ;
    int n = nums.size() ;
    vector<int> dp(n, inf);
    if(n == 0 or nums[0] == 0 ) { cout << 0 << endl ; exit(0) ; }
    for(int i = 0; i < n; i++ ) {
        for(int j = 0 ; j < i; j++) {
            if(i <= j + nums[j] && dp[j] != inf ){
                dp[i] = min(dp[i], 1 + dp[j]) ;
            }
        }
    }
    cout << dp[n-1] << endl ;
    
    return 0;
}
