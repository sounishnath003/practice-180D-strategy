// author: Sounish Nath
// time: 15-08-2020, Codevita E
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long int ll;

int main() {
    int n, w, v, d;
    cin >> n >> w >> d;
    int a[n];
    int sum[n] = {};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> dpw(n + 10);
    vector<ll> dpwd(n + 10);
    ll temp = 0;
    for (int i = n - 1; i >= 0; i--) {
        temp = 0;
        for (int j = 0; j < w && i + j < n; j++) {
            temp += a[i + j];
            if (i + j + 2 < n) {
                dpw[i] = max(dpw[i], temp + dpw[i + j + 2]);
            }
            else {
                dpw[i] = max(dpw[i], temp);
            }
        }
        dpw[i] = max(dpw[i], dpw[i + 1]);
    }
    w += d;
    temp = 0;
    for (int i = n - 1; i >= 0; i--) {
        temp = 0;
        for (int j = 0; j < w && i + j < n; j++) {
            temp += a[i + j];
            if (i + j + 2 < n) {
                dpwd[i] = max(dpwd[i], temp + dpwd[i + j + 2]);
            }
            else {
                dpwd[i] = max(dpwd[i], temp);
            }
        }
        dpwd[i] = max(dpwd[i], dpwd[i + 1]);
    }
    if (dpw[0] < dpwd[0]) {
        cout << "Right" << " " << abs(dpw[0] - dpwd[0]) << endl;
    }
    else if (dpw[0] > dpwd[0]) {
        cout << "Wrong" << " " << abs(dpw[0] - dpwd[0]) << endl;
    }
    else {
        cout << "Both are Right" << endl;
    }
    
    return 0;
}