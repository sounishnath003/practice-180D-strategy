// Repeat and Missing Number
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 1; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;

    vector<int> nums { 3, 1, 3 } ;
    int n = (int) nums.size() ;
    fo(i, n) {
        int t = abs(nums[i] - nums[i - 1]) ;
        if(t != 1){
            cout << "missing: " << t << endl ;
            break ;
        }
    }
    for_each(nums.begin(), nums.end(), [&](const int& x){
        if(count(nums.begin(), nums.end(), x) > 1) {
            cout << "repeat " << x << endl ;
        }
    });
    return 0;
}
