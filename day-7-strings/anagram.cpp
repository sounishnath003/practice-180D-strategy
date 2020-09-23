#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s, t;
	cin >> s >> t;
	sort(s.begin(), s.end())  ;
	sort(t.begin(), t.end());
	if(t == s){
		cout << "anagram\n";
	}else{
		cout << "not anagrams\n";
	}


}

