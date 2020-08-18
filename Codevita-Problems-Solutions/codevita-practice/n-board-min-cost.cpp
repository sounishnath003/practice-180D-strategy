#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int inf = 1e9+7 ;
const int N = 1e6+7 ;

template<typename T>
void operator<<(ostream &os, vector<vector<T>> &mat) {
    for(const T i : mat) {
        for (const T j : i ){
            cout << j << " " ;
        }
        cout << endl ;
    }
}
template<typename T>
void operator<<(ostream &os, vector<T > &v){
    for (const T x : v) {
        cout << x << " " ;
    }
    cout << endl ;
}


int go(vector<vector<int>> &grid) {
  int H = grid.size(),
    W = grid[0].size() ;
  vector<vector<int>> dp(H, vector<int>(W)) ;
  for(int row = 0; row < H; row++) {
    for(int col = 0; col < W; col++) {
      if(row == 0 or col == 0) {
        dp[row][col] = grid[row][col] ;
      }
      else {
        dp[row][col] = grid[row][col] + min( (row==0) ? inf : dp[row-1][col] , (col == 0) ? inf : dp[row][col-1] )/2 ;
      }
    }
  }
  return dp[H-1][W-1] ;
}


int main(int argc, char const *argv[]){
    IOS ;
   
    vector<vector<int>> grid {
      {0,3,9,6},
      {1,4,4,5},
      {8,2,5,4},
      {1,8,5,9}
    }    ;

    cout << go(grid) ;

    return 0;
}
