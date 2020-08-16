#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

void print(vector<int>& v) {
    copy(v.begin(), v.end(), ostream_iterator<int>  {cout, " "}) ; cout << endl ;
}

void go(int rupee) {
    vector<int> coins;
    for(int i = 1; i <= round((double)rupee/2); ++i) coins.emplace_back(i) ;
    vector<int> pref ; pref.emplace_back(0) ;
    for(const int x : coins) {
        if (pref.back() + x <= rupee){
            pref.emplace_back(pref.back() + x); 
        }
    }
    cout << pref.size() - 1 << endl ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int rupee = 10 ;
    go(rupee) ;
   
    return 0;
}
