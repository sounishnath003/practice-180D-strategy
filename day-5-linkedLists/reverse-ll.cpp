// Reverse a LinkedList
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

struct LinkedList {
    Node *root ;
    LinkedList() : root(NULL) {} 
    void push(int data) {
        Node *t = new Node(data);
        t->next = root ;
        root = t ;
    }
    void reverse() {
        Node *cr = root ;
        Node *prev, *next;
        prev = next = NULL;
        while(cr) {
            next = cr->next ;
            cr->next = prev ;
            swap(prev, cr->next) ;
        }
        root = prev ;
    }
    void print(){
        while(root){
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
    linkedlist.push(5);
    linkedlist.print();
    linkedlist.reverse();
    linkedlist.print() ;

    return 0;
}
