/* 
	problem link: https://leetcode.com/problems/k-diff-pairs-in-an-array/ 
	author: Sounish Nath
	Day - 2
*/
#include <bits/stdc++.h>
using namespace std ;

using hashmap = unordered_map<int, int>;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n);
	fo(i, n) {
		cin >> nums[i];
	}
	int k; cin >> k;
	hashmap cache ;
	for(auto &&x : nums){
		cache[x]++;
	}
	int ans = 0;
	debug() << imie(cache);
	for(auto pp : cache) {
		int x = pp.first;
		if(cache.count(x)){
			ans += (k == 0) ? cache[x + k] >= 2 : cache[x+k] >= 1;	
		}
	}
	cout << "ans: " << ans << endl ;


}

