#include"DoubledLinkedList.h"
DoubleLinkedList::DoubleLinkedList(){
    head = NULL;
}
bool DoubleLinkedList::IsEmpty() {
    if (head == NULL) {
        return true;
    }
    else {
        return false;
    }
}

int DoubleLinkedList::NumberOfElemnt()
{
    int counter = 0;
    node* temp = new node;
    temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}
// push_front()
void DoubleLinkedList::Insert(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = head;
    head = newnode;
    newnode->prev = NULL;
}

// push_back()
void DoubleLinkedList::PushBack(int value) {
    node* newnode = new node;
    newnode->data = value;
    if (IsEmpty()) {
        newnode->prev = NULL;
        newnode->next = head;
        head = newnode;
    }
    else {
        node* temp = new node;
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = NULL;
        newnode->prev = temp;
    }
}

// print()
void DoubleLinkedList::Display() {
    if (IsEmpty()) {
        cout << "double linked list is empty" << endl;
    }
    else {
        node* temp = new node;
        temp = head;
        vector<int> v;
        while (temp != NULL) {
            v.push_back(temp->data);
            temp = temp->next;
        }
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
}

void DoubleLinkedList::DeletFront()
{
    if (NumberOfElemnt() > 1) {
        node* temp = new node;
        temp = head;
        head = temp->next;
        head->prev = NULL;
        delete temp;
    }
    else if (NumberOfElemnt() == 1) {
        node* temp = new node;
        temp = head;
        head = NULL;
        delete temp;
    }
    else {
        cout << "list is empty " << endl;
    }
}
void DoubleLinkedList::DeletLast()
{
    if (NumberOfElemnt() == 1) {
        node* temp = new node;
        temp = head;
        head = NULL;
        delete temp;
    }
    else {
        cout << "list is empty " << endl;
    }
}

void DoubleLinkedList::PushIndex(int index, int value) {
    if (NumberOfElemnt() <= 1 and index < 2) {
       Insert(value);
    }
    else if (index > NumberOfElemnt()) {
        PushBack(value);
    }
    else {
        node* newnode = new node;
        newnode->data = value;
        int counter = 1;
        node* temp = new node;
        temp = head;
        while (counter != index - 1) {
            temp = temp->next;
            counter++;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void DoubleLinkedList::Reverse()
{
    node* prev = new node;
    node* current = new node;
    node* next = new node;
    prev = NULL;
    current = head;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }
    head = prev;
}

int DoubleLinkedList::Get(int indx)
{
    int counter = 1;
    node* temp = new node;
    temp = head;
    while (indx != counter) {
        temp = temp->next;
        counter++;
    }
    return temp->data;
}

