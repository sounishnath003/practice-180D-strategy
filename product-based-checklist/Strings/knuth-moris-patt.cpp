/* Theory: https://cp-algorithms.com/string/prefix-function.html */
#include<bits/stdc++.h>

using namespace std ;

/* BAD approach - O(N*M) */
void naive_substring_match(string s, string p){
	int n = (int) s.length(), m = (int) p.length();
	for(int i = 0 ; i <= n - m; i++){
		int j;
		for(j = 0; j < m; j++){
			if(s[i + j] != p[j]){
				break;
			}
		}
		if(j == m){
			cout << "pattern has been found\n";
		}
	}
}


int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	string s, p;
	cin >> s >> p;
	
	/* prefix solution in single *Iter O(N+M) */
	int m = (int) p.length();
	vector<int> faliurFunc(m, -1);
	int right, left;
	// preparing faliurFunc / PIE Table
	for(right = 1, left = -1; right < m; right++){
		while(left != -1 && p[left + 1] != p[right]){
			left = faliurFunc[left];
		}
		if(p[left + 1] == p[right]){
			faliurFunc[right] = left++;
		}
	}
	// search for pattern
	int tpoint = -1;
	for(int i = 0; i < (int)s.length(); i++){
		while(tpoint != -1 && s[i] != p[1 + tpoint]){
			tpoint = faliurFunc[tpoint];
		}
		if(s[i] == p[tpoint + 1]){
			tpoint++;	
		}
		if(tpoint == m-1){
			cout << "found at index: " << i - tpoint << endl;
			break;
		}
	}
	
}

