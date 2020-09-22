/*
	Name: separate zeros from non-zeros in an integer array
	Copyright: Interview Practice Set
	Date: 22-09-20 13:52
*/

#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, st = 0 ;
	cin >> n ;
	vector<int> nums(n) ;
	fo(i, n){ cin >> nums[i] ; }
	for(int i = 0; i < n; i++){
		if(nums[i] != 0){
			nums[st++] = nums[i] ;
		}
	}
	for(int i = st; i < n; i++){
		nums[i] = 0 ;
	}
	debug() << imie(nums) ;
}

