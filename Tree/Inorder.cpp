#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

void inorder(struct Node *root)
{
	if(root==NULL)
		return;
	else
		inorder(root->left);
		cout << " "<< root->data;
		inorder(root->right);
}


int main()
{
	struct Node *root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	
	root -> left -> left = new Node(4);
	root -> left -> right = new Node(5);
	root -> left -> right -> left = new Node(8);
	
	root -> right -> left = new Node(6);
	root -> right -> right = new Node(7);
	
	root -> right -> right -> left  = new Node(9);
	root -> right -> right -> right = new Node(10);
	
	inorder(root);
	return 0;
}