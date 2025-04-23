/*
Consider the Dictionary Implementations which allow for efficient storage and retrieval of
key-value pairs using binary search trees. Each node in the tree store (key, value) pair. The
dictionary should support the following operations efficiently:
1. Insert word (Handle insertion of duplicate entry)
2. Delete word
3. Search specific word
4. Display dictionary (Traversal)
5. Mirror image of dictionary
6. Create a copy of dictionary
7. Display dictionary level wise
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
public:
    Node *left;
    string key, value;
    Node *right;
} *root = NULL;

queue<Node *> q;

struct Node *Insert(Node *t, string k, string v)
{
    Node *p;
    if (t == NULL)
    {
        p = new Node;
        p->key = k;
        p->value = v;
        p->left = p->right = NULL;
        if (root == t)
        {
            root = p;
            return root;
        }
        t = p;
        return t;
    }
    else if (k < t->key)
        t->left = Insert(t->left, k, v);
    else if (k > t->key)
        t->right = Insert(t->right, k, v);

    return t;
}

int height(Node *t)
{
    if (t == NULL)
        return 0;
    int x = height(t->left);
    int y = height(t->right);

    return x > y ? x + 1 : y + 1;
}

Node *succ(Node *t)
{
    while (t && t->left)
    {
        t = t->left;
    }
    return t;
}

Node *pred(Node *t)
{
    while (t && t->right)
    {
        t = t->right;
    }
    return t;
}

struct Node *Rdelete(Node *t, string k)
{
    if (t == NULL)
        return NULL;
    if (k < t->key)
        t->left = Rdelete(t->left, k);
    else if (k > t->key)
        t->right = Rdelete(t->right, k);
    else
    {
        if (t->left == NULL && t->right == NULL)
        {
            delete t;
            return NULL;
        }
        else
        {
            Node *p;
            if (height(t->left) > height(t->right))
            {
                p = pred(t->left);
                t->key = p->key;
                t->value = p->value;
                t->left = Rdelete(t->left, p->key);
            }
            else
            {
                p = succ(t->right);
                t->key = p->key;
                t->value = p->value;
                t->right = Rdelete(t->right, p->key);
            }
        }
    }
    return t;
}

void inorder(Node *t)
{
    if (t != nullptr)
    {
        inorder(t->left);
        cout << "key: " << t->key << "\tValue: " << t->value << endl;
        inorder(t->right);
    }
}

Node *search(Node *t, string k)
{
    if (t == NULL)
        return NULL;
    if (k < t->key)
        search(t->left, k);
    else if (k > t->key)
        search(t->right, k);
    else if (k == t->key)
        return t;
    return NULL;
}

void levelOrder(Node *t)
{
    if (t == NULL)
    {
        cout << "Tree is NULL\n";
        return;
    }
    if (t == root)
    {
        cout << "Key: " << t->key << "\tValue: " << t->value << endl;
        q.push(t);
    }
    Node *p;
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p->left)
        {
            cout << "Key: " << p->left->key << "\tValue: " << p->left->value << endl;
            q.push(p->left);
        }
        if (p->right)
        {
            cout << "Key: " << p->right->key << "\tValue: " << p->right->value << endl;
            q.push(p->right);
        }
    }
}

Node *copy(Node *t)
{
    if (t == nullptr)
            return nullptr;
    Node *newNode = new Node;
    newNode->key = t->key;
    newNode->value = t->value;
    newNode->left = copy(t->left);
    newNode->right = copy(t->right);
    return newNode;
}

Node *mirror(Node *t)
{
    if (t == nullptr)
            return nullptr;
    Node *newNode = new Node;
    newNode->key = t->key;
    newNode->value = t->value;
    newNode->left = mirror(t->right);
    newNode->right = mirror(t->left);
    return newNode;
}

int main()
{
    int choice = 0;
    string k, v;
    Node *t;

    while (1)
    {
        cout << "1. Insert\n"
             << "2. Inorder\n"
             << "3. delete\n"
             << "4. search\n"
             << "5. levelorder\n"
             << "6. mirror\n"
             << "7. copy\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "exiting the program!!\n";
            exit(0);
        case 1:
            cout << "enter the key , value: ";
            cin >> k >> v;
            Insert(root, k, v);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> k;
            Rdelete(root, k);
            break;
        case 4:
            cout << "enter the key to search: ";
            cin >> k;
            t = search(root, k);
            if (t)
                cout << "key found!\n";
            else
                cout << "key Not found\n";
            break;
        case 5:
            levelOrder(root);
            break;
        case 6:
            t = mirror(root);
            inorder(t);
            break;
        case 7:
            t = copy(root);
            inorder(t);
            break;
        default:
            break;
        }
    }
    return 0;
}