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
    vector<vector<int>> grid = {{1, 3, 3},
                                {2, 1, 4},
                                {0, 6, 4}};

    int H = grid.size(), W = grid[0].size();
    vector<vector<int>> dp(H, vector<int>(W, -1*inf));

    for(int col = W-1; col >= 0; col--) {
        for(int row = 0; row < H; row++) {
            int right = ( col == W-1) ? 0 : dp[row][col+1] ;
            int right_up = (row == 0 || col == W - 1) ? 0 : dp[row - 1][col + 1];
            int right_down = (row == H - 1 || col == W - 1) ? 0 : dp[row + 1][col + 1];
            dp[row][col] = grid[row][col] + max({right, right_up, right_down});
        }
    }
    debug () << imie (dp) ;
    int res = dp[0][0];
    for(int i = 1; i < (int) dp.size(); i++) {
        res = max(res, dp[i][0]);
    }
    debug () << imie(res) ;
}

int main() {
    srand(time(NULL));
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();

}