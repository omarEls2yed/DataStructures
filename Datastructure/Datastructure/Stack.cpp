#include "Stack.h"

Stack::Stack(int Size)
{
    top = -1;
    MxSize = Size;
    arr = new int[MxSize];
}

bool Stack::IsEmpty()
{
    return top == -1;
}

bool Stack::IsFull()
{
    return top == MxSize - 1;
}

void Stack::Insert(int item)
{
    if (IsFull())
        cout << "Stack is overflow" << endl;
    else {
        top++;
        arr[top] = item;
    }
}

void Stack::Delete()
{
    if (IsEmpty())
        cout << "Stack is underflow" << endl;
    else
        top--;
}

int Stack::GetTop()
{
    if (IsEmpty())
        return INT_MIN;
    else
        return arr[top];
}

int Stack::Size()
{
    return top + 1;
}

void Stack::Display()
{
    for (int i = top; i >= 0; i--)
        cout << arr[i] << ' ';
    cout << endl;
}

void Stack::clear()
{
    top = -1;
    delete[] arr;
}