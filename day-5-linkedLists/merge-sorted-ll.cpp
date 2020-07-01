// Merge two sorted Linked List
// advanced without space - using stack space concept
#include<bits/stdc++.h>
using namespace std ;
#define fo(i, n) for(int i = 0; i < n; i++)
#define foo(i, k, n) for(int i = k; i < n; i++)
#define deb(x) {cout << #x << " " << x << endl ;}
#define IOS ios::sync_with_stdio(false), cin.tie(0) ;
#define MOD = 1e9+7 ;
const int N = 1e6+7 ;

struct Node{
    int data ;
    Node *next;
    Node(int d) : data(d), next(NULL) {}
};

Node *merge(Node *root1, Node *root2) {
    if(!root1){return root2 ;}
    if(!root2){return root1 ;}
    if(root1->data <= root2->data) {
        root1->next = merge(root1->next, root2) ;
        return root1;
    }else{
        root2->next = merge(root1, root2->next) ;
        return root2 ;
    }
}



int main(int argc, char const *argv[]){
    IOS ;
   
   Node *root1 = new Node(-41);
   root1->next = new Node(1);
   root1->next->next = new Node(3);
   root1->next->next->next = new Node(5);
   root1->next->next->next->next = new Node(15);

   Node *root2 = new Node(-51);
   root2->next = new Node(-1);
   root2->next->next = new Node(4);
   root2->next->next->next = new Node(8);

   root1 = merge(root1, root2);
   while(root1){
       cout << root1->data << " " ;
       root1 = root1->next ;
   }

    return 0;
}
