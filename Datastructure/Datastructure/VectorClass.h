#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
#include "IdataStructure.h"
using namespace std;
class VectorClass :IdataStructure {
    int* arr;
    int capacity;
    int current;
public:
    VectorClass();
    ~VectorClass();
    void Insert(int data);
    int get(int index);
    void pop();
    int size();
    int getcapacity();
    void Display();
    void reverse();
    void update(int indx,int value);
};
