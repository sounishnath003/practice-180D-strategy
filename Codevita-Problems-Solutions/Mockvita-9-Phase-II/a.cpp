#include<bits/stdc++.h>
using namespace std ;

int go(string& brides, string& grooms){
    int answer = 0 ;
    for(auto &&x : brides){
        auto f = grooms.find_first_of(x) ;
        if(f != string::npos) {
            grooms.erase(f, 1) ;
        }
    }
    return answer =  grooms.size() ;
}

int main(int argc, char const *argv[]){
       
    int n ;
    cin >> n ;
    string brides , grooms ;
    cin >> brides >> grooms ;

    cout << go(brides, grooms) << endl ;

    return 0;
}
