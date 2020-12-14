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

// not fully functionall!
void solve2() {
    int n,k;
    cin >> n >> k;
    if(k>n){
        return;
    }

    vector<int> nums(n+1);
    fo(i,0,n+1)
        nums[i]=i;

    if(n%2==0) {
        for(int i = 0; i < n; i++){ if(i%2==1) { nums[i] *= -1; } }
    }else {
        for(int i = 0; i < n; i++){ if(i%2==0) { nums[i] *= -1; } }
    }

    debug() << imie(nums);
    int pos=0;
    for_each(nums.begin(), nums.end(), [&](int x) { pos+= x > 0; });
    debug() << imie(pos);
    int i = 1;

    int sum=0;
    while(i<=n) {
        sum+=nums[i]; // -1+2=1
        if(sum>0){
            if(pos<k){
                int diff = k-pos; // 6-5=1
                for(int i = n; i >=1; i--) {
                    if(diff) {
                        if(nums[i] < 0) {
                            nums[i] *= -1;
                            pos++;
                            diff--;
                        }
                    }
                }
                if(pos==k) {
                    debug() << imie(nums);
                    return;
                }
            }

            if(k<pos) {
                int diff = pos-k; // 3-2=1
                for(int i = n; i >=1 ; i--) {
                    if(diff) {
                        if(nums[i]>0) {
                            nums[i]*=-1;
                            pos--;
                            diff--;
                    }
                    }
                }
                if(k==pos) {
                    debug() << imie(nums);
                    return;
                }
            }
        }
    }
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> nums(n+1);
    fo(i,0,n+1)
        nums[i] = i;
    // debug() << imie(nums);

    // corner case
    if(k > n)
        return;
    
    // conditions 1 - Even(N)
    if(!n&1) {
        for(int i = 0; i < n; i++){ if(i%2==1) { nums[i] *= -1; } }
    }else {
    // conditions 2 - Odd(N)
        for(int i = 0; i < n; i++){ if(i%2==0) { nums[i] *= -1; } }
    }

    // count How many positibes
    int postivies = 0;
    fo(i,1,n+1){ postivies += nums[i] > 0; }

    
    // condition TotalSum > 0 (a[i]...a[k])
    int total = 0;
    fo(i,1,n+1){
        total += nums[i];
        if(total > 0) {
            if(postivies < k) {
                int df = k-postivies;
                for(int i = n; i >= 0 && df > 0; i--) {
                    if(nums[i] < 0) {
                        nums[i] = -nums[i];
                        postivies++;
                        df--;
                    }
                }
                if(postivies == k) {
                    break;
                }
            }
            else {
                int dif = postivies-k;
                for(int i = n; i >= 0 && dif > 0; i--) {
                    if(nums[i] > 0) {
                        nums[i] = -nums[i];
                        postivies--;
                        dif--;
                    }
                }
                if(k == postivies) {
                    break;
                }
            }
        }
    }
    for(int i = 1; i < n+1; i++) {
        cout << nums[i] << " ";
    }
    cout << endl; 
}

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        solve();
    }
    
}