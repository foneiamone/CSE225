/* Write a function that checks if the tree contains any duplicate nodes. Return true if it does.
Otherwise return false.
Write a function that prints only the internal nodes.

1, 1, 2, 3, 5, 6, 7, 8, 
True
2, 7, */

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree
{
private:
    Node *root;

    void insertNode(Node *&tree, int data)
    {
        if (tree == NULL)
        {
            tree = new Node;
            tree->data = data;
            tree->left = NULL;
            tree->right = NULL;
        }
        else if (data < tree->data)
        {
            insertNode(tree->left, data);
        }
        else
        {
            insertNode(tree->right, data);
        }
    }

    void printInOrder(Node *tree)
    {
        if (tree == NULL)
        {
            return;
        }
        printInOrder(tree->left);
        cout << tree->data << ", ";
        printInOrder(tree->right);
    }

    int treeLength(Node *tree)
    {
        if (tree == NULL)
        {
            return 0;
        }
        return 1 + treeLength(tree->left) + treeLength(tree->right);
    }

    bool findNode(Node *tree, int data)
    {
        if (tree == NULL)
        {
            return false;
        }

        if (tree->data == data)
        {
            return true;
        }
        else if (data < tree->data)
        {
            return findNode(tree->left, data);
        }
        else
        {
            return findNode(tree->right, data);
        }
    }

    Node *retrieveNode(Node *tree, int data)
    {
        if (tree == NULL)
        {
            return NULL;
        }

        if (tree->data == data)
        {
            return tree;
        }
        else if (data < tree->data)
        {
            return retrieveNode(tree->left, data);
        }
        else
        {
            return retrieveNode(tree->right, data);
        }
    }

    void deleteNode(Node *&tree, int data)
    {
        if (tree == NULL)
        {
            return;
        }
        if (tree->data == data)
        {
            if (tree->left == NULL && tree->right == NULL)
            {
                delete tree;
                tree = NULL;
            }
            else if (tree->left != NULL)
            {
                int maxLeftNode = findMaxNode(tree->left);
                tree->data = maxLeftNode;
                deleteNode(tree->left, maxLeftNode);
            }
            else
            {
                int minRightNode = findMinNode(tree->right);
                tree->data = minRightNode;
                deleteNode(tree->right, minRightNode);
            }
        }
        else if (tree->data < data)
        {
            deleteNode(tree->right, data);
        }
        else
        {
            deleteNode(tree->left, data);
        }
    }

    int findMinNode(Node *tree)
    {
        if (tree == NULL)
        {
            return -1;
        }
        else if (tree->left == NULL)
        {
            return tree->data;
        }
        else
        {
            return findMinNode(tree->left);
        }
    }

    int findMaxNode(Node *tree)
    {
        if (tree == NULL)
        {
            return -1;
        }
        else if (tree->right == NULL)
        {
            return tree->data;
        }
        else
        {
            return findMaxNode(tree->right);
        }
    }

    void makeEmpty(Node *&tree)
    {
        if (tree == NULL)
        {
            return;
        }
        makeEmpty(tree->left);
        makeEmpty(tree->right);
        delete tree;
        tree = NULL;
    }

    int getHeight(Node *tree)
    {
        if (tree == NULL)
        {
            return 0;
        }
        int lsh = 1 + getHeight(tree->left);
        int rsh = 1 + getHeight(tree->right);

        if (lsh > rsh)
        {
            return lsh;
        }
        else
        {
            return rsh;
        }
    }

    int countNodes(Node *tree)
    {
        if (tree == NULL)
        {
            return 0;
        }
        return 1 + countNodes(tree->left) + countNodes(tree->right);
    }

    bool duplicateNode(Node *tree)
    {
        if (tree == NULL)
        {
            return false;
        }

        if (findNode(tree->left, tree->data) || findNode(tree->right, tree->data))
        {
            return true;
        }
        return duplicateNode(tree->left) || duplicateNode(tree->right);
    }

    void printInternalNode(Node *tree)
    {
        if (tree == NULL)
        {
            return;
        }
        printInternalNode(tree->left);

        if (tree->left != NULL && tree->right != NULL && tree != root)
        {
            cout << tree->data << ", ";
        }
        printInternalNode(tree->right);
    }

public:
    BinarySearchTree()
    {
        root = NULL;
    }

    void insertNode(int data)
    {
        insertNode(root, data);
    }

    void printInOrder()
    {
        printInOrder(root);
    }

    int treeLength()
    {
        return treeLength(root);
    }

    Node *retrieveNode(int data)
    {
        return retrieveNode(root, data);
    }

    bool findNode(int data)
    {
        return findNode(root, data);
    }

    void deleteNode(int data)
    {
        deleteNode(root, data);
    }

    int findMinNode()
    {
        return findMinNode(root);
    }

    int findMaxNode()
    {
        return findMaxNode(root);
    }

    bool isBalanced();

    void makeEmpty()
    {
        makeEmpty(root);
    }

    int getHeight()
    {
        return getHeight(root);
    }

    bool isEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int countNodes()
    {
        return countNodes(root);
    }

    bool duplicateNode()
    {
        return duplicateNode(root);
    }

    void printInternalNode()
    {
        printInternalNode(root);
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insertNode(5);
    bst.insertNode(2);
    bst.insertNode(7);
    bst.insertNode(1);
    bst.insertNode(8);
    bst.insertNode(3);
    bst.insertNode(6);
    bst.insertNode(1);

    bst.printInOrder();

    if (bst.duplicateNode())
    {
        cout << "\nTrue";
    }

    else
    {
        cout << "\nFalse";
    }

    cout << endl;

    bst.printInternalNode();
}
