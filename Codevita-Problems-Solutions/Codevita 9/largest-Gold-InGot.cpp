#include <bits/stdc++.h>
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
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i <= n; i++)
typedef long long ll  ;
const int mod = 1e9 + 7 ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int length, breadth;
    cin >> length >> breadth;
    vector<int> ingots(n);
    fo(i, n) {
        cin >> ingots[i] ;
    }
    int spread = accumulate(ingots.begin(), ingots.end(), 0) ;
    int res = 0, ans = 0 ;
    stack<int> cache ; // index
    fo(i, n) {
        while( cache.size() && ingots[i] <= ingots[cache.top()]) {
            int topel = cache.top() ;
            cache.pop() ;
            debug() << imie(ans) ;
            res = ingots[topel] * ( cache.empty() ? i : (i - cache.top() - 1)) ;
            ans = max(ans % mod, res) ;
        }
        cache.push(i) ;
    }
    while(!cache.empty()) {
        debug() << imie(ans) ;
        int top = cache.top() ;
        cache.pop() ;
        res = ingots[top] * (cache.empty() ? n : (n - cache.top() - 1)) ;
        ans = max(ans % mod, res) ;
    }

    int vol = ((spread - ans) * length * breadth) % mod ;
    cout << "maximum volumn: " << vol << endl ;


}
