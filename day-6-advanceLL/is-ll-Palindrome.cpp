// Check if a LinkedList is palindrome or not. 
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
} ;

int main(int argc, char const *argv[]){
    IOS ;
    auto is_palindrome = [&](const Node *root) {
        if(!root) {return false ; }
        stack<int> cache ;
        while(root) {
            cache.push(root->data) ;
            root = root->next ;
        }
        while(root) {
            if(root->data != cache.top()) {
                return false ;
            }
            cache.pop() ;
            root = root->next ;
        }
        return true ;
    };
    
    Node *root = new Node(1) ;
    root->next = new Node(2) ;
    root->next->next = new Node(1) ;

    cout << is_palindrome(root) << endl ;

    return 0;
}
