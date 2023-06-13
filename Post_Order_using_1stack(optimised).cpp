#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;
	Node(int val){
		this->data= val;
		this->left = NULL;
		this->right = NULL;
	}
};

//Post Order traversal
//Using Iterative technique(OPTIMISED)
//Uing only 1 stack
void post_order(Node* root){
	stack<Node*> st;
	Node* curr = root;

	while(curr!=NULL || !st.empty()){
		if(curr!=NULL){
			st.push(curr);
			curr = curr->left;
		}
		else{
			Node* temp = st.top()->right;
			if(temp==NULL){
				temp=st.top();
				st.pop();
				cout << temp->data << " ";
				while(!st.empty()&& temp==st.top()->right){
					temp = st.top();
					st.pop();
					cout << temp->data << " ";
				}
			}
			else
				curr = temp;
		}
	}
}



int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);


	cout << "Post Order->";
	post_order(root);
	
	


}
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7