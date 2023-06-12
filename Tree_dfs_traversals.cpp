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

//PreOrder Traversal
void pre_order(Node* root){
	if(root==NULL){
		return;
	}

	cout << root->data<<" ";
	pre_order(root->left);
	pre_order(root->right);
}
//InOrder Traversal
void in_order(Node* root){
	if(root==NULL){
		return;
	}

	pre_order(root->left);
	cout << root->data<<" ";
	pre_order(root->right);
}

//PostOrder Traversal
void post_order(Node* root){
	if(root==NULL){
		return;
	}

	pre_order(root->left);
	pre_order(root->right);
	cout << root->data<<" ";
}



int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(4);
    cout << "Preorder->";
	pre_order(root);
	cout <<endl;
	cout << "Inorder->";
    in_order(root);
    cout <<endl;
    cout << "Postorder->";
    post_order(root);


}
