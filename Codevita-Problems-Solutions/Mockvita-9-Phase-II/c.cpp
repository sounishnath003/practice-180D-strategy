#include<bits/stdc++.h>
using namespace std ;

int maxlength = 0, countt = 0;
unordered_map<int, int> cache;
int geometric_func(int x, int y) {
    countt++ ;
    if(y > x) {
        swap(x, y) ;
    }
    if(x == 0 or y == 0) {
        return 0 ;
    }
    if(x == y) {
        return 1 ;
    }else{
        auto f = cache.find((x+y)*91) ;
        if (f == cache.end()) {
            cache[(x + y) * 91] = 1 + geometric_func(x - y, y) ;
        }
        maxlength = max((int) cache.size(), maxlength) ;
        if (cache.find(((x - y) + y) * 91) != cache.end()) {
            cache.erase(((x - y) + y) * 91) ;
        }
    }
    return cache[(x + y) * 91] ;
}


int main() {

    int a, b, c, d ;
    cin >> a >> b >> c >> d ;

    int answer = 0 ;
    for(int i = a; i < b + 1; i++) {
        for(int j = c; j < d + 1; j++) {
            answer += geometric_func(i, j) ;
        }
    }
    cout << answer << endl ;

    return 0 ;
}