// Excel Column Number
// ascii calculation - O(1)
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

int main(int argc, char const *argv[]){
    IOS ;
   
   vector<int> columns {12,10,26,51,52,80,676,702,705};
   for(auto &&n : columns){
       cout << n << setw(15) ;
       string answer = "" ;
       while(n){
           int rem = n % 26 ;
           if(rem == 0) {
               answer += "Z" ;
               n = (n / 26) ;
           }else{
               answer += (rem - 1) + 'A' ;
               n /= 26 ;
           }
       }
       reverse(answer.begin(), answer.end()) ;
       cout << answer << endl ;
   }

    return 0;
}
