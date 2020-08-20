// Add two numbers as LinkedList
#include<bits/stdc++.h>
#define print(nums) { for(auto &&x : nums) { cout << x << " " ; } cout << endl ; }
using namespace std ;

struct Node {
    int data ;
    Node* next ;
    Node(int data) : data(data), next(NULL) { }
};

void _print(Node *root) {
    while(root) {
        cout << root->data << " " ;
        root = root->next ;
    }
    cout << endl ;
}

Node *addTwoList(Node *root1, Node *root2) {
    if(!root1) {
        return root2;
    }
    if(!root2) {
        return root1 ;
    }
    Node *answer = NULL, *t, *prev(NULL) ;
    int cursum = 0, cry = 0 ;
    while(root1 or root2) {
        cursum = cry + ( root1 ? root1->data : 0 ) + ( root2 ? root2->data : 0 ) ;
        cry = (cursum > 9) ? 1 : 0 ;
        cursum %= 10 ;
        t = new Node(cursum) ;
        if(!answer) { answer = t ; }
        else {
            prev->next = t ;
        }
        prev = t ;
        if(root1) { root1 = root1->next ; }
        if(root2) { root2 = root2->next ; }
    }
    if(cry > 0) {
        t->next = new Node(cry) ;
    }
    return answer ;
}

Node* optimisedAddList(Node* root1, Node* root2) {
    Node* ans = nullptr ;
    Node** node = &ans ;
    int sum = 0 ;
    while(root1 or root2 or sum > 0) {
        if(root1) { sum += root1->data ; root1 = root1->next ; }
        if(root2) { sum += root2->data ; root2 = root2->next ; }
        (*node) = new Node(sum % 10) ;
        sum = sum / 10 ;
        node = &((*node)->next) ;
    }
    return ans ;
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    
    Node* root = new Node(2);
    root->next = new Node(4);
    root->next->next = new Node(3) ;

    Node* root2 = new Node(5);
    root2->next = new Node(6) ;
    root2->next->next = new Node(4) ;

    Node *ans = optimisedAddList(root, root2);
    _print(ans) ;

    
    
    return 0;
}
