/*
	Name: Bheem & Permutations (CodeNation Problem Solution)
	Author: Sounish Nath
	Date: 28-09-20 00:18
*/

#include<bits/stdc++.h>
using namespace std ;
const int inf = 2e9+18 ;

int main() {
	vector<int> A;
	int B, n;
	cin >> A;
	cin >> B;
	vector<int> ans;
	foo(i, 1, B){
		ans.push_back(n++);
	}
	int r = A - B ;
	ans.push_back(A);
	while(r--){ ans.push_back(n++); }
	cout << ans ;
}
