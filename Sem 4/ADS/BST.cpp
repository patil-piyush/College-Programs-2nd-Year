#include <iostream>
using namespace std;

// structure for Node
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root;

// queue
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(q->size * sizeof(struct Node *));
}

void enqueue(struct Queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full!!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct Node *dequeue(struct Queue *q)
{
    struct Node *x = NULL;
    if (q->rear == q->front)
        printf("Queue is Empty\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    return q.front == q.rear;
}
// end of queue

// Insert function for inserting an element in a BST by level order traversal
void InsertLevelOrder(Node *t, int key)
{
    struct Node *p, *r = NULL;
    Queue q;
    create(&q, 100);
    // if root is not present
    if (t == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        t = p;
        return;
    }

    enqueue(&q, t);
    while (!isEmpty(q))
    {
        r = dequeue(&q);
        if (r->lchild != NULL)
        {
            enqueue(&q, r->lchild);
        }
        else
        {
            p = new Node;
            p->data = key;
            p->lchild = p->rchild = NULL;
            r->lchild = p;
            return;
        }

        if (r->rchild != NULL)
        {
            enqueue(&q, r->rchild);
        }
        else
        {
            p = new Node;
            p->data = key;
            p->rchild = p->rchild = NULL;
            r->rchild = p;
            return;
        }
    }
}

// Insert function for inserting an element in a BST
void Insert(Node *t, int key)
{
    struct Node *r = NULL, *p;
    if (t == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return;
    }

    while (t != NULL)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;
    if (key < r->data)
        r->lchild = p;
    else
        r->rchild = p;
}

// function to create a binary tree from inorder traversal
void createInorder()
{
    int n, ele;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    int Ino[n];
    cout << "\n(Elements must be sorted)\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element: ";
        cin >> Ino[i];
    }
    root = new Node;
    root->data = Ino[n / 2];
    root->lchild = root->rchild = NULL;
    for (int i = n / 2; i >= 0; --i)
    {
        Insert(root, Ino[i]);
    }
    for (int j = n / 2; j < n; ++j)
    {
        Insert(root, Ino[j]);
    }
}

// create function for tree creation
void create()
{
    int x;
    struct Node *p;
    cout << "enter the data for root node: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->rchild = root->lchild = NULL;
    cout << "Enter the number of nodes you want to add: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << "th element to be inserted: ";
        cin >> x;
        Insert(root, x);
    }
}

// Recurssive traversals
void Preorder(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
    return;
}

void Inorder(struct Node *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
    return;
}

void Postorder(struct Node *p)
{
    if (p != NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
    return;
}

// function for counting the total Nodes
int Count(struct Node *p)
{
    if (p != NULL)
    {
        int x = Count(p->lchild);
        int y = Count(p->rchild);
        return x + y + 1;
    }
    return 0;
}

// function for counting the leaf Nodes
int CountLeaf(struct Node *p)
{
    if (p != NULL)
    {
        int x = CountLeaf(p->lchild);
        int y = CountLeaf(p->rchild);
        if (p->lchild == NULL && p->rchild == NULL)
            return x + y + 1;
        else
            return x + y;
    }
    return 0;
}

int main()
{
    createInorder();
    cout << "Preorder: ";
    Preorder(root);
    cout << endl;
    // int key;
    // cout<<"Enter the key that you wamt to insert by level order: ";
    // cin>>key;
    // InsertLevelOrder(root,key);

    // cout << "Inorder: ";
    // Inorder(root);
    // cout << endl;
    // cout<<"Postorder: ";
    // Postorder(root);
    // cout<<endl;
    // cout<<"Number of Nodes: ";
    // cout<<Count(root);
    // cout<<endl;
    // cout<<"Number of Leaf Nodes: ";
    // cout<<CountLeaf(root);
    // cout<<endl;
    return 0;
}