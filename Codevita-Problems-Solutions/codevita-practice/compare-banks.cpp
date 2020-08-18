#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

// EMI = loanAmount * monthlyInterestRate / ( 1 – 1 / (1 + monthlyInterestRate)^(numberOfYears * 12))

int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    int p = 10000, y = 20, n ;
    int yrs ,  s ;
    int bank[10], cnt = 0 ;

    for(int i = 0; i < 2; i++) {
        scanf("%d", &n) ;
        int sum = 0 ;
        for (int i = 0; i < n; i++) {
            scanf("%d", &yrs ) ;
            scanf("%d", &s ) ;
            int sq = pow((1 + s), yrs*12) ;
            int emi = (p * (s))/ (1 - 1/sq) ;
            sum += emi ;
        }
        bank[cnt++] = sum ;
    }
    cout << endl ;
    min(bank[0], bank[1]) ? cout << "Bank A" << endl  : cout << "Bank B" << endl  ;
   
    return 0;
}
