// Longest substring without repeat 
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;

    string str = "geeksforgeeks";
    int n = str.length(), j = -1, answer = 0 ;
    vector<int> dp(256);
    fo(i, n){
        char x = str[i];
        if(dp[x] > j){ j = dp[x] ; }
        dp[x] = i ;
        answer = max(answer, i - j);
    }
    cout << answer << endl ;

    return 0;
}
