/*

Write a program to find prime numbers in a given range and 
do the encoding of these numbers using below encoding mechanism. 
 
Encoding Mechanism – Suppose there is a number n from 0 to 9.
So to encode it you have to get n¬th alphabet in the alphabet series (a to z) followed 
by there next consecutive alphabet up to n-1. 
 
Example –  
1. 5 – efghi (e is the 5th character in a-z and followed by 4 (n-1) characters). 
2. 47 – defgghijklm (for 4 – defg and for 7 - ghijklm). 
 
Input-  
Enter start value :10 
Enter end value :30 
 
Output-  
Prime Numbers between 10 and 30 
11 13 17 19 23 29 
aa, acde, aghijklm, aijklmnopq, bccde, bcijklmnopq 
 
OR 
 
11 -> aa 
13 -> acde 
17 -> aghijklm 
19 -> aijklmnopq 
23 -> bccde 
29 -> bcijklmnopq

*/


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
    int lo,hi;
    cin >> lo >> hi;
    vector<bool> tprime(hi+1, false);
    for(int i = 2; i*i <= hi; i++) {
        if(!tprime[i]) {
            for(int j = i*i; j <= hi; j+=i) { tprime[j] = true; }
        }
    }
    vector<string> primes;
    fo(i,lo,hi+1) {
        if(!tprime[i]) {primes.push_back(to_string(i));}
    }
    tprime.clear();
    debug () << imie (primes);
    vector<string> letters = { "", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
   for(auto prime : primes) {
       for(auto &x : prime) {
           int n = x-'0'; // 1 - 3
           for(int i = 0; i < n; i++) {
               cout << letters[n+i];
           }
       }
        cout << endl;
   }
}

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve();
    
}