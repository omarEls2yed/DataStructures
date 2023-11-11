#pragma once
#include <iostream>
#include <assert.h>
#include "IdataStructure.h"
using namespace std;
class Stack :IdataStructure
{
    int top;
    int MxSize;
    int* arr;
public:
    Stack(int Size);
    bool IsEmpty();
    bool IsFull();
    void Insert(int item);
    void Delete();
    int GetTop();
    int Size();
    void Display();
    void clear();
};
