/*
    author: Sounish Nath
    date: 2020-08-19 23:50:22
    problem: SLL to CDLL | (Ayush Kr. Shaw)
*/
#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;

struct Node{
    int data ;
    Node *left, *right ;
    Node(int data) : data(data), left(nullptr), right(nullptr) { }
};


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;

    int n;
    cin >> n ;
    vector<int> nums(n) ;
    for(int i = 0; i < n; i++) { cin >> nums[i] ; }
    Node* root = nullptr ;
    Node* firstnode = new Node(nums[0]);
    firstnode->left = new Node(nums.back()) ;
    root = firstnode ;
    for(int i = 1; i < n; i++) {
        root->right = new Node(nums[i]) ;
        root->right->left = root ;
        root = root->right ;
    }
    root->right = firstnode ;
    root = root->right ;
    while(n--) {
        cout << root->left->data << " " << root->data << " " << root->right->data << endl ;
        root = root->right ;
    }


    return 0;
}
