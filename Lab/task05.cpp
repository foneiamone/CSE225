/*

head -> 2 -> 3 ->
head -> 2 -> 3 -> 4 -> 5 ->
head -> 2 -> 3 -> 4 ->
head -> 3 -> 4 ->

*/

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

    void addNodeAtFront(int data)
    {
        Node *n = new Node;
        n->data = data;
        n->next = head;
        head = n;
    }

    void appendNode(int data)
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
};

int main()
{
    // Create a LinkedList
    // Add two nodes at the beginning of the list
    // Print the list
    // Add two nodes at the end of the list
    // Print the list
    // Delete the last node
    // Print the list
    // Delete the first node
    // Print the list

    LinkedList a;

    a.addNodeAtFront(3);
    a.addNodeAtFront(2);
    a.printNodes();

    a.appendNode(4);
    a.appendNode(5);
    a.printNodes();

    a.deleteLastNode();
    a.printNodes();

    a.deleteFirstNode();
    a.printNodes();
}
