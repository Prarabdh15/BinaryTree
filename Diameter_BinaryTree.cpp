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

int height(Node* root){
	if(root==NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh)+1;
}

int maxi=0;//Global variable

int diameter(Node* root){
	if(root==NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	maxi = max(maxi,lh+rh);

	diameter(root->left);
	diameter(root->right);
	return maxi;
    
}







int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	root->left->left->left = new Node(5);
	root->right = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(9);
	root->right->right->left->left = new Node(10);

    cout << "Diameter->" <<diameter(root);
	
	
	


}