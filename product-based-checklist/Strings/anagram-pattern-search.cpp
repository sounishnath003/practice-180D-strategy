#include<bits/stdc++.h>

using namespace std;
using pairr = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	string s, p;
	cin >> s >> p;
	int n = s.length();
	int m = p.length();
	vector<bool> lps(26);
	for(auto &&x : p){
		lps[x-'a'] = true;
	}
	for(int i = 0; i <= n - m; i++){
		for(int j = 0; j < m; j++){
			if(lps[s[i+j] - 'a'] != lps[p[j] - 'a']){
				break;
			}
			if(j == m - 1){
				cout << "pattern for anagram is present\n"; exit(0);
			}
		}
	}
	cout << "pattern is not present\n";
}
