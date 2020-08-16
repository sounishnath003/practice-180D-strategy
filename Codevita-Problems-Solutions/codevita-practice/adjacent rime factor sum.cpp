#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void operator<<(ostream &os, vector<int > &v){
    for (const int x : v) {
        cout << x << " " ;
    }
    cout << endl ;
}


vector<int> runSieve(int upperBound) {
  vector<int> results ;
  int upperBoundSquareRoot = (int)sqrt((double)upperBound);
  bool *isComposite = new bool[upperBound + 1];
  memset(isComposite, 0, sizeof(bool) * (upperBound + 1));
  for (int m = 2; m <= upperBoundSquareRoot; m++) {
    if (!isComposite[m]) {
      cout << m << " ";
      for (int k = m * m; k <= upperBound; k += m)
        isComposite[k] = true;
    }
  }
  for (int m = upperBoundSquareRoot; m <= upperBound; m++)
    if (!isComposite[m])
      results.emplace_back(m) ;
  delete [] isComposite;
  return results ;
}


bool go(int n) {
    vector<int> primes = runSieve(2*n) ;
    auto itr = upper_bound(primes.begin(), primes.end(), n) ;
    int next_prime = *itr ;
    int sum = n + next_prime ;
    for (int i = 2; i <= (int)sum/2; i++) {
        if (n % i == 0) {
            if (primes[i] == 0) {
                return false ;
            }
        }
    }
    return true ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    int n = 11 ;
    if(go(n)) {
        cout << "yes" ;
    }else {
        cout << "no" ;
    }

    return 0;
}
