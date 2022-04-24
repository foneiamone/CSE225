/* Complete the classes given below. Avoid making memory leaks. Do not write any other function. 
Do not import any other library. */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *first;
    Node *last;

public:
    Queue()
    {
        first = NULL;
        last = NULL;
    }

    void enqueue(int data)
    {
        Node *q = new Node;
        q->data = data;
        q->next = NULL;

        if (first == NULL)
        {
            first = q;
            last = q;
        }

        else
        {
            last->next = q;
            last = q;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
        }

        else if (first == last)
        {
            free(first);
            first = last = NULL;
        }

        else
        {
            Node *q = first;
            first = first->next;
            free(q);
        }
    }

    // returns the first item (int) without removing it
    int firstItem()
    {
        Node *q;
        q = first;
        return q->data;
    }

    bool isEmpty()
    {
        if (first == NULL && last == NULL)
        {
            return true;
        }

        return false;
    }

    void makeEmpty()
    {
        while (first != NULL)
        {
            Node *q = first;
            first = first->next;
            free(q);
        }
        last == NULL;
    }
};

int main()
{
    // Complete the functions above
    // Call each function here in the main()
    // to test if they are working correctly

    Queue a;
    for (int i = 0; i < 10; ++i)
    {
        a.enqueue(i);
    }

    for (int i = 0; i < 10; ++i)
    {
        cout << a.firstItem() << " ";
        a.dequeue();
    }
    cout << endl;

    a.makeEmpty();

    a.dequeue();

    if (a.isEmpty())
    {
        cout << "Empty Queue" << endl;
    }
}
