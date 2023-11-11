#include "AvlTree.h"
node* AvlTree::Insert(node* root, int value) {
    if (root == NULL) {
        node* newnode = new node;
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        newnode->hight = 1;
        root = newnode;
    }

    if (value < root->data) {
        root->left = Insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = Insert(root->right, value);
    }
    else {
        return root;
    }

    // Update ancestors
    root->hight = 1 + max(Height(root->left), Height(root->right));
    int bal = Balance(root);

    // LL
    if (bal > 1 && value < root->left->data) {
        return Rightrotate(root);
    }

    // RR
    if (bal < -1 && value > root->right->data) {
        return Leftrotate(root);
    }

    // LR
    if (bal > 1 && value > root->left->data) {
        root->left = Leftrotate(root->left);
        return Rightrotate(root);
    }

    // RL
    if (bal < -1 && value < root->right->data) {
        root->right = Rightrotate(root->right);
        return Leftrotate(root);
    }

    return root;
}

void AvlTree::Insert(int value) {
    root = Insert(root, value);
}

node* AvlTree::Delete(node* root, int value) {
    if (root == NULL) {
        return;
    }

    if (value < root->data) {
        Delete(root->left, value);
    }
    else if (value > root->data) {
        Delete(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            // No child
            root = NULL;
        }
        else if (root->left == NULL && root->right != NULL) {
            // One child
            root->data = root->right->data;
            delete root->right;
            root->right = NULL;
        }
        else if (root->left != NULL && root->right == NULL) {
            // One child
            root->data = root->left->data;
            delete root->left;
            root->left = NULL;
        }
        else {
            // Two children
            node* temp = Minnode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }

    if (root == NULL) {
        return;
    }

    root->hight = 1 + max(Height(root->left), Height(root->right));
    int bal = Balance(root);

    // LL
    if (bal > 1 && Balance(root->left) >= 0) {
        Rightrotate(root);
    }

    // RR
    if (bal < -1 && Balance(root->right) <= 0) {
        Leftrotate(root);
    }

    // LR
    if (bal > 1 && Balance(root->left) < 0) {
        root->left = Leftrotate(root->left);
        Rightrotate(root);
    }

    // RL
    if (bal < -1 && Balance(root->right) > 0) {
        root->right = Rightrotate(root->right);
        Leftrotate(root);
    }
}

void AvlTree::Delete(int value) {
    node* newnode = new node;
    newnode = Delete(root, value);
    root = newnode;
}

node* AvlTree::Search(node* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == value) {
        return root;
    }
    else if (value > root->data) {
        root->right = Search(root->right, value);
    }
    else {
        root->left = Search(root->left, value);
    }
}

void AvlTree::Search(int value)
{
    node* newnode = new node;
    newnode = Search(root, value);
    if (newnode != NULL) {
        cout << "FOUND" << endl;
    }
    else {
        cout << "NOT FOUND" << endl;
    }
}

void AvlTree::Disblay(node* root)
{
    if (root == NULL) {
        return;
    }
    Disblay(root->left);
    Disblay(root->right);
    cout << root->data << " ";
}

void AvlTree::Display()
{
    cout << "Use another display" << endl;
}

AvlTree::AvlTree()
{
    root = NULL;
}

node* AvlTree::Maxnode(node* root)
{
    node* current = new node;
    current = root;
    while (current->right != NULL)
        current = current->right;
    return current;
}

node* AvlTree::Minnode(node* root)
{
    node* current = new node;
    current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

int AvlTree::Balance(node* root)
{
    if (root == NULL) {
        return 0;
    }
    return (Height(root->left)) - (Height(root->right));
}

int AvlTree::Height(node* root)
{
    if (root == NULL)
        return 0;
    return root->hight;
}

node* AvlTree::Leftrotate(node* x)
{
    node* y = new node;
    node* t = new node;
    y = x->right;
    t = y->left;
    y->left = x;
    x->right = t;
    x->hight = 1 + max((Height(x->right)), Height(x->left));
    y->hight = 1 + max(Height(y->left), Height(y->right));
    return y;
}

node* AvlTree::Rightrotate(node* x)
{
    node* y = new node;
    node* t = new node;
    y = x->left;
    t = y->right;
    y->right = x;
    x->left = t;
    x->hight = 1 + max((Height(x->right)), Height(x->left));
    y->hight = 1 + max(Height(y->left), Height(y->right));
    return y;
}