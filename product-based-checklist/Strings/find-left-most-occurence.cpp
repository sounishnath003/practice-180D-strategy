#include<bits/stdc++.h>

using namespace std;
using pairr = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;
	int n = s.length();
	vector<int> cache(26);
	for(auto &&x : s){
		cache[x - 'a']++;
	}
	for(int i = 0; i < n; i++){
		if(cache[s[i] - 'a'] > 1){
			cout << "leftmost index: " << i << endl; break;
		}
	}
}
