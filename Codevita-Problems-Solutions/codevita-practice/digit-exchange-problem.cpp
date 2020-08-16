#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void operator<<(ostream &os, vector<int > &v){
    for (const int x : v) {
        cout << x << " " ;
    }
    cout << endl ;
}


int go(int &n, int &k) {
    string s1 = to_string(n) , s2 = to_string(k);
    if (s1.length() != s2.length()) {
        return -1 ;
    } ;
    vector<int> digits ;
    while(n) { digits.push_back(n % 10); n/= 10 ; }
    sort(digits.begin(), digits.end()) ;
    while(next_permutation(digits.begin(), digits.end())) {
        int sum = 0 ;
        for (const int x : digits) {
            sum = sum * 10 + x ;
        }
        if (sum > k) {
            return sum ;
        }
    }
}



int main(int argc, char const *argv[]){
    IOS ;
   
    int n = 1234, k = 221 ;
    cout << go(n, k) ;

    return 0;
}
