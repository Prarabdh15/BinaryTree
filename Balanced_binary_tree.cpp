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
int max_depth(Node* root){
	if(root==NULL) return 0;
	queue<Node*> q;
	q.push(root);
  
  int cnt = 0;
	while(!q.empty()){
		Node* node = q.front();
		q.pop();
		if(node->left!=NULL) q.push(node->left);
		if(node->right!=NULL) q.push(node->right);

		if(node->left!=NULL || node->right!=NULL)
			cnt++;


	}
	return cnt;
}


//Balanced binary tree
// if for every Node: 
// height(left)-height(right)<=1

bool check(Node* root){
	if(root==NULL) return true;

	int lh = max_depth(root->left);
	int rh = max_depth(root->right);


	if(abs(lh-rh)>1) return false;

	bool x = check(root->left);
	bool y = check(root->right);

	if(!x || !y)
		return false;

	return true;
}



int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	//root->right->right->left = new Node(9);


	cout << "Is it a balanced binary tree->";
	cout << check(root);
	
	


}
  //     1
  //    / \
  //   2   3
  //  / \ / \
  // 4  5 6  7
//          /
//         9