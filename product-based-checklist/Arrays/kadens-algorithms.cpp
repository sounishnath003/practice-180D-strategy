#include<bits/stdc++.h>

using namespace std ;
const int inf = 2e9+18;

int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0 ; i < n; i++) {
		cin >> nums[i];
	}
	int sum = -inf, a = 0;
	for(auto &&x : nums) {
		a += x;
		sum = max(sum, a);
		a = max(a, 0);
	}
	cout << sum;
}

