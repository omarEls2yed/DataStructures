#include "CircularQueue.h"
using namespace std;
Queue::Queue(int sizee) {
    size = sizee;
    array = new t[sizee];
    this->front = 0;
    this->rear = 0;
}
Queue::~Queue() {
    delete[] this->array;
}
bool Queue::isEmpty() {
    return this->front == this->rear;
}

bool CircularQueue::isFull() {
    return (this->rear + 1) % this->size == this->front;
}

void CircularQueue::enqueue(int element) {
    if (this->isFull()) {
        cout << "Queue is full!" << endl;
    }
    else {
        this->array[this->rear] = element;
        this->rear = (this->rear + 1) % this->size;
    }
}

int CircularQueue::dequeue() {
    if (this->isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else {
        int element = this->array[this->front];
        this->front = (this->front + 1) % this->size;
        return element;
    }
}

int CircularQueue::front() {
    if (this->isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else {
        return this->array[this->front];
    }
}

int CircularQueue::rear() {
    if (this->isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else {
        return this->array[this->rear - 1];
    }
}

void CircularQueue::display() {
    if (this->isEmpty()) {
        cout << "Queue is empty!" << endl;
    }
    else {
        for (int i = this->front; i < this->rear; i++) {
            cout << this->array[i] << " ";
        }
        cout << endl;
    }
}

