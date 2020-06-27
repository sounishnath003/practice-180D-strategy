// Find the duplicate in an array of N integers. 
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
   
    vector<int> nums {1,20,3,4,5,6,7,8,1,4} ;
    int n = nums.size() ;
    fo(i, n) {
        if(nums[abs(nums[i])] >= 0) {
            nums[i] *= -1 ;
        }else{
            cout << nums[i] << " " ;
        }
    }

    return 0;
}
