// Remove N-th node from back of LinkedList
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct Node{
    int data;
    Node *next ;
    Node(int d) : data(d), next(NULL) {}
};

void _deleteNthNode(Node *root, int pos) {
    if(!root) {return ;}
    fo(i, pos - 1) {root = root->next ;}
    Node *p = root->next->next ;
    delete root ;
    root->next = p ;
}

void print(Node *root) {
    while(root) {
        cout << root->data << " " ;
        root = root->next ;
    }
    cout << endl ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    Node *root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->next->next = new Node(4);
    root->next->next->next->next = new Node(5);
    print(root) ;
    
    _deleteNthNode(root, 3) ;
    print(root) ;

    return 0;
}
