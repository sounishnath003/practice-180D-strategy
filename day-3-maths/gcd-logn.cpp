// Find GCD in Log N
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a%b) ;
}

int main(int argc, char const *argv[]){
    IOS ;

    cout << gcd(2, 10) << endl ;
    cout << gcd(5, 10) << endl ;
    cout << gcd(13, 10) << endl ;
    cout << gcd(42, 10) << endl ;
    cout << gcd(300, 962) << endl ;

    return 0;
}
