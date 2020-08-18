// author: Sounish Nath
// Date: 16-08-2020
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

// references printter 1
void printt(unordered_map<int, char> &dict) {
    for (auto &&x : dict) {
        cout << x.first << " - " << x.second << endl;
    }
    cout << endl; 
}
// references printter 2
void printt(unordered_map<char, char> &dict) {
    for (auto &&x : dict) {
        cout << x.first << " - " << x.second << endl;
    }
    cout << endl; 
}

int main(int argc, char const *argv[]){
    IOS ;
   
    string s ;
    cin >> s ;
    int n ;
    cin >> n ;
    vector<pair<string, string>> words ;
    fo(i, n) {
        string t, p ;
        cin >> t >> p ;
        words.emplace_back(t, p) ;
    }
    unordered_map<char, char> dict ;
    unordered_map<char, int> tranpose ;
    for(auto &&pp : words) {
        string word = pp.first, key = pp.second ;
        unordered_map<int, char> mp1, mp2 ;
        for(auto x: word) {
            int cnt = count(word.begin(), word.end(), x) ;
                mp1[cnt] = x;
                tranpose[x] = cnt ;
        }
        for(auto &&x : key) {
            int cnt = count(key.begin(), key.end(), x);
            mp2[cnt] = x ;
        }
        for(auto &&key : mp1) {
            dict.insert({ key.second, mp2[key.first] }) ;
        }
    }
    // printt(dict) ;
    for(auto &&x : s ){
        cout << dict[x] ;
    }
    cout << endl ;


    return 0;
}
