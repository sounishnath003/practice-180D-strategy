#include <bits/stdc++.h>
using namespace std ;
#define deb(x) cout << #x << " " << x << endl 

void go(vector<int> &chocs, int &m) {
  sort(chocs.begin(), chocs.end()) ;
  int first = 0, last = 0, minDiff = INT_MAX ;
  for(int i = 0; i+m-1 < chocs.size(); i++) {
    int diff = chocs[i+m-1] - chocs[i] ;
    if (minDiff > diff) {
      first = i, last = i+m-1 ;
      minDiff = diff ;
    }
}

  cout << chocs[last] - chocs[first] << endl ;
}

int main() {
  vector<int> chocs  {12, 4, 7, 9, 2, 23, 25, 41, 
                 30, 40, 28, 42, 30, 44, 48, 
                 43, 50};
  int m = 7
  go(chocs, m)   ;
}