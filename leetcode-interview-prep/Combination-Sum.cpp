// problem link: https://leetcode.com/problems/combination-sum/
#include <bits/stdc++.h>
using namespace std ;

using choice = vector<int> ;

vector<choice> f(vector<int> &nums, int curIndex, int target) {
	//base case
	if((int) nums.size() == curIndex) return {} ;
	if(target == 0) return {{}};
	if(target < 0) return {};
	
	vector<choice> ans = f(nums, curIndex + 1, target); // without consider
	vector<choice> others = f(nums, curIndex, target - nums[curIndex]); // let it consider
	
	for(choice c : others) {
		c.push_back(nums[curIndex]);
		ans.push_back(c);
	}
	return ans ;
}

vector<choice> permjutationSum(vector<int> &nums, int target) {
	return f(nums, 0, target) ;
}


int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n ;
	vector<int> nums(n) ;
	fo(i, n) {
		cin >> nums[i];
	}
	debug() << imie(nums) ;
	vector<choice> ans = permjutationSum(nums, 7)q;
	for(choice c : ans){
		debug() << imie(c) ;
		cout << endl ;
	}

}

