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
    
    unordered_map<int, int> cache ;
    int cars ;
    cin >> cars ;
    int answer = 0 ;
    fo(i, cars) {
        int xaxis, yaxis, velocity ;
        cin >> xaxis >> yaxis >> velocity ;
        int tmp = sqrt(pow((xaxis/velocity), 2) + pow((yaxis/velocity),2)) ;
        cache[tmp]++ ;
    }
    for(auto &&pp : cache) {
        if(pp.second != 1) {
            answer += (pp.second * (pp.second - 1)) / 2;
        }
    }
    cout << answer ;

    return 0;
}
