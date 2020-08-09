#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;

vector<int> solve(string A, vector<vector<int>>& B) {
        vector<int> res(B.size()) ;
        int flag = 1 ;
        int index = 0 ;
        for(auto a : B) {
            int left = a[0] - 1, right = a[1] ;
            int count  = 0 ;
            right-- ;
            while(left < right ) {
                if(A.at(left) != '1' ) left++ ;
                if(A.at(right) != '1' ) right-- ;
                if(A.at(left) == '1' && A.ar(right) == '1' ) break ;
            }
            if (left == right ) {
                res[index++] = 0 ;
            }else {
                for(int i = left; i < right ; i++) {
                    if (A.at(i) == '0') count++ ;
                }
                res[index++] = count ;
            }
        }
        return res ;
    }
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    
    
    return 0;
}
