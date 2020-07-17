#include <bits/stdc++.h> 

using namespace std;
int findMinRec(vector<int> arr, int i, int sumCalculated, int sumTotal) {
    if (i==0)
        return max((sumTotal-sumCalculated), sumCalculated);
    return min(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal),
               findMinRec(arr, i-1, sumCalculated, sumTotal));
}
int main() {
    int n, sum = 0;
    string s ;
    vector<int> nums ;
    getline(cin, s, '\n') ;
    stringstream ss(s) ;
    while(ss >> n) {
        sum += n;
        nums.push_back(n) ;
    }
    
    cout << findMinRec(nums, nums.size(), 0, sum); 
    return 0;
}