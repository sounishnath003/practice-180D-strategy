#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s ;
	int n = (int) s.size();
	for(int i = 0;i < (1 << n); i++){
		for(int j = 0; j < n; j++){
			if(i & (1 << j)){
				cout << s[j] ;
			}
		}
		cout << "\n";
	}

}

