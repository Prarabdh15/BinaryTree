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
 //global variable
//Take TC: O(N) insted of O(N^2)

int diameter(Node* root, int& maxi){
	if(root==NULL)
		return 0;

	int lh = diameter(root->left,maxi);
	int rh = diameter(root->right,maxi);

	maxi = max(maxi,lh+rh);

	return 1+max(lh,rh);
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
	
	
	int maxi = 0;
    int blah = diameter(root,maxi);
    cout << "Diameter->" << maxi;
	

}