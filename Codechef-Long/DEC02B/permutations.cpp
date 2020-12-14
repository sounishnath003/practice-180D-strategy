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
const int inf = 0x3f3f3f3f;
using longint = long long int;
#define fo(i, k, n) for(longint i = k; i < n; i++)

long long nPr(int n, int r, long long mod = 0)
{
    long long result = 1;
    for(int i = n-r+1; i <= n; i++) {result *= i; if(mod) result %= mod;}
    return result;
}

const int  P =  998244353 ;

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    auto moddedBY = [&] (int x) -> int {
        if (x < P) {
            return x;
        }
        return x - P;
    };

    int n;
    cin >> n;
    string w;
    cin >> w;
    
    std::vector<int> dp[2];
    dp[0] = {1};
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur ^= 1;
        dp[cur].assign(1 << (i / 2), 0);
        for (int s = 0; s < (1 << ((i - 1) / 2)); ++s) {
            int ns = s;
            if (i % 2 == 0) {
                ns |= 1 << ((i / 2) - 1);
            }
            dp[cur][ns] = moddedBY(dp[cur][ns] + dp[!cur][s]);
            for (int j = 1; j <= i / 2; ++j) {
                if (i % j == 0 && w[i / j - 1] == '1' && (ns >> (j - 1) & 1)) {
                    int t = ns & ~(1 << (j - 1));
                    dp[cur][t] = moddedBY(dp[cur][t] + dp[!cur][s]);
                }
            }
        }
    }
    
    std::vector<std::vector<int>> C(n + 1, std::vector<int>(n + 1));
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
        }
    }
    std::vector<int> fac(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = int64_t(fac[i - 1]) * i % P;
    }
    
    std::vector<int> f(n);
    for (int s = 0; s < (1 << (n / 2)); ++s) {
        int k = n / 2 - __builtin_popcount(s);
        f[k] = (f[k] + int64_t(dp[cur][s]) * fac[n - k]) % P;
    }
    
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (int j = i; j < n; ++j) {
            ans = (ans + int64_t(C[j][i]) * ((j - i) % 2 == 0 ? f[j] : P - f[j])) % P;
        }
        std::cout << ans << " ";
    }
    cout << endl ;
    
    return 0;
}
