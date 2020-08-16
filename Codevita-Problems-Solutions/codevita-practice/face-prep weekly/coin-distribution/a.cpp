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
    
    int ammount ;
    cin >> ammount ;
    
    auto min_coins = [&](int &ammount) {
    	int five = (ammount - 4) / 5  ;
    	ammount -= five * 5 ;
    	int one = (ammount & 1) ? 1 : 2 ;
    	ammount -= one ;
    	int two = ammount / 2;
    	printf("%d %d %d %d\n", (five + one + two), five, two, one );
	};
	
	min_coins(ammount) ;    

    return 0;
}
