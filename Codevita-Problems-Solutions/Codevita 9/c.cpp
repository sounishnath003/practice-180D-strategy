// author : Sounish Nath
// time: 15-08-2020, codevita 9
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
const int mod = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long int lli ;

void test_case() {
    lli n, prefsum = 0;
    cin >> n;
    lli aBreath, bHeight;
    cin >> aBreath >> bHeight;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    prefsum = accumulate(arr.begin(), arr.end(), 0);
    lli res = 0, ans = 0;
    stack<int> cache;
    for (int i = 0; i < n; i++)
    {
        while (!cache.empty() and arr[i] <= arr[cache.top()])
        {
            lli tp = cache.top();
            cache.pop();
            res = arr[tp] * (cache.empty() ? i : (i - cache.top() - 1));
            ans = max(ans % mod, res);
        }
        cache.push(i);
    }
    while (!cache.empty()) {
        lli tp = cache.top();
        cache.pop();
        res = arr[tp] * (cache.empty() ? n : (n - cache.top() - 1));
        ans = max(ans % mod, res);
    }
    auto f = ((prefsum % mod - ans % mod) % mod * aBreath % mod * bHeight % mod) % mod;
    cout << f << endl;
}

int main() {
    IOS
        
    test_case() ;

    return 0 ;
}