#include "LinkedQueue.h"
LinkedQueue::LinkedQueue(){
	front = back = NULL;
}
bool LinkedQueue::is_empty()
{
	if (front == NULL and back == NULL) {
		return true;
	}
	else return false;
}

void LinkedQueue::Insert(int value)
{
	node* newnode = new node;
	newnode->data = value;
	if (is_empty()) {
		front = newnode;
		back = newnode;
		newnode->next = NULL;
	}
	else {
		back->next = newnode;
		back = newnode;
		newnode->next = NULL;
	}
}

void LinkedQueue::Display()
{
	node* temp = new node;
	temp = front;
	vector<int>v;
	while (temp != NULL) {
		v.push_back(temp->data);
		temp = temp->next;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int LinkedQueue::number_of_element()
{
	int counter = 0;
	node* temp = new node;
	temp = front;
	while (temp != NULL) {
		counter++;
		temp = temp->next;
	}return counter;
}

void LinkedQueue::dequeue()
{

	if (is_empty()) {
		cout << "queue is empty" << endl;
	}
	else if (number_of_element() == 1) {
		delete front;
		front = back = NULL;
		//empty
	}
	else {
		node* temp = new node;
		temp = front;
		front = front->next;
		delete temp;
	}
}

void LinkedQueue::GetFront()
{
	cout << front->data << endl;
}

void LinkedQueue::GetBack()
{
	cout << back->data << endl;
}

bool LinkedQueue::is_found(int value)
{
	node* temp = new node;
	temp = front;
	while (temp != NULL) {
		if (temp->data == value) {
			return true;
		}temp = temp->next;
	}return false;
}

void LinkedQueue::clear()
{
	while (!is_empty()) {
		dequeue();
	}
}



