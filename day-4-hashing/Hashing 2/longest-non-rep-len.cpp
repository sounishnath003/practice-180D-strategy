#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s ;
	int n = (int) s.length();
	vector<int> seen(256);
	int len = 0, ans = -1 ;
	fo(i, n){
		len = max(len, 1 + seen[s[i]]) ;
		ans = max(ans, i - len + 1);
		seen[s[i]] = i ;
	}
	cout << "max length: " << ans;

}

