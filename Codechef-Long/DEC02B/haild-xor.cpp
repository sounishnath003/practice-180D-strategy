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

int myXOR(int x, int y)
{
    int res = 0; // Initialize result

    // Assuming 32-bit Integer
    for (int i = 31; i >= 0; i--)
    {
        // Find current bits in x and y
        bool b1 = x & (1 << i);
        bool b2 = y & (1 << i);

        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);

        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}

/* 
    * traverse 0..n-1
    *  - i=0, j=1, p = log2( max(a[i], a[j]) )
    *  - i++, j++ ;
*/

void solve2() {
    int N,X;
    cin >> N >> X;
    vector<int> nums(N);        
    for(int i = 1; i < N+1; i++) {
        cin >> nums[i];
    }
    auto msb = [&](int n) -> int {
        return (int)  pow(2,(int) log2(n)) ;
    };
    fo(i,1,N+1) {
        int msb_i = msb(nums[i]);
        bool t = false;
        fo(j,i+1,N) {
            int msb_j = msb(nums[j]);
            if(msb_i == msb_j) {
                t = true;
                int p = log2( max(nums[i], nums[j]) ) ;
                nums[i] = nums[i] ^ (1 << p) ;
                nums[j] = nums[j] ^ (1 << p) ;
                break;
            }
        }
        if(!t) {
            int p = (int) log2(max(nums[i], nums[N])) ;
            nums[i] = nums[i] ^ (1 << p) ;
            nums[N] = nums[N] ^ (1 << p) ;
        }
    }
    cout << "FINAL ANS : "; debug() << imie(nums) ;
}

using matrix = vector<vector<longint>>;

void solve() {
    longint N,X, bits = 32;
    cin >> N >> X;
    vector<longint> nums;
    matrix dp(bits+1);
    fo(i,0,N) {
        int x; cin >> x;
        nums.push_back(x) ;
    }
    // detetmining Cases of mask Bit
    for(int i = 0; i < N; i++) {
        int x = nums[i];
        for(int j = bits; j >= 0; j--) {
            if(x & (1LL << j) ) {
                dp[j].push_back(i);
            }
        }
    }

    vector<longint> count_diff(bits+1);
    for(longint i = 0; i < N-1; i++) {
        for(longint j = bits; j >= 0; j--) {
            longint mask = (longint)  (1LL << j) ;
            if( (nums[i] & mask) == 0) {
                continue;
            }
            nums[i] = nums[i] ^ mask;
            // mask MSB bit - clone finding P(near to value of cur_elem)
            longint scnd = 0LL;
            if(++count_diff[j] < dp[j].size()) {
                scnd = dp[j][count_diff[j]++];
            } else {
                scnd = N-1;
            }
            nums[scnd] = nums[scnd] ^ mask;
            if(--X == 0) {
                break;
            }
        }
        if(X==0) {
            break;
        }
    }
    // if X times and 
    // N == even (can be fond N+1 release state like BellmanFord)
    if(X>0 && X % 2 == 1 && N == 2 ) {
        nums[N-1] ^= (1LL << 0) ;
        nums[N-2] ^= (1LL << 0) ;
    }

    debug () << imie(nums);

    // for(auto &&x : nums) {
    //     cout << x << " ";
    // }
    // cout << endl ;
}


int main() {
    int t;
    cin >>t;
    while(t--) {
        solve();
    }
}
