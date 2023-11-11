#include "BSTtree.h"

BSTtree::BSTtree()
{
	root = NULL;
}

node* BSTtree::Insert(node* root, int value)
{
	if (root == NULL) {
		node* newnode = new node;
		newnode->data = value;
		newnode->left = NULL;
		newnode->right = NULL;
		root = newnode;
	}
	else if (value < root->data) {
		root->left = Insert(root->left, value);
	}
	else {
		root->right = Insert(root->right, value);
	}
	return root;
}

void BSTtree::Insert(int value)
{
	root = Insert(root, value);
}

void BSTtree::Display(node* root)
{
	if (root == NULL) {
		return;
	}
	Display(root->left);
	Display(root->right);
	cout << root->data << " ";
}

void BSTtree::Display()
{
	cout << "use the another disblay" << endl;
}

node* BSTtree::Search(node* root, int value)
{
	if (root == NULL) {
		return NULL;
	}
	else if (root->data == value) {
		return root;
	}
	else if (root->data > value) {
		Search(root->left, value);
	}
	else Search(root->right, value);
}

void BSTtree::Search(int value)
{
	node* found = new node;
	found = Search(root, value);
	if (found == NULL)cout << "NOT FOUND" << endl;
	else cout << "FOUND" << endl;
}

node* BSTtree::Findmax(node* root)
{
	if (root->right == NULL) {
		return root;
	}Findmax(root->right);
}

void BSTtree::Findmax()
{
	node* maxi = new node;
	maxi = Findmax(root);
	cout << maxi->data << endl;
}

node* BSTtree::Findmin(node* root)
{
	if (root->left == NULL) {
		return root;
	}Findmin(root->left);
}

void BSTtree::Findmin()
{
	node* mini = new node;
	mini =Findmin(root);
	cout << mini->data << endl;
}

node* BSTtree::Delete(node* root, int value)
{

	if (root == NULL)return NULL;
	else if (value > root->data) {
		root->right = Delete(root->right, value);
	}
	else if (value < root->data) {
		root->left = Delete(root->left, value);
	}
	else {
		if (root->left == NULL and root->right == NULL) {
			root = NULL;
		}
		else if (root->left == NULL and root->right != NULL) {
			root->data = root->right->data;
			delete root->right;
			root->right = NULL;
		}
		else if (root->left != NULL and root->right == NULL) {
			root->data = root->left->data;
			delete root->left;
			root->left = NULL;
		}
		else {
			node* maxi = new node;
			maxi = Findmax(root->left);
			root->data = maxi->data;
			root->left = Delete(root->left, maxi->data);
		}
	}return root;
}

void BSTtree::Delete(int value)
{
	node* del = new node;
	del = Delete(root, value);
	root = del;
}





