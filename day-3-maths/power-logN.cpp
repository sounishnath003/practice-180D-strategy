// Find n ^ x in log N
#include<bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int power(int a, int b) {
    if(b == 0) { return 0 ;}
    if(b == 1) { return a ; }
    if(b&1){
        return a * power(a, b - 1) ;
    }else {
        return power(a*a, b/2) ;
    }
}

int main(int argc, char const *argv[]){
    IOS ;
   
    cout << power(2, 3) << endl ;
    cout << power(5, 3) << endl ;
    cout << power(3, 3) << endl ;
    cout << power(89, 4) << endl ;
    cout << power(2, 20) << endl ;

    return 0;
}
