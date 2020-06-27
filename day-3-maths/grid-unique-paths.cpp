// Grid Unique Paths
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

// total O(2*n) complexity:
int countUniquePaths(int n, int m) {
    if(n == 1 or m == 1) {return 1 ;}
    return countUniquePaths(n - 1, m) + countUniquePaths(n, m - 1);
}

// total O(n*n) complexity: polynomial solution
int dpsolution(int n, int m) {
    vector<vector<int>>  dp(n, vector<int>(m));
    fo(i, n){
        dp[i][0] = 1 ;
    }
    fo(i, m){
        dp[0][i] = 1 ;
    }
    for(int i = 1 ; i<n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
        }
    }
    return dp[n - 1][m - 1] ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    cout << countUniquePaths(10,17) << endl ;
    cout << dpsolution(10, 17) << endl ;

    return 0;
}
