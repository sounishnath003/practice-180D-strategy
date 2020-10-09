/*
	Name: Game of Maximizations
	Copyright: HackerRank HackFest 2020
	Author: Sounish Nath
	Date: 09-10-20 11:43
	Description: 
*/

#include <bits/stdc++.h>

using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n;
	cin >> n ;
	vector<int> stones(n);
	for(int i = 0; i < n; i++) {
		cin >> stones[i];
	}
	int oddsum = 0, evensum = 0 ;
	for(int i = 0 ; i < n ; i++) {		
		if(oddsum != evensum) {
			oddsum > evensum ? --oddsum : --evensum;
		}
		if(i & 1) {
			oddsum += stones[i];
		}else{
			evensum += stones[i];
		}
	}
	cout << "maximum picking up: " << 2 * oddsum << endl ;
	

}

