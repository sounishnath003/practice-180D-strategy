/*
	Name: Find kth largest element in unsorted array
	Copyright: Interview Practice 
	Author: 
	Date: 22-09-20 14:22
	Description: 
*/
#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n ;
	vector<int> nums(n) ;
	fo(i, n){ cin >> nums[i] ; }
	int k; cin >> k;
	make_heap(nums.begin(), nums.end(), greater<int>{}) ;
	while(k--){
		debug() << imie(nums) imie(k);
		pop_heap(nums.begin(), nums.end()) ;
		make_heap(nums.begin(), nums.end(), greater<int>{});
	}
	cout << nums[0] << endl ;
}

