/*
    author: Sounish Nath
    date: 2020-08-20 14:44:34
    problem: Smallest KMP | Credit (Arpana Ray)
*/
#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    int n;
    cin >> n ;
    while(n--) {
        string s, p;
        cin >> s >> p ;
        map<char, int> cache ;
        for(auto &&x : s) { cache[x]++ ; }
        for(auto &&x : p) { cache[x]-- ; }
        bool tt = true;
        for(auto&& pp : cache) {
            if(pp.first > p[0] and tt){ cout << p ; tt = false ; }
            while(pp.second--) { cout << pp.first ; }
        }
        cout << endl ;
    }
    
    return 0;
}
