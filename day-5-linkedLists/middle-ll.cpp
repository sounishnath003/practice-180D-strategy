// Find middle of LinkedList
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
    static Node *node(Node *root){
        return root; 
    }
};

struct LinkedList {
    Node *root = new Node((int)NULL);
    void push(int data) {
        Node *t = new Node(data);
        t->next = root ;
        root = t ;
    }
    int middle(){
        Node *fast = Node::node(root);
        Node *slow = Node::node(root);
        while(fast->next != NULL && fast != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow->data ;
    }
    void print() {
        while(root) {
            cout << root->data << " " ;
            root = root->next ;
        }
        cout << endl ;
    }
};

int main(int argc, char const *argv[]){
    IOS ;
   
    LinkedList linkedlist ;
    linkedlist.push(1);
    linkedlist.push(2);
    linkedlist.push(3);
    linkedlist.print() ;
    cout << linkedlist.middle();

    return 0;
}
