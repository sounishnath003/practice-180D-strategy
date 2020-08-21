// author: Sounish Nath
// time: 15-08-2020, Codevita B
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

// basic binary bits().
int movedOutBits(int &n, vector<int> &binaries, int index){
    int ans = 0;
    while(n){
        if(n & 1){
            binaries[index]++ ;
        }
        n = n >> 1 ;
    }
    return ans ;
}

// recursive choice Greedyly
void _fSecretSounish(int i, vector<int> &binaries, int sizz , int ss, int &ttox) {
    if(i == sizz){
        if( ss == 0 ){ ttox++ ; } // tbits to inc().
        return ;
    }
    _fSecretSounish(i + 1, binaries, sizz, ss + binaries[i], ttox); // considering + 1
    _fSecretSounish(i + 1, binaries, sizz, ss, ttox) ; // without choice ing the state
}

int main(int argc, char const *argv[]){
    IOS ;
   
    int n;
    cin >> n;
    vector<int> nums(n) ;
    fo(i, n) {
        cin >> nums[i] ;
    }
    int mm = *max_element(nums.begin(), nums.end());
    auto countBITS = [&] (int n){
        int c = 0 ;
        while(n){
            c++ ;
            n >>= 1 ;
        }
        return c ;
    };
    int count_bits = countBITS(mm) ;
    vector<int> binaries(n);
    fo(i, n){
        movedOutBits( nums[i], binaries, i );
    }
    // print(binaries)
    int jIdx = 0;
    fo(i, n){
        binaries[jIdx] = count_bits - 2 * binaries[i] ;
        if(binaries[jIdx] == 0){
            continue ;
        }else{
            jIdx++ ;
        }
    }
    int _ttotx = 0 ;
    _fSecretSounish(0, binaries, jIdx, 0, _ttotx) ;
    _ttotx-- ;
    _ttotx = _ttotx * ( 1 + n - jIdx ) + (1 << (n - jIdx)) - 1 ;
    // deb(_ttotx ) ;
    vector<int> bincount(count_bits, 0);
    int index = 0 ;
    while(_ttotx) {
        bincount[index] = _ttotx & 1 ;
        _ttotx = _ttotx >>  1 ;
        index++ ;
    }
    for(int i = count_bits - 1; i >= 0; i--){
        cout << bincount[i] ;
    }

    return 0;
}
