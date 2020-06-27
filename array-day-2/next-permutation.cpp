// Next Permutation
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
    auto print = [&](const vector<int> v){
        for(auto &&x : v){
            cout << x << " " ;
        }
        cout << endl ;
    };
    vector<int> nums {84,894,848,4,84,681,768,17,982,984,894};
    do{
        print(nums) ;
    }while(next_permutation(nums.begin(), nums.end()));

    return 0;
}
