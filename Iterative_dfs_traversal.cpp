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

//Pre Order traversal
//Using Iterative technique
void pre_order(Node* root){
	//edge case
	if(root==NULL) 
		return;

	stack<Node*> st;
	st.push(root);
	while(!st.empty()){
		Node* temp = st.top();
		st.pop();

		//First Right Then Left
		if(temp->right!=NULL)
			st.push(temp->right);
		if(temp->left!=NULL)
			st.push(temp->left);

		cout << temp->data << " ";
	}

}

//In Order Traversal
//Iterative approch
void in_order(Node* root){
	stack<Node*> st;
	Node* node = root;

	while(true){
		if(node!=NULL){
			st.push(node);
			node = node->left;
		}
		else{
			if(st.empty()) break;
			node = st.top();
			st.pop();
			cout << node->data << " ";
			node = node->right;
		}
	}
}


//Post Order Traversal
//Iterative approch
void post_order(Node* root){
	stack<Node*> st1,st2;
	st1.push(root);

	while(!st1.empty()){
		root = st1.top();
		st1.pop();
		st2.push(root);
		if(root->left!=NULL) st1.push(root->left);
		if(root->right!=NULL) st1.push(root->right);
	}
    
    //Your stack 2(st2) contains post order sequence
	while(!st2.empty()){
		cout << st2.top()->data << " ";
		st2.pop();
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


    cout << "Pre Order->";
	pre_order(root);

	cout <<endl;

	cout << "In Order->";
	in_order(root);

	cout<<endl;

	cout << "Post Order->";
	post_order(root);
	
	


}
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7