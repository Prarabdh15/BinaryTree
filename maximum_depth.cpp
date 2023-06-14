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

//Maximum Depth of a binary tree
//Recursive approach
//Logic: 1+max(l,r)

int max_depth(Node* root){
	if(root==NULL) return 0;

	int lh = max_depth(root->left);
	int rh = max_depth(root->right);

	return 1 + max(lh,rh);
}
// TC: O(height of binary tree)




int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->right->right->left = new Node(9);


	cout << "maxmimum Depth->";
	cout << max_depth(root);
	
	


}
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7
//          /
//         9