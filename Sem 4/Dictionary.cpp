#include<iostream>
using namespace std;

//queue
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
//end of queue

//structure for Node
struct Node{
    struct Node *lchild;
    string key;
    string value;
    struct Node *rchild;
}*root;

void createBST(){
    struct Node *p,*t;
    string x,y;
    Queue q;
    create(&q,100);
    cout<<"Enter the key-value pair for root Node: ";
    cin>>x>>y;
    t= new Node;
    t->key = x;
    t->value = y;
    t->lchild=t->rchild = NULL;
    root = t;
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter the key-value pair for left child of "<<t->value<<" :";
        cin>>x>>y;
        if(x!="-" && y!="-"){
            t= new Node;
            t->key = x;
            t->value = y;
            t->lchild=t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        cout<<"Enter the key-value pair for right child of "<<t->value<<" :";
        cin>>x>>y;
        if(x!="-" && y!="-"){
            t= new Node;
            t->key = x;
            t->value = y;
            t->lchild=t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

