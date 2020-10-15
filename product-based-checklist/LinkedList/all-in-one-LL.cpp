#include<bits/stdc++.h>

using namespace std ;

// struct of Node
struct Node {
	int data;
	Node* next;
	Node(int d) : data(d), next(NULL){ }
};

struct LinkedList {
	Node* root = NULL ;
	
	LinkedList(){ }
	void insertNode(int data) {
		Node* t = new Node(data);
		t->next = root;
		root = t;
	}
	void printList(){
		while(root){
			cout << " -> ";
			cout << root->data << " ";
			root = root->next;
		}
		cout << endl;
	}
	void is_cyclic(){
		Node* slow = root, *fast = root;
		while(fast && fast->next){
			if(slow == fast){
				cout << "cycle detected\n";
				return;
			}
			fast = fast->next->next;
			slow = slow->next;
		}
		cout << "cycle not detected\n";
	}
};


int main() {
	srand(time(NULL)); cin.tie(0);
	ios::sync_with_stdio(false);

	LinkedList list;
	list.insertNode(5);
	list.insertNode(6);
	list.insertNode(8);
	list.insertNode(11);
	list.insertNode(17);
	list.insertNode(23);
	list.insertNode(37);
	list.printList();
	list.is_cyclic();
	

}

