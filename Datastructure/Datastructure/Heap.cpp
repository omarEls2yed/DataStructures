#include "Heap.h"
Heap::Heap(int value)
{
	maxsize = value;
	arr = new int[maxsize];
	currentsize = 0;
}
void Heap::Rotate(int idx)
{
	int liftidx = idx * 2 + 1;
	int rightidx = idx * 2 + 2;
	int maxi = idx;
	if (liftidx < currentsize and arr[maxi] < arr[liftidx]) {
		maxi = liftidx;
	}
	if (rightidx < currentsize and arr[maxi] < arr[rightidx]) {
		maxi = rightidx;
	}
	if (maxi != idx) {
		swap(arr[maxi], arr[idx]);
		Rotate(maxi);
	}
}

int Heap::Parentidx(int idx)
{
	return (idx - 1) / 2;
}

int Heap::Liftidx(int idx)
{
	return idx * 2 + 1;
}

int Heap::Rightidx(int idx)
{
	return idx * 2 + 2;
}

void Heap::Removemax()
{
	if (currentsize == 0) {
		cout << "already empty" << endl;
	}
	else if (currentsize == 1) {
		currentsize--;
	}
	else {
		arr[0] = arr[currentsize - 1];
		currentsize--;
		Rotate(0);
	}
}

void Heap::Increaseidx(int idx, int value)
{
	arr[idx] = value;
	while (idx != 0 and arr[Parentidx(idx)] < arr[idx]) {
		swap(arr[Parentidx(idx)], arr[idx]);
		idx = Parentidx(idx);
	}
}

int Heap::Getmax()
{
	return arr[0];
}

int Heap::CurSize()
{
	return currentsize;
}

void Heap::Deleteidx(int idx)
{
	int value = INT_MAX;
	Increaseidx(idx, value);
	Removemax();
}

void Heap::Insert(int value)
{

	if (currentsize == maxsize) {
		cout << "heap is full" << endl;
		return;
	}
	int idx = currentsize;
	arr[currentsize] = value;
	currentsize++;
	while (idx != 0 and arr[Parentidx(idx)] < arr[idx]) {
		swap(arr[Parentidx(idx)], arr[idx]);
		idx = Parentidx(idx);
	}
}

void Heap::Display()
{
	for (int i = 0; i < currentsize; i++) {
		cout << arr[i] << " ";
	}cout << endl;
}


