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

    double x_l,y_l,x_w,y_w,f ;
    cin >> x_l ;
    cin >> y_l ;
    cin >> x_w ;
    cin >> y_w ;
    cin >> f ;

    double answer = 0;
    if ((y_l + y_w) == 0 ) {
        answer = x_l * f ;
    }
    answer = floor(answer) ;
    printf("%6f", answer) ;

    return 0;
}
