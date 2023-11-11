#include "LinkedStack.h"

LinkedStack::LinkedStack() {
    top = NULL;
}

bool LinkedStack::IsEmpty() {
    return top == NULL;
}

bool LinkedStack::IsFull()
{
    return false;
}

void LinkedStack::Insert(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int LinkedStack::pop() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else {
        node* temp = top;
        top = top->next;
        int value = temp->data;
        delete temp;
        return value;
    }
}

void LinkedStack::Display()
{
    node* temp = new node;
    temp = top; vector<int>v;
    while (temp != NULL) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }cout << endl;
}
int LinkedStack::Peek() {
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        return -1;
    }
    else {
        return top->data;
    }
}
int LinkedStack::NumberOfElement() {
    node* temp = new node;
    temp = top; int count = 0;
    while (temp != 0) {
        count++;
        temp = temp->next;
    }return count;
}
bool LinkedStack::IsFound(int value) {
    node* temp = top;
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}