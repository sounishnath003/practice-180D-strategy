// 4 Sum problem
#include <bits/stdc++.h>
using namespace std ;

int main() {
  vector<int> nums { 10, 2, 3, 4, 5, 9, 7, 8 } ;
  unordered_map<int, pair<int,int>> cache ;
  int n = nums.size() ;
  int target = 23 ;
  for(int i = 0; i < n - 1; i++) {
    for(int j = i + 1; j < n; j++) {
      int cursum = target - ( nums[i] + nums[j] ) ;
      auto f = cache.find(cursum) ;
      if(f != cache.end()) {
        int x = f->second.first, y = f->second.second ;
        cout << nums[i] << " " << nums[j] << " " << nums[x] << " " << nums[y] << endl ;
      }
      cache.insert({ nums[i] + nums[j], {i, j} }) ;
    }
  }
}
