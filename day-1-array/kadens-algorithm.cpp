// Kadane's Algorithm
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
   
    vector<int> nums {4918,41,-89,-148,4,8,17,-98,7987};
    int x = 0 ;
    int answer = 0 ;
    for(auto && i : nums){
        x += i ;
        answer = max(answer, x);
        x = max(x, 0) ;
    }
    cout << answer << endl ;

    return 0;
}
