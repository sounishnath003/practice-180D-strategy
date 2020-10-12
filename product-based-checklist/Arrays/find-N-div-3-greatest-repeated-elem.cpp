/*
	Name: Find >= N/3 repeative elems
	Copyright: Product Based CheckList
	Author: Sounish Nath
	Date: 13-10-20 00:04
	Description: Arrays Based Problem
*/
#include<bits/stdc++.h>

using namespace std ;
const int inf = 2e9+18;

/* !space optimised ~ cache<int, int> O(N) */
void f(vector<int>& nums){
	int n = nums.size();
	map<int, int> cache ;
	for(auto &&x : nums ) {
		cache[x]++;
	}
	for(auto &&p : cache) {
		if(p.second >= (int)(n / 3)){
			cout << p.first << endl; break;
		}
	}
}

int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	/* space optimse ~ O(1) solution */
	int fseen = inf, sseen = inf, c1 = 0, c2 = 0;
	for(int i = 0 ;i < n; i++) {
		if(fseen == nums[i]){
			c1++;
		}else if(sseen == nums[i]){
			c2++;
		}else if(c1 == 0){
			fseen = nums[i];
			c1++;
		}
		else if(c2 == 0){
			sseen = nums[i];
			c2++;
		}
		else{
			c1--, c2--;
		}
	}
	c1 = c2 = 0;
	for(int i = 0; i < n; i++){
		if(nums[i] == fseen){
			c1++;
		}else if(nums[i] == sseen){
			c2++;
		}
	}
	if(c1 >= (int)n/3){
		cout << fseen << endl;
	}else{
		cout << sseen << endl;
	}
}

