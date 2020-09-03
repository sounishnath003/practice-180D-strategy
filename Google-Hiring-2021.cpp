#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;

void f(string &s, int &cost, vector<vector<int>> &grid, unordered_map<char, int>& alpha) {
    int tcost = 0 ;
    for(int i = 0 ; i < (int) s.size(); i++) {
          tcost += (i == 0) ? grid[alpha[s[i]] - 1][alpha[s[i]] - 1] : grid[alpha[s[i - 1]] - 1][alpha[s[i]] - 1] ;
    }
    cost = min(tcost, cost) ;
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int n ;
    string s ;
    int cost = 2e9 ;
    cin >> n ;
    vector<vector<int>> grid(n, vector<int>(n)) ;
    for(int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j] ;
        }
    }
    cin >> s ;
    unordered_map<char, int> alpha = {
        {'a', 1},  
        {'b', 2},  
        {'c', 3},  
        {'d', 4},
        {'e', 5},
    };
    do{
        f(s, cost, grid, alpha) ;
    }while(next_permutation(s.begin(), s.end())) ;
    cout << cost << endl ;
       
    return 0;
}


/*
5
0 5 1 5 3
4 0 9 4 2
7 9 0 10 7
1 2 8 0 2
3 9 7 7 0
abcde
*/
