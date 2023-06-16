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

//To check if a tree's are identical or not.
//Traverse a tree in any order and check wether the
//its is same for both or not.
//If same the trees are identical else not.

void preorder(Node* root,vector<int>& v){
	if(root==NULL){
		return;
	}
	v.push_back(root->data);
	preorder(root->left);
	preorder(root->right);
}

bool Identical_or_Not(vector<int> a,vector<int> b){
	if(a.size()!=b.size()) return false;

	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
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
	
	
	
	

}