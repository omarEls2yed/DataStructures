#pragma once
#include<iostream>
#include <assert.h>
#include "IdataStructure.h"
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
	int hight;
};
class AvlTree:IdataStructure {
public:
	node* root = new node;
	AvlTree();
	node* Maxnode(node* root);
	node* Minnode(node* root);
	int Balance(node* root);
	int Height(node* root);
	node* Leftrotate(node* x);
	node* Rightrotate(node* x);
	node* Insert(node* root, int value);
	void Insert(int value);
	node* Delete(node* root, int value);
	void Delete(int value);
	node* Search(node* root, int value);
	void Search(int value);
	void Disblay(node* root);
	void Display();
};
