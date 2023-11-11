#pragma once
#include<iostream>
#include <assert.h>
#include <vector>
#include "IdataStructure.h"
using namespace std;
class Heap :IdataStructure {
	//complete tree u fill lift at first
	//parent is maximum than child
	int maxsize;
	int currentsize;
	int* arr;
public:
	Heap(int value);
	void Rotate(int idx);
	int Parentidx(int idx);
	int Liftidx(int idx);
	int Rightidx(int idx);
	void Removemax();
	void Increaseidx(int idx, int value);
	int Getmax();
	int CurSize();
	void Deleteidx(int idx);
	void Insert(int value);
	void Display();
};