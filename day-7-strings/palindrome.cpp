#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s ;
	int lo = 0, hi = (int) s.length() - 1;
	bool t = false ;
	while(lo != hi && !t){
		if(s[lo++] != s[hi--]){
			t = true ;
			cout << "not palindrom\n";
			break ;
		}
	}
	if(!t){
		cout << "palindrome\n";
	}


}

