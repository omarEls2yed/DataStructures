#pragma once
#include<iostream>
#include <assert.h>
#include <vector>
#include "IdataStructure.h"
using namespace std;
class node {
public:
	int data;
	node* next;
};
class LinkedQueue: IdataStructure {
public:
	node* front = new node;
	node* back = new node;
	LinkedQueue();
	bool is_empty();
	void Insert(int value);
	void Display();
	int number_of_element();
	void dequeue();
	void GetFront();
	void GetBack();
	bool is_found(int value);
	void clear();
};
