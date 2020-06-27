// 2 Sum problem
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

    vector<int> nums { 0, -1, 2, -3, 1 };
    int sum = -2 ;
    unordered_set<int> compp ;
    for(auto &&i : nums) {
        int need = sum - i ;
        if(compp.count(i)){
            cout << i << setw(3) << need << endl ;
        }
        compp.insert(need) ;
    }

    return 0;
}
