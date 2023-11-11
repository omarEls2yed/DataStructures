#pragma once
#include <iostream>
#include <assert.h>
#include <vector>
#include "IdataStructure.h"
using namespace std;
class node {
public:
	int data;
	node* next;
};
class LinkedList :IdataStructure {
public:
	node* head = new node;
	LinkedList();
	bool IsEmpty();
	void PushFront(int newdata);
	void Display();
	int NunberofElemnt();
	void PushAfter(int item, int newvalue);
	void Insert(int value);
	void Delete(int item);
	void ReveseList();
	int GetIndx(int ind);
};