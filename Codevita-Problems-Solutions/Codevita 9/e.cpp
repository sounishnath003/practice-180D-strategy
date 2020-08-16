#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long ll ;

int main(int argc, char const *argv[]){
    IOS ;
   
    int n;
    int k;
    int totalsum = 0, tmp;
    cin >> n >> k ;
    vector<int> nums(n) ;
    auto remove_element = [&](vector<int> &nums) {
        pop_heap(nums.begin(), nums.end()) ;
        nums.pop_back() ;
    };
    fo(i, n) {
        cin >> tmp;
        totalsum += tmp ;
        nums.push_back(tmp) ;
    }
    make_heap(nums.begin(), nums.end());
    print(nums)
    ll maximum = 0, answer = 0 ;
    fo(i, k)     {
        maximum = nums.front() ;
        totalsum = maximum ;
        remove_element(nums);
        answer = maximum/2 ;
        nums.push_back(answer) ;
        push_heap(nums.begin(), nums.end()) ;
    }
    cout << totalsum << endl ;

    return 0;
}
