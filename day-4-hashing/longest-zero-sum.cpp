#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n ;
	vector<int> nums(n) ;
	for(int i = 0; i < n; i++){ cin >> nums[i] ; }
	vector<int> dp(n);
	for(int i = 0; i < n; i++){
		int left = 0 ;
		for(int j = i; j < n; j++){
			left += nums[j] ;
			if(left - nums[j] == 0){
				dp[i] = (i == 0) ? 0 : max(dp[i - 1], j - i) ;
			}
		}
	}
	cout << "ans: " << dp.back() ;

}
