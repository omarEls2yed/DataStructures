#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include "IdataStructure.h"
using namespace std;
class node {
public:
	int data;
	node* next;
};
class LinkedStack :IdataStructure
{
public:
	node* top = new node;
	LinkedStack();
	bool IsEmpty();
	bool IsFull();
	void Insert(int value);
	int pop();
	void Display();
	int NumberOfElement();
	int Peek();
	bool IsFound(int value);
};
