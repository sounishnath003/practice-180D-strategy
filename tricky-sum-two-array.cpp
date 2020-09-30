/*
	Name: Trick
	Copyright: 
	Author: 
	Date: 30-09-20 10:26
	Description: 
*/

#include <bits/stdc++.h>
using namespace std ;
const int inf = 2e9+17;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> nums1(n), nums2(n);
    fo(i, n) { cin >> nums1[i]; }
    fo(i, n) { cin >> nums2[i]; }
    
    vector<vector<int>>dp(n, vector<int>(n, inf));
    dp[0][0] = nums1[0] + nums2[0];
    foo(i, 0, n){
        int el = nums1[i];
        for (int j = 0; j < n; j++){
            if(i == 0) {
            	dp[i][j] = min(dp[i][j - 1], el + nums2[j]);
			}else{
				dp[i][j] = (j == 0) ? min(dp[i-1][j], el + nums2[j]) : min({el + nums2[j], dp[i-1][j], dp[i][j - 1]}) ;
			}
        }
        debug() << imie(dp);
    }
    
    cout << "minimum costs: " << dp[n-1][n-1];
}
