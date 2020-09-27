/*
	Name: BJomes hates XOR (CodeNation Problem Solution)
	Author: Sounish Nath
	Date: 28-09-20 00:18
*/

#include<bits/stdc++.h>
using namespace std ;
const int inf = 2e9+18 ;

void go(vector<int> &A, int k) {
	const int inf = 2e9+18;
	int cost = inf ;
	int n = (int) A.size();
	fo(i, n - k){
		int _cost = inf, xoor = 0 ;
		foo(j, i, i + k){
			xoor = xoor ^ A[j];
		}
		foo(b, i, n - k){
			_cost = min(_cost, abs(xoor ^ A[b]) - A[b])
		}
		cost = min(cost, _cost);
	}
	return cost == inf ? 0 : abs(cost);
}

int main() {
	vector<int> A;
	int B;
	cin >> A;
	cin >> B;
	
	go(A, B);
}
