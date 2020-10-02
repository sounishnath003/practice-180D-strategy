#include <bits/stdc++.h>
using namespace std ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> powers(n);
	fo(i, n){
		cin >> powers[i];
	}
	int sum = accumulate(powers.begin(), powers.end(), 0);
	int maxelem = *max_element(powers.begin(), powers.end());
	int minelem = *min_element(powers.begin(), powers.end());
	int cost = (sum - (maxelem  * minelem) );
	
	cout << "minimum operations: " << cost << endl ;
	double f = 1.0 + (double) (cost * (k / 100) * (1/2));
	cout << "hence total max power: " << f << endl ;
	
}
