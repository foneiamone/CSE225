#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    // Deletes the first node from the list
    void deleteFirstNode()
    {
        if (head == NULL)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Deletes the last node from the list
    void deleteLastNode()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            deleteFirstNode();
        }
        else
        {
            Node *current = head;
            while (current->next->next != NULL)
            {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        }
    }

    // Adds a node at the front position of the list
    void addNodeAtFront(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = head;
        head = n;
    }

    // Adds a node at the end of the list
    void addNodeAtEnd(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = NULL;
        if (head == NULL)
        { // list is empty
            head = n;
        }
        else
        {
            Node *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = n;
        }
    }

    // Inserts a node at the specified position
    // The front node's position is 0
    void insertNode(int data, int position)
    {
        if (position == 0)
        {
            addNodeAtFront(data);
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }
            Node *n = new Node;
            n->data = data;
            n->next = current->next;
            current->next = n;
        }
    }

    // Inserts a node at the specified position
    // The front node's position is 0
    void deleteNode(int position)
    {
        if (position == 0)
        {
            deleteFirstNode();
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < position - 1; i++)
            {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    void printNodes()
    {
        Node *current = head;
        cout << "head -> ";
        while (current != NULL)
        {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << endl;
    }

    // Prints the last node of a linked list
    void printLastNode()
    {
        // complete this function
        Node *current = head;
        while (current != NULL)
        {
            current = current->next;
            if (current->next == NULL)
            {
                cout << "tail -> " << current->data << endl;
            }
        }
    }

    // Returns the length of the list
    int getLength()
    {
        // complete this function
        Node *current = head;
        int count;
        while (current != NULL)
        {
            current = current->next;
            count++;
        }
        return count;
    }
};

int main()
{
    // Complete the printLastNode() and getLength() functions
    // Create a linked list and test the functions you wrote
    LinkedList a;

    a.addNodeAtFront(1);
    a.addNodeAtFront(3);
    a.addNodeAtEnd(7);
    a.addNodeAtFront(4);
    
    a.printNodes();
    cout << "length -> " << a.getLength() << endl;
    a.printLastNode();
}
