// Delete a given Node when a node is given.(0(1)solution)
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct Node {
    int data ;
    Node *next ;
    Node(int d) : data(d), next(NULL) {}
};

// O(N) solution - slow solution
void deleteNode(Node *root, int val) {
    if(!root) {return ;}
    while(root && root->next->data != val) { root = root->next ; }
    if(!root) { exit(1) ;}else{cout << "started deleting node\n" ;}
    Node *p = root->next->next ;
    delete root->next ;
    root->next = p ;
}

// optimized O(1) delete given node
void optimizedDeleteNode(Node *root, int val) {
    if(!root) {return ;}
    stack<Node*> cache ;
    Node *p ;
    while(root && root->data != val) {
        if(root->next->data == val) {
            p = root->next->next ;
            delete root->next ;
            root->next = p ;
            break ;
        }else{
            cache.push(root) ;
            root = root->next ;
        }
    }
}

void print(Node *root) {
    while(root) {
        cout << root->data << "  ";
        root = root->next ;
    }
    cout << endl ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
   Node *root = new Node(1) ;
   root->next = new Node(2);
   root->next->next = new Node(4);
   root->next->next->next = new Node(6);
   root->next->next->next->next = new Node(-2) ;
   print(root) ;

   deleteNode(root, -2) ;
   print(root) ;
   optimizedDeleteNode(root, 4) ;
   print(root) ;


    return 0;
}
