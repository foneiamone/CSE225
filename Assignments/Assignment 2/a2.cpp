/* Using the Stack class given below write a program that can convert an infix arithmetic expression to postfix form.

- Convert the Stack class to a template class.
- User will input the infix expression as a string.
- You can assume that all the operands will be single digit.
- Follow the algorithm from the lecture slide.
- Do not include any library other than <iostream>.
- Do not use any other class than Stack.cpp. */

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

// Functions
int priority(char opr)
{
  if (opr == '^')
  {
    return 3;
  }

  else if (opr == '*' || opr == '/')
  {
    return 2;
  }

  else if (opr == '+' || opr == '-')
  {
    return 1;
  }

  return 0;
}

string infixToPostfix(string a)
{
  Stack<char> b;
  string c;

  for (int i = 0; i < a.length(); i++)
  {
    if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9'))
    {
      c += a[i];
    }

    else if (a[i] == '(')
    {
      b.push('(');
    }

    else if (a[i] == ')')
    {
      while (b.top() != '(')
      {
        char d = b.top();
        c += d;
        b.pop();
      }

      if (b.top() == '(')
      {
        char d = b.top();
        b.pop();
      }
    }

    else
    {
      while (b.isEmpty() == false && priority(a[i]) <= priority(b.top()))
      {
        char d = b.top();
        c += d;
        b.pop();
      }
      b.push(a[i]);
    }
  }

  while (b.isEmpty() == false)
  {
    char d = b.top();
    c += d;
    b.pop();
  }

  return c;
}

// Main
int main()
{
  string input;

  cout << "Infix expression: ";
  cin >> input;

  cout << "Postfix expression: " << infixToPostfix(input);

  return 0;
}
