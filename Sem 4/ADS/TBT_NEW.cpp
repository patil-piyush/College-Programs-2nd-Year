#include <iostream>
#include <stdlib.h>
#define MAX_VALUE 65536

using namespace std;

struct Node
{
    int data;
    Node *rchild;
    Node *lchild;
    bool lThread, rThread;
};

class ThreadedBT
{
private:
    Node *root;

public:
    ThreadedBT()
    {
        root = new Node;
        root->data = MAX_VALUE;
        root->lchild = root->rchild = root;
        root->lThread = root->rThread = true;
    }

    void makeEmpty()
    { // clear tree
        root = new Node;
        root->data = MAX_VALUE;
        root->lchild = root->rchild = root;
        root->lThread = root->rThread = true;
    }

    // insert function for TBT - it inserts the key at correct position
    void Insert(int key)
    {
        Node *p = root;
        for (;;)
        {
            if (p->data < key)
            {
                if (p->rThread)
                    break;
                p = p->rchild;
            }
            else if (p->data > key)
            {
                if (p->lThread)
                    break;
                p = p->lchild;
            }
            else
            {
                return;
            }
        }
        Node *temp = new Node;
        temp->data = key;
        temp->lchild = temp->rchild = temp;
        temp->lThread = temp->rThread = true;

        if (p->data > key)
        {
            temp->lchild = p->lchild;
            p->lchild = temp;
            temp->rchild = p;
            p->lThread = false;
        }
        else
        {
            temp->rchild = p->rchild;
            p->rchild = temp;
            temp->lchild = p;
            p->rThread = false;
        }
    }

    // Corrected in-order display for Threaded Binary Tree
    void displayTree()
    {
        Node *temp = root->lchild; // Start from the leftmost node

        if (temp == root)
        {
            cout << "Tree is empty.\n";
            return;
        }

        // Move to the leftmost node
        while (!temp->lThread)
            temp = temp->lchild;

        // Traverse the tree using threads
        while (temp != root)
        {
            cout << temp->data << " ";
            if (temp->rThread) // If it's a thread, follow it
                temp = temp->rchild;
            else
            { // Otherwise, move to the leftmost node of right subtree
                temp = temp->rchild;
                while (!temp->lThread)
                    temp = temp->lchild;
            }
        }
        cout << endl;
    }
};


int main()
{
    ThreadedBT tbt;
    cout << "ThreadedBinaryTree\n";
    char ch;
    int c, v;
    while (1)
    {
        cout << "1. Insert " << endl;
        cout << "2. Delete" << endl;

        cout << "3. Search" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> c;
        // perform switch operation
        switch (c)
        {
        case 1:
            cout << "Enter integer element to insert: ";
            cin >> v;
            tbt.Insert(v);
            break;
        case 2:
            // cout << "Enter integer element to delete: ";
            // cin >> v;
            // tbt.Delete(v);
            break;
        case 3:
            // cout << "Enter integer element to search: ";
            // cin >> v;
            // if (tbt.search(v) == true)
            //     cout << "Element " << v << " found in the tree" << endl;
            // else
            //     cout << "Element " << v << " not found in the tree" << endl;
            break;
        case 4:
            cout << "\nTree Cleared\n";
            tbt.makeEmpty();
            break;
        case 5:
            cout << "Display tree: \n ";
            tbt.displayTree();
            break;
        case 6:
            exit(1);
        default:
            cout << "\nInvalid type! \n";
        }
    }
    cout << "\n";
    return 0;
}