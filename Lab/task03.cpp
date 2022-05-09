/* Task 1: Convert the stack class to a template class
Task 2: Take a string from the user and print the reverse string using a stack
Example:
input: nsu
output: usn */

#include <iostream>
using namespace std;

// Exception class thrown by push() when stack is full.
class FullStack
{
};

// Exception class thrown by pop() and Top when stack is empty.
class EmptyStack
{
};

// Class
template <class T>
class Stack
{
private:
    int stackSize;
    int topIndex;
    T *items;

public:
    Stack();
    Stack(int);
    ~Stack();
    void makeEmpty();
    bool isFull();
    bool isEmpty();
    void push(int);
    void pop();
    int top();
};

// Definitions
template <class T>
Stack<T>::Stack()
{
    stackSize = 5;
    items = new T[stackSize];
    topIndex = -1;
}

template <class T>
Stack<T>::~Stack()
{
    delete[] items;
}

template <class T>
Stack<T>::Stack(int stackSize)
{
    this->stackSize = stackSize;
    items = new T[stackSize];
    topIndex = -1;
}

template <class T>
void Stack<T>::makeEmpty()
{
    topIndex = -1;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return (topIndex == -1);
}

template <class T>
bool Stack<T>::isFull()
{
    return (topIndex == stackSize - 1);
}

template <class T>
void Stack<T>::push(int newItem)
{
    if (isFull())
        throw FullStack();
    topIndex++;
    items[topIndex] = newItem;
}

template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
        throw EmptyStack();
    topIndex--;
}

template <class T>
int Stack<T>::top()
{
    if (isEmpty())
        throw EmptyStack();
    return items[topIndex];
}

// main
int main()
{
    Stack<char> s(3);

    while (!s.isFull())
    {
        char a;
        cin >> a;
        s.push(a);
    }

    while (!s.isEmpty())
    {
        cout << (char)s.top();
        s.pop();
    }
}