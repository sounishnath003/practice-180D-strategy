/* https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ */
#include<bits/stdc++.h>

using namespace std ;
const int inf = 2e9+18;


int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n ;
	vector<int> stocks(n);
	for(int i = 0; i < n; i++){
		cin >> stocks[i];
	}
	/* a very BEST problem ~ 1 */
	int minimal = inf, profit = 0;
	for(auto &&stock : stocks){
		minimal = min(minimal, stock);
		profit = max(profit, abs(stock - minimal));
	}
	cout << "your max profit is: " << profit << endl ;
}

