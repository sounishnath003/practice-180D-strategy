  /*
	Name: Merge Overlapping Intervals
	Copyright: Product Based CheckList
	Author: Sounish Nath
	Date: 13-10-20 00:27
	Description: Arrays Based Problem
*/
#include<bits/stdc++.h>

using namespace std ;
using pairr = pair<int, int>;

int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pairr> intervals(n);
	for(int i = 0 ; i < n; i++) {
		pairr p ; cin >> p.first >> p.second ;
		intervals.emplace_back(p);
	}
	sort(intervals.begin(), intervals.end(), [&](pairr &a, pairr &b) {
		return a.first < b.first;
	});
	for(int i = 0 ; i < n - 1; i++) {
		pairr a = intervals[i], b = intervals[i + 1];
		if(a.second >= b.first){
			a.first = min(a.first, b.first);
			a.second = max(a.second, b.second);
		}else{
			intervals[i] = b;
		}
	}
	cout << "sorted merged intervals:\n";
	for(auto &&x : intervals){
		cout << x.first << " - " << x.second << endl ;
	}
}

