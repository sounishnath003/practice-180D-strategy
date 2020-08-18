#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

bool prime(int &n) {
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) return false ;
    }
    return true ;
}

vector<int> primes ;

void go(int &range) {
    for (int i = 2 ; i <= range; i++) {
        if (prime(i)) primes.emplace_back(i) ;
    }
    int sum = 2, cnt = 0 ;
    for (int i = 1; i < primes.size(); i++) {
        sum += primes[i] ;
        if (sum > primes[primes.size() -1]) break ;
        if(binary_search(primes.begin(), primes.end(), sum)) cnt++ ;
    }
    deb(cnt) ;
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int range = 20 ;
    go(range) ;
   
    return 0;
}
