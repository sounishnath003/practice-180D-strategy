#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std ;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
template < class c > struct rge { c b, e; };
template < class c > rge<c> range(c i, c j) { return rge<c>{i, j}; }
template < class c > auto dud(c* x) -> decltype(cerr << *x, 0);
template < class c > char dud(...);
struct debug {
 ~debug() { cerr << endl; }
 template < class c > typename \
 enable_if<sizeof dud<c>(0) != 1, debug&>::type operator<<(c i) { cerr << boolalpha << i; return * this; }
 template < class c > typename \
 enable_if<sizeof dud<c>(0) == 1, debug&>::type operator<<(c i) {return * this << range(begin(i), end(i)); }
 template < class c, class b > debug & operator << (pair < b, c > d) { return * this << "(" << d.first << ", " << d.second << ")";}
 template < class c > debug & operator <<(rge<c> d) { *this << "["; for (auto it = d.b; it != d.e; ++it) *this << ", " + 2 * (it == d.b) << *it; return * this << "]";}
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
typedef long long ll;
#define fo(i, k, n) for(int i = k; i < n; i++)
const int inf = 0x3f3f3f3f;
using longint = long long int;

void solve() {
    int N, D;
    cin >> N >> D;
    vector<int> ages(N);
    for(auto &&x : ages) {
        cin >> x;
    }
    int in_risk=0, not_risk=0;
    for(auto &&age : ages) {
        if(age>=80 or age <=9){
            in_risk++;
        }else {
            not_risk++;
        }
    }
    int days = ceil(in_risk*1.0/D*1.0)+ceil(not_risk*1.0/D*1.0);
    cout << days << endl;
}

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
}