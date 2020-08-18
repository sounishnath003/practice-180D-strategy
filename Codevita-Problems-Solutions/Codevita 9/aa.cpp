// author: sounish nath
// time: 15-08-2020, codevita problem A
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
#define MOD = 1e9+7 ;
const int N = 100 ;

void sol1(){
    int n ;
    cin >> n ;
    vector<vector<char>> bricks(n, vector<char>(n)) ;
    int answer = 0 ;
    fo(i, n) {
        for(int j = 0; j < n; j++) {
            cin >> bricks[i][j] ;
        }
    }
    for(int i = 0; i < n; i++) {
        print(bricks[i])
    }
    fo(i, n) {
        for(int j = 0; j < n; j++) {
            if( bricks[i][j] == 'D' ){
                answer++ ;
            }
        }
    }
    answer = floor(sqrt(answer));
    cout << answer << endl ;
}


int givemetheFuckingAREA(int hist[], int n) {
    stack<int> cache;

    int max_area = 0;  
    int tp;            
    int area_with_top; 
    int i = 0;
    while (i < n) {
        if (cache.empty() || hist[cache.top()] <= hist[i])
            cache.push(i++);
        else {
            tp = cache.top(); 
            cache.pop();      
            // area cacl
            area_with_top = hist[tp] * (cache.empty() ? i : i - cache.top() - 1);
            // update max
            max_area = max( max_area, area_with_top ) ;
        }
    }
    // last check same area for top bars
    while (!cache.empty())
    {
        tp = cache.top();
        cache.pop();
        area_with_top = hist[tp] * (cache.empty() ? i : i - cache.top() - 1);

        if (max_area < area_with_top)
            max_area = area_with_top;
    }

    return max_area;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    int n ; 
    cin >> n ;

    char arr[N][N] ;
    int vec2[N][N] ;
    int roow[N], col[N] ;
    fo(i, n){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j] ;
        }
    }
    fo(i, n){
        for(int j = 0; j < n ; j++) {
            if(arr[i][j] == 'D') {
                vec2[i][j] = 0 ;
            }else{
                vec2[i][j] = 1 ;
            }
        }
    }
    fo(i, n){
        int pretotal = 0 ;
        // int pretotal2 = 0 ;
        for(int j = 0 ; j < n ; j++) {
            pretotal += vec2[i][j] ;
            // pretotal2 += vec2[j][i] ;
        }
        roow[i] = n - pretotal ;
        // col[i] = n - pretotal2 ;
    }
    fo(i, n){
        // int pretotal = 0 ;
        int pretotal2 = 0 ;
        for(int j = 0 ; j < n ; j++) {
            // pretotal += vec2[i][j] ;
            pretotal2 += vec2[j][i] ;
        }
        // roow[i] = n - pretotal ;
        col[i] = n - pretotal2 ;
    }
    auto amIPerfectSq = [&](int n) {
        // pure maths func (GFG)
        for(int in = 1; in * in <= n; in++) {
            if( (n % in == 0) and (n / in == in) ) {
                return true ;
            }
        }
        return false ;
    };
    int counnt = 0 ;
    fo(i, n) {
        if(roow[i] != 0) { break ; }
        else{ counnt++ ; }
    }
    int anothercount = 0 ;
    fo(i, n) {
        if(col[i] != 0) {
            break ;
        }else {
            anothercount++ ;
        }
    }
    if(counnt  == n and anothercount == n) {
        cout << "0" ;
    }else{
        int ar1, ar2 ;
        ar1 = givemetheFuckingAREA(roow, n) ;
        ar2 = givemetheFuckingAREA(col, n) ;
        // deb(ar1); deb(ar2) ;
        // check if perfect sq
        bool t1 = amIPerfectSq(ar1);
        bool t2 = amIPerfectSq(ar2) ;
        if(t1 && t2) {
            int _m = max( sqrt(ar1), sqrt(ar2) ) ;
            cout << _m ;
        }else if( t1 && !t2 ){
            cout << sqrt(ar1)  ;
        }else if(!t1 &&  t2 ) {
            cout << sqrt(ar2) ;
        }else{
            cout << "1" ;
        }
    }


    return 0;
}



/*

** Test Cases **
4
C D C D
C C D C
D D D D
C D D D

------------

7
C D D C D D D
C D D C D D D
D D D D D D C
D C D C D D D
D D D C D C D
C D D C D C C
C D C D C C C

*/