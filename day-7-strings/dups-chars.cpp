#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	string s;
	cin >> s; 
	bitset<255> seen;
	for(int i = 0; i < (int) s.length(); i++){
		char x = s[i] ;
		if(seen[x]){
			cout << x << " " ;
		}else{
			seen[x] = true;	
		}
	}


}

