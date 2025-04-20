#include <iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
} *root = nullptr;


// INSERTION
struct Node *Rinsert(struct Node *t, int key)
{
    Node *p;
    if (t == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        return p;
    }
    if (key < t->data)
        t->lchild = Rinsert(t->lchild, key);
    else if (key > t->data)
        t->rchild = Rinsert(t->rchild, key);
    else if (key == t->data)
        return nullptr;
    return t;
}


// GENERATING N RANDOM NUMBER IN THE RANGE 1 TO 100
void Generate_and_Insert(int n)
{
    int num;
    for (int i = 0; i <= n; i++)
    {
        // srand(time(0));
        num = rand() % 100 + 1;
        if (i == 0)
        {
            root = Rinsert(root, num);
            cout << num << "Inserted successfully.\n";
        }
        else
        {
            Rinsert(root, num);
            cout << num << "Inserted successfully.\n";
        }
    }
}


// PREORDER TRAVERSAL
void postorder(struct Node *t)
{
    if (t != nullptr)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        cout << "\nData: " << t->data << endl;
    }

}


//SUMUP FUNCTION
int SumUp(Node* t){
    if (t == nullptr)
    {
        return 0;
    }
    if(t->lchild == nullptr && t->rchild == nullptr)
        return t->data;
    if (t->lchild)
        t->data += SumUp(t->lchild);
    else if (t->rchild)
        t->data += SumUp(t->rchild);
    return t->data;
}

int main()
{
    int choice, n;

    while (1)
    {
        cout << "\n==== Dictionary Menu ====\n";
        cout << "1. Insert n number of random data\n";
        cout << "2. Display using postorder\n";
        cout << "3. use sumall function\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of keys you want to insert: ";
            cin >> n;
            Generate_and_Insert(n);
            break;
        case 2:
            cout << "Tree: ";
            postorder(root);
            break;
        case 3:
            cout << "Tree: ";
            SumUp(root);
            postorder(root);
            break;
        case 0:
            cout << "Exiting...\n";
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
