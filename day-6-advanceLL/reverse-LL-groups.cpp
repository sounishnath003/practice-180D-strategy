#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int data ;
    Node* next ;
    Node(int d) : data(d), next(NULL) { }
};

void print(Node* root) {
    while(root) {
        cout << root->data << " " ;
        root = root->next ;
    }
    cout << endl ;
}

// whole list got reversed
Node* reverse(Node* root) {
    if(!root or !root->next) {
        return root ;
    }
    Node* nextroot = reverse(root->next) ;
    root->next->next = root; 
    root->next = NULL ;
    return nextroot ;
}

// reverse in groups 
Node* reverse(Node* root, int range) {
    if((!root or !root->next) and range) {
        return root ;
    }
    Node* nextroot = reverse(root->next, --range) ;
    root->next->next = root; 
    root->next = NULL ;
    return nextroot ;
}

int main(int argc, char const *argv[]) {

    Node* root = new Node(1) ;
    root->next = new Node(2) ;
    root->next->next = new Node(3) ;
    root->next->next->next = new Node(4) ;

    print(root) ;

    root = reverse(root, 1) ;
    print(root) ;
    delete[] root ;
    

    return 0;
}
