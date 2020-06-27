// Set Matrix Zeros
// complexity: O(H + W) || (H = row, W = col)
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

    vector<vector<int>> matrix {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    int H = (int) matrix.size();
    int W = (int) matrix[0].size();
    vector<vector<bool>> visited(H, vector<bool>(W)) ;
    auto set_zeros = [&](int row, int col) {
        fo(i, H) { visited[i][col] = true, matrix[i][col] = 0 ; }
        fo(i, W){ visited[row][i] = true, matrix[row][i] = 0 ; }
    };
    for(int row = 0 ; row < H; row++){
        for(int col = 0; col < W; col++) {
            if(!visited[row][col] && matrix[row][col] == 0) {
                set_zeros(row, col) ; break;
            }
        }
    }
    for(auto &&row : matrix){
        for(auto &&x : row) {
            cout << x << " " ;
        }
        cout << endl ;
    }

    return 0;
}
