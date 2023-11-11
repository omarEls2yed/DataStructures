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
    node* prev;
};
class DoubleLinkedList :IdataStructure {
public:
    node* head = new node;
    DoubleLinkedList();
    bool IsEmpty();
    int NumberOfElemnt();
    void Insert(int value);
    void PushBack(int value);
    void Display();
    void DeletFront();
    void DeletLast();
    void PushIndex(int index, int value);
    void Reverse();
    int Get(int indx);
};