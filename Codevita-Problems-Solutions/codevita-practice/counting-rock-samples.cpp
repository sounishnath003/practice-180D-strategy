#include<bits/stdc++.h>
#define fo(i, n) for(int i = 0; i < n; i++)
using namespace std ;
#define deb(x) {cout << #x << " " << x << endl ;}

bool go(int &rock, int &lo, int &hi) {
    if (lo <= rock and rock <= hi) {return true ;}
    else {return false ;}
}


int main(int argc, char const *argv[]){
    ios::sync_with_stdio(0) ;
    freopen("inp.txt", "r", stdin) ;


    int n, sample_size ;

    cin >> n >> sample_size ;
    vector<int> rocks ;

    for (int i = 0; i < n; i++) {
        int l ; cin >> l ;
        rocks.push_back(l) ;
    }


    for(int i = 0; i < sample_size; i++) {
        int lo, hi, cnt = 0 ;
        cin >> lo >> hi ;
        for(int rock : rocks ) {
            cnt += go(rock, lo, hi) ;
        }
        cout << cnt << " " ;
    }
    
   
    return 0;
}
