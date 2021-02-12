#include<bits/stdc++.h>

using namespace std;

bool rotate(string s, string t){
	if((int) s.length() != (int) t.length()){
		return false;
	}
	return (s+s).find(t) != string::npos;
}

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;
	(rotate(s1, s2)) ? cout << "can be rotated\n" : cout << "cannot be rotated\n";
}
