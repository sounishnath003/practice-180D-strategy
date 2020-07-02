// Add two numbers as LinkedList
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

Node *addTwoList(Node *root1, Node *root2) {
    if(!root1) {
        return root2;
    }
    if(!root2) {
        return root1 ;
    }
    Node *answer = NULL, *t, *prev(NULL) ;
    int cursum = 0, carry = 0 ;
    while(root1 or root2) {
        cursum = carry + (root1 ? root1->data : 0 ) + (root2 ? root2->data : 0) ;
        carry = cursum > 9 ? 1 : 0 ;
        cursum %= 10 ;
        t = new Node(cursum) ;
        if(!answer) {
            answer = t ;
        }else prev->next = t ;
        if(root1) {root1 = root1->next ;}
        if(root2) {root2 = root2->next ;}
    } 
    if(carry > 0) { t->next = new Node(carry); };
    return answer ;
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
   
    Node *root1 = new Node(2) ;
    root1->next = new Node(3) ;
    Node *root2 = new Node(1) ;
    root2->next = new Node(0) ;
    print(root1) ;
    print(root2) ;

    Node *answer = addTwoList(root1=root1, root2=root2) ;
    print(answer) ;
    

    return 0;
}
