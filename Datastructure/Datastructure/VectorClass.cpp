#include "vectorClass.h"
VectorClass::VectorClass() {
    arr = new int[1];
    capacity = 1;
    current = 0;
}
VectorClass::~VectorClass() {
    delete[] arr;
}
void VectorClass::Insert(int data) {
    if (current == capacity) {
        int* temp = new int[2 * capacity];
        for (int i = 0; i < capacity; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        capacity *= 2;
        arr = temp;
    }
    arr[current] = data;
    current++;
}
int VectorClass::get(int index) {
    if (index < current) {
        return arr[index];
    }
}
void VectorClass::pop() {
    current--;
}
int VectorClass::size() {
    return current;
}
int VectorClass::getcapacity() {
    return capacity;
}
void VectorClass::Display() {
    for (int i = 0; i < current; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void VectorClass::reverse() {
    for (int i = 0; i < current; i++) {
        arr[i] = arr[current - i - 1];
    }
}
void VectorClass::update(int indx, int value) {
    if (indx < current) {
        for (int i = 0; i < current; i++) {
            if (i == indx) {
                arr[i] = value;
                break;
            }
        }
    }
}
