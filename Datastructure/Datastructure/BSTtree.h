#pragma once
#include<iostream>
#include <assert.h>
#include <vector>
#include "IdataStructure.h"
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;
};
class BSTtree:IdataStructure {
public:
	node* root = new node;
	BSTtree();
	node* Insert(node* root, int value);
	void Insert(int value);
	void Display(node* root);
	void Display();
	node* Search(node* root, int value);
	void Search(int value);
	node* Findmax(node* root);
	void Findmax();
	node* Findmin(node* root);
	void Findmin();
	node* Delete(node* root, int value);
	void Delete(int value);
};