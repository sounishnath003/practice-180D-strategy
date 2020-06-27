// Sort an array of 0's 1's 2's without using extra space or sorting algo
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
    // approch:  O(N) time & O(0) space
    // `algorithm called 3-way DUCTCH Flag partition`
    
    // vector<int> nums { 0, 1, 2, 0, 1, 2 } ;
    vector<int> nums{0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = (int) nums.size() ;
    fo(i, n) {
     if(nums[i] == 0){
        for (int j = i; j > 0; j--) {
            swap(nums[j], nums[j - 1]);
        }
     }
     if(nums[i] == 1) {
        for (int j = i; j > 0; j--) {
            if(nums[j - 1]!= 0)
            swap(nums[j], nums[j - 1]);
        }
     }
    }
    for(auto &&i : nums){
        cout << i << " " ;
    }


    return 0;
}
