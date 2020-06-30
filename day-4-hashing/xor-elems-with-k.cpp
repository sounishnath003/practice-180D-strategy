/*
    statement - Count number of subarrays with 
    given XOR.(this clears a lot of problems)
    author - sounishnath003
    date - 30-06-2020
    time - O(N) approch
*/
#include<bits/stdc++.h>
using namespace std;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;

    vector<int> nums { 4, 2, 2, 6, 4 }; int m = 6 ;
    unordered_map<int, int> cache ;
    vector<int> prefxor ;
    prefxor.push_back(nums[0]);
    int answer = 0 ;
    for(auto &&x : nums) { prefxor.push_back(prefxor.back() xor x); }
    fo(i, (int) nums.size()){
        int x = nums[i] ;
        int t = m ^ x ;
        answer += cache[t] ;
        if(prefxor[i] == m){ answer++ ; }
        cache[prefxor[i]]++ ;
    }
    cout << answer << endl ;

    return 0;
}
