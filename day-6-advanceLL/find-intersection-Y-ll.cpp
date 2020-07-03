// Find intersection point of Y LinkedList 
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
    Node(int d ) : data(d), next(NULL) {}
};

int intersectionYpoint(Node *root1, Node *root2) {
    set<Node*> cache ;
    while(root1) { 
        cache.insert(root1) ; root1 = root1->next ; 
    }
    while(root2) {
        auto f = cache.find(root2) ;
        if(f == cache.end()) {
            root2 = root2->next;
        }else{ return root2->data; }
    }
    return -1 ;
}

int main(int argc, char const *argv[]){
    IOS ;
   
    Node *root1 = new Node(1) ;
    Node *root2 = new Node(1) ;

    root1->next = new Node(2) ;
    root2->next = new Node(4);
    root1->next->next = new Node(3) ;
    root1->next->next->next = new Node(6) ;
    root1->next->next = root1->next->next->next ; // merged manually

    if(intersectionYpoint(root1, root2) == -1) {
        cout << "no intersection avaible" << endl ;
    }else{
        cout << "intersection point is: " << endl ;
        cout << intersectionYpoint(root1, root2) << " " ;
    }

    return 0;
}
