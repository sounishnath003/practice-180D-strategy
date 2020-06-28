// 4 Sum problem
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, j, n) for(int i = 0; i < n; i++) for(int j = 0; j < n ; j++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;

    vector<int> nums{10, 2, 3, 4, 5, 9, 7, 8};
    int n = (int) nums.size() ;
    int target = 23 ; bool tt = true ;
    unordered_map<int, vector<pair<int, int>>> cache ;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            int cursum = target - ( nums[i] + nums[j] );
            auto f = cache.find(cursum);
            if(f != cache.end()) {
                for(auto &&ii : f->second){
                    int x = ii.first, y = ii.second;
                    if(tt){
                        cout << nums[i] << " " << nums[j] << " " << nums[x] << " " << nums[y] << endl ;
                        tt = false ;
                    }
                }
            }
            cache.insert({nums[i] + nums[j] , {{i,j}}});
        }
    }

    return 0;
}