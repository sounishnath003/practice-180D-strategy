#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s; 
	int n = (int) s.length() - 1; int lo = 0 ;
	while(n != lo){
		swap(s[lo++], s[n--]);
	}
	cout << s;


}

