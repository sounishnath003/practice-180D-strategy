#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

void buildtree(vector<int> &nums, vector<int> &tree, int start, int end, int treenode) {
    if(start == end) {
        tree[treenode] = nums[start] ;
        return ;
    }
    int mid = (start + end) / 2 ;
    buildtree(nums, tree, start, mid, 2 * treenode) ;
    buildtree(nums, tree, mid + 1, end, 2 * treenode+1) ;
    tree[treenode] = tree[2*treenode] + tree[2*treenode + 1] ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    vector<int> nums {1,2,3,4,5,6,7,8,9};
    int n = nums.size() ;
    vector<int> tree(2*n);

    buildtree(nums, tree, 0, n-1, 1) ;
    for(auto x : tree) {
        cout << x << " " ;
    }

    return 0;
}
