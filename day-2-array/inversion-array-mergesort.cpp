// Inversion of Array(Using Merge Sort)
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void mergesort(int &answer, vector<int>::iterator start, vector<int>::iterator end) {
    if (end - start > 1){
        answer += 3 ;
        vector<int>::iterator mid = start + (end - start) / 2;
        mergesort(answer, start, mid);
        mergesort(answer, mid, end);
        inplace_merge(start, mid, end);
    }
}

int main(int argc, char const *argv[]){
    IOS ;

    // simple  approch - O(N*N)
    vector<int> nums { 8, 4, 2, 1 } ;
    int n = (int) nums.size() ;
    int answer = 0 ;
    int answer2 = 0 ;
    fo(i, n){
        for(int j = i + 1; j < n; j++){
            answer += (nums[i] > nums[j]) ;
        }
    }
    cout << answer << endl ;

    // mergesort approch  O(NlogN)
    mergesort(answer2, nums.begin(), nums.end()) ;
    cout << answer2 << endl ;

    return 0;
}
