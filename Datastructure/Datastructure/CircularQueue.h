#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "IdataStructure.h"
#include <iostream>
using namespace std;
class Queue :IdataStructure {
	int rear;
	int front;
	int length;
	int* arr;
	int maxSize;
public:
	Queue(int size);
	int isEmpty();
	bool isFull();
	void Insert(int Element);
	void deleteQueue();
	int frontQueue();
	int rearQueue();
	void Display();
	int queueSearch(int element);
	~Queue();
};
