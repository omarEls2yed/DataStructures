#include "LinkedList.h"
LinkedList::LinkedList() {
    head = NULL;
}

bool LinkedList::IsEmpty() {
    return head == NULL;
}


void LinkedList::PushFront(int newdata) {
    node* newnode = new node;
    newnode->data = newdata;
    newnode->next = head;
    head = newnode;
}


void LinkedList::PushAfter(int item, int newvalue) {
    node* temp = head;
    while (temp != NULL && temp->data != item) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item not found in the list" << endl;
    }
    else {
       
        node* newnode = new node;
        newnode->data = newvalue;
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void LinkedList::Insert(int value) {
    if (IsEmpty()) {
        PushFront(value);
    }
    else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        node* newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        temp->next = newnode;
    }
}

void LinkedList::Display() {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void LinkedList::Delete(int item) {
    if (IsEmpty()) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->data == item) {
        node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    node* dellptr = head;
    node* prev = NULL;
    while (dellptr->data != item) {
        prev = dellptr;
        dellptr = dellptr->next;
    }
    if (dellptr == NULL) {
        cout << "Item not found in the list" << endl;
        return;
    }
    prev->next = dellptr->next;
    delete dellptr;
}


void LinkedList::ReveseList() {
    node* prev = NULL;
    node* next = NULL;
    node* current = head;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

int LinkedList::GetIndx(int ind) {
    if (ind < 0 || ind >= NunberofElemnt()) {
        cout << "Index out of range" << endl;
        return -1;
    }
    int counter = 1;
    node* temp = head;
    while (counter != ind) {
        counter++;
        temp = temp->next;
    }
    return temp->data;
}
int LinkedList::NunberofElemnt() {
    int counter = 0;
    node* temp = head;
    while (temp != NULL) {
        counter++;
        temp = temp->next;
    }
    return counter;
}

