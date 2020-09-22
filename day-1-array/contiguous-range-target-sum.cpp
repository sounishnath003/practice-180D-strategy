/*
	Name: Contiguous Range Target Sum
	Author: Sounish Nath
	Date: 22-09-20 00:03
	Description: Array Interview Asked Questions
*/

#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n ;
	vector<int> nums(n) ;
	for(int i = 0; i < n; i++) { cin >> nums[i] ; }
	int target ;
	cin >> target ;
	for(int i = 0; i < n; i++){
		int left = 0 ;
		for(int j = i; j < n; j++){
			left += nums[j] ;
			if(left == target){
				print(nums.begin() + i, nums.begin() + j + 1) ;
			}
		}
	}


}

