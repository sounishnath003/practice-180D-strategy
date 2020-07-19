#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

string findSubstring(string s, int k) {
    string::iterator start = s.begin() ;
    string::iterator end = s.begin() + k ;
    string vowels = "aeiou" ;
    set<pair<int, string>> cache ;
    while(end != s.end() + 1) {
        int countt = 0 ;
        string t = string(start, end) ;
        for(auto &&x : t) {
            if (vowels.find(x) != string::npos) { countt++ ; }
        }
        cache.insert({countt, t}) ;
        ++start, ++end ;
    }
    for(auto &&pp : cache ) {
        cout << pp.first  << " - " << pp.second << endl ;
    }
    return (cache.end())->second ;
}


int main(int argc, char const *argv[]){
    IOS ;
   
    string s = "azerdii" ;
    // string s = "caberqiitefg" ;
    int k = 5 ;

    cout << findSubstring(s, k) << endl ;


    return 0;
}
