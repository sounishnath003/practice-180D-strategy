#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}
const int N = 1e9+7;

int fact(int n) {
    int c = 1;
    for (int i = 1; i <= n; i++) {
        c*= i;
    }
    return c ;
}

void go(vector<string> &books) {
    int cnt = 0 ;
    int n = books.size() -1 ;
    cout << (fact(n) + (n)) % N << endl  ;
}



int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;

    vector<string> books { "b1", "b2", "b3"} ;
    go(books) ;
   
    return 0;
}
