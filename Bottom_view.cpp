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
vector<int> bottom_view(Node* root){
	vector<int> ans;
	if(root==NULL) return ans;
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		Node* node = it.first;
		int line = it.second;
        mp[line] == node->data;
		
		if(node->left!=NULL){
			q.push({node->left,line-1});
		}
		if(node->right!=NULL){
			q.push({node->right,line+1});
		}  
	}
	for(auto i:mp){
		ans.push_back(i.second);
	}
	return ans;
}
int main() {
	Node* root = new Node (1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	
    cout << "Bottom View of Binary tree:";
    vector<int> ds = bottom_view(root);
    
    for(auto i:ds) cout << i << " ";
    
	
	
	


}