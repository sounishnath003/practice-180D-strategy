// author : Sounish Nath
// time: 15-08-2020, codevita 9
// Wrong for private testcase [ never throught; for a cache needs to update and monitor state ]
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
const int mod = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long int ll ;

int main(int argc, char const *argv[]){
    IOS ;

    int n;
    cin >> n;
    int breadth, height ;
    cin >> breadth >> height ;
    long long int answer = 0, result = 0 ;
    vector<int> goldsIngot(n) ;
    fo(i, n) {
        cin >> goldsIngot[i] ;
    }
    long long int prefsumm = accumulate(goldsIngot.begin(), goldsIngot.end(), 0) ;
    // deb(prefsumm) ;
    stack<int> cache ;
    fo(i, n) {
        while(!cache.empty() && goldsIngot[i] <= goldsIngot[cache.top()] ){
            long long int cachetop = cache.top();
            cache.pop();
            result = goldsIngot[cachetop] * (cache.empty() ? i : (i - cache.top() - 1));
            answer = max(answer % mod, result);
        }
        cache.push(i) ;
    }
    while(!cache.empty()){
        long long int tps = cache.top() ;
        cache.pop() ;
        result= goldsIngot[tps] * ( cache.empty()? n: (n-tps-1) );
        answer = max(answer % mod, result) ;
    }
    int final =  ((prefsumm % mod - answer % mod) % mod * breadth % mod * height % mod) % mod ;
    cout << final << endl ;

    return 0;
}