#include<bits/stdc++.h>
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}
#define fo(i, n) for(int i = 0; i < n ; i++)
const int N = 1e+6 ;


void go(int &n, int &k) {
    vector<int> factos ;
    for (int i = 1; i <= (int)n/2; i++) {
        if (n % i == 0) {
            factos.emplace_back(i) ;
        }
    }
    factos.emplace_back(n) ;
    if (k > factos.size()-1) {cout << factos[abs(k-factos.size())-1] << endl ; }
    else {cout << factos[k] << endl ; }
}



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin) ;
        freopen("out.txt", "w", stdout) ;
    #endif

    int n , k ;
    scanf("%d,%d", &n, &k) ;

    go(n, k) ;
    
    return 0;
}
