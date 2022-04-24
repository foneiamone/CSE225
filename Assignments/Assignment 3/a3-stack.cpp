/* Complete the classes given below. Avoid making memory leaks. Do not write any other function. 
Do not import any other library. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *s = new Node;
        s->data = data;
        s->next = top;
        top = s;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
        }

        else
        {
            Node *s = top;
            top = top->next;
            delete (s);
        }
    }

    int getTop()
    {
        return top->data;
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }

        return false;
    }

    void makeEmpty()
    {
        while (top != NULL)
        {
            Node *s = top;
            top = top->next;
            delete (s);
        }
    }
};

int main()
{
    // Complete the functions above
    // Call each function here in the main()
    // to test if they are working correctly

    Stack a;
    for (int i = 0; i < 10; ++i)
    {
        a.push(i);
    }

    Stack b;
    for (int i = 0; i < 10; ++i)
    {
        b.push(a.getTop());
        a.pop();
    }

    for (int i = 0; i < 10; ++i)
    {
        cout << b.getTop() << " ";
        b.pop();
    }

    cout << endl;

    a.push(1011);

    cout << a.getTop() << endl;

    a.makeEmpty();

    if (a.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    a.pop();
}
