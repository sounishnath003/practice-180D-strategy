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

bool is_safe(vector<vector<int>> &board, int row, int col) {
    int H = board.size() ;
    int W = board[0].size() ;
    if (board[row][col]) {
        return false ;
    }
    int i = row, j = col ;
    while(i >= 0 and j >= 0) {
        if (board[i][j]) {
            return false ;
        }
        i--, j-- ;
    }
    i = row, j = col ;
    while(i < H and j >= 0) {
        if (board[i][col]) {
            return false ;
        }
        i++, j-- ;
    }
    return true ;
}



int main(int argc, char const *argv[]){
    IOS ;
   
    vector<vector<int>> board {
        {0,0,1,0},
        {1,0,0,0},
        {0,0,0,0},
        {0,0,0,0},
    }    ;

    for (auto row : board ) {
        cout << row ;
    }

    if (is_safe(board, 2, 3)) {
        cout << "safe\n";
    }else {
        cout << "not safe\n";
    }

    return 0;
}
