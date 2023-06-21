#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 10e9+7;

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
bool isleaf(Node* root){
	if(!root->left && !root->right)
		return true;
	else
		return false;
}

void left_boundary(Node* root,vector<int>& ds){
	Node* curr = root->left;
	while(curr){
		if(!isleaf(curr)) ds.push_back(curr->data);

		if(curr->left) curr = curr->left;
		else curr = curr->right;
	}
}

void add_leaf(Node* root,vector<int>& ds){
	if(isleaf(root)){
		ds.push_back(root->data);
		return;
	}
	if(root->left) add_leaf(root->left,ds);
	if(root->right) add_leaf(root->right,ds);
}

void right_boundary(Node* root,vector<int>& ds){
	stack<int> st;
	Node* curr = root->right;
	while(curr){
		if(!isleaf(root)) st.push(curr->data);
		if(curr->right) curr = curr->right;
		else curr = curr->left;
	}
	while(!st.empty()){
		int data = st.top();
		ds.push_back(data);
		st.pop();
	}
}

//Main code where all the function are called.
vector<int> print_boundary(Node* root){
	vector<int> ds;
	if(!root) return ds;
	if(!isleaf(root)) ds.push_back(root->data);

	left_boundary(root,ds);
	add_leaf(root,ds);
	right_boundary(root,ds);
	return ds;

}

int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
    
    vector<int> ds = print_boundary(root);

    for(auto i:ds) cout << i << " ";
    
	
	
	


}