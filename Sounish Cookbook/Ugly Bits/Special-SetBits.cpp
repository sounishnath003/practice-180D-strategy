/*
    author: Sounish Nath
    date: 2020-08-19 00:10:21
*/
#include<bits/stdc++.h>
using namespace std ;

void f(){
    int n, q;
    cin >> n >> q;
    int pre[n + 1] = {};
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pre[i] = pre[i - 1];
        if(x & (x << 1))
            pre[i]++;
    }
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
}

void go(vector<int> &nums, vector<pair<int, int>> &quires, int k) {
    bitset<8> kb(k) ;
    string pattern = kb.to_string() ;
    vector<bitset<32>> binarynums ;
    for (const int x : nums) {
        bitset<32> b(x) ;
        binarynums.push_back(b) ;
    }
    for(auto pp : quires) {
        int count = 0 ;
        for(int i = pp.first-1 ; i < pp.second; i++){
            string bb = binarynums[i].to_string() ;
            auto f = bb.find(pattern) ;
            if (f != string::npos ){
                count++ ;
            }
        }
        cout << count << endl ;
    }
}



int main(int argc, char const *argv[]){
    IOS ;
    
    int n, k ;
    cin >> n >> k;
    vector<int> nums(n) ;
    for(int i = 0 ; i < n; i++) {
        cin >> nums[i] ;
    }
    vector<pair<int, int>> quires ;
    for(int i = 0 ; i < k; i++)  {
        int x, y ;
        cin >> x >> y ;
        quires.push_back({x, y}) ;
    }
    go(nums, quires, 3) ;

    return 0;
}



/*
-------------------
Explanation:
--------------------
We can note that if a number has consecutive bits set, then on left-shifting its bits by 1
and doing AND operation on that number will give some non-zero value. Let us take a number 3. Its binary equivalent is 011,
on shifting its bits by 1 on left side results in 110. And doing and with 011 gives 010 which is non zero.
So its a special number. Now to answer range query we can maintain prefix sum array.
Pre[i] contains Count of special number upto index i. So queries can be answered by using relation -
Ans [l,r] = pre[r] - pre[l-1].
*/