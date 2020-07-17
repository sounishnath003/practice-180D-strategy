#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;
typedef long long ll ; 



vector<ll>& runSeive(int st, int n){ 
    bool prime[n - st + 1]; 
    vector<ll> *primes = new vector<ll>;
    memset(prime, true, sizeof(prime)); 
  
    for (int p=st; p*p<=n; p++)  { 
        if (prime[p] == true)  { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
    for (int p=2; p<=n; p++) {
       if (prime[p]) {
          primes->push_back(p);
       }
    }
    return *primes ;
}


ll go(int start, int end) {
    auto isprime = [&](const ll n) {
        for(int i = 2; i * i <= n ; i++) {
            if (n % i == 0) {return false ;}
        }
        return true ;
    };
    vector<ll> primes = runSeive(start, end) ;
    vector<string> primesString ;
    for(auto &&i : primes) {
        primesString.push_back(to_string(i)) ;
    }
    set<ll> gp ;
    for(auto &&i : primesString) {
        for(auto && j : primesString) {
            ll newpInt = (long) stoll(i + j);
            if (isprime(newpInt)){
                gp.insert(newpInt) ;
            }
        }
    }
    ll a = *min_element(gp.begin(), gp.end()) ;
    ll b = *max_element(gp.begin(), gp.end()) ;
    ll c = 0 ;
    deb(a); deb(b) ;
    for(int i = 0; i < (int) gp.size() - 2; i++) {
        c = a + b ;
        swap(a,b);swap(b,c) ;
    }
    return c ;
}



int main(int argc, char const *argv[]){
    IOS ;
   
    int n, m ;
    cin >> n >> m ;
    cout << go(n, m) << endl ;

    return 0;
}
