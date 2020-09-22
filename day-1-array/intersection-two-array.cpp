/*
	Name: Intersection of 2 Arrays
	Date: 22-09-20 13:36
*/

#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> nums(n) ;
	fo(i, n){
		cin >> nums[i] ;
	}
	int m ;
	cin >> m ;
	vector<int> nums2(m) ;
	fo(i, m){
		cin >> nums2[i];
	}
	set<int> seen ;
	for(auto &&x : nums){
		seen.insert(x) ;
	}
	for(auto &&x : nums2){
		if(seen.count(x)){
			cout << x << " " ;
		}
	}

}

