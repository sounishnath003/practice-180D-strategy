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

void solve2() {
    string s;
    getline(cin, s);
    longint n = s.length() ;
    vector<string> subsets[n+1];
    fo(i,0,n) {
        int l = 0;
        fo(len, 1, n - i + 1) {
            subsets[len].push_back(s.substr(i,len));
            l = len;
        }
        sort(subsets[l].begin(), subsets[l].end()) ;
    }
    set<string> matched, unmatched;
    auto countZeros = [&](string &s) -> int {
        int c=0;
        for(auto &&x : s) {
            if(x == '1') {
                c++;
            }
        }
        return c;
    };
    for (auto &&row : subsets){
        // debug () << imie (row) ;
        for(auto str : row) {
            string t = str;
            int ones = countZeros(str) ;
            if(ones % 2 == 0) {
                debug () << imie(str) ;
                reverse(t.begin(), t.end());
                // auto f = find_if(row.begin(), row.end(), [&](string &tt) {return tt == t ;});
                matched.insert(str) ;
            } else {
                unmatched.insert(str);
            }
        }
    }
    
    //debug () << imie(matched) ;
    //debug () << imie(unmatched) ;

    cout << "Equivalence class : " << matched.size()+unmatched.size() << endl ;

}

using P = pair<int, int>;
using doublePaired = pair<P,P>;

void solve() {
    string s;
    cin >> s;

    auto computeConditionsString = [&](string& s, int &size, int num1, int num0, vector<int>& queued, int sumO, int sumE, int n) -> int {
        set<doublePaired> cached;
        cached.insert(make_pair(make_pair(num1, num0), make_pair(sumO, sumE)));
        fo(i,size,n){
            if(s[i-size] == '1') {
                queued.erase(queued.begin()); // popped up *begin
                int t = sumE;
                sumE = sumO;
                sumO = t;
                num1--;
            } else {
                num0--;
                queued[0] -= 1;
                sumE--;
            }
            // next channel 1
            if (s[i] == '1') {
                num1++;
                queued.push_back(0);
            } else {
                num0++;
                queued[(int)queued.size()-1]+=1;
                if((int) queued.size() % 2 == 1) { sumE++; }
                else {sumO++;}
            }
            cached.insert(make_pair(make_pair(num1, num0), make_pair(sumO, sumE)));
        }
        return (int) cached.size() ;
    };
    
    int n = s.length() ;
    int answer = 0;
    int x = 0;
    fo(i,0,n) {
        vector<int> lists;
        int num0=0,num1=0,sumE=0,sumO=0,curr=0, rht = 0;
        x = i+1;
        fo(j,0,i+1) {
            if(s[j] == '0') {
                if((curr&1)==false) {
                    sumE++;
                }else {
                    sumO++;
                }
                rht++;
                num0++;
            } else {
                lists.push_back(rht);
                rht = 0;
                curr++;
                num1++;
            }
        }
        lists.push_back(rht);
        debug () << imie(rht) imie (num0) imie(num1) imie(curr) ;
        answer += computeConditionsString(s,x,num1,num0,lists,sumO,sumE, n);
    }
    debug () << imie (answer) ;
    answer = 0;
}

int main() {
    srand(time(NULL)) ;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

}
