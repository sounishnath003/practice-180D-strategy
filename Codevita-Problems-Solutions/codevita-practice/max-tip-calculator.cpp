#include<bits/stdc++.h>
#define fo(i, n) for(int i = 1; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}
const int N = 1e6+5 ;


// stl approch
void getMaxTip(int x, int y, int n, vector<int> A, vector<int> B) {
    int totalTip = 0 ;
    for (int i = 0; i < A.size(); i++ ) {
        if (x == 0 and y == 0) break ;
        if (max(A[i], B[i]) == A[i]) {x-- ;}
        else {y-- ;}
        
        totalTip += max(A[i], B[i]);    
    }
    cout << totalTip << endl ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    // int N = 5, X = 3, Y = 3 ;
    // vector<int> A = {1,2,3,4,5} ;
    // vector<int> B = {5,4,3,2,1} ;
    
    int N = 8, X = 4, Y = 4 ;
    vector<int> A = {1,4,3,2,7,5,9,6 } ;
    vector<int> B = {1,2,3,6,5,4,9,8} ;

    getMaxTip(X, Y, N, A, B) ;
   
    return 0;
}
