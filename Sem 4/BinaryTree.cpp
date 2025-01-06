#include<iostream>
using namespace std;

//structure for Node
struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root;

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

void create(){
    struct Queue q;
    create(&q, 100);
    int x;
    struct Node *p;
    cout<<"enter the data for root node: ";
    cin>>x;
    struct Node *t = new Node;
    t->data = x;
    t->rchild = t->lchild = NULL;
    root = t;
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter the data for left child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            struct Node *t = new Node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        cout<<"Enter the data for right child of "<<p->data<<" : ";
        cin>>x;
        if(x!=-1){
            struct Node *t = new Node;
            t->data = x;
            t->rchild = t->lchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p!=NULL){
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
    return;
}

void inorder(struct Node *p){
    if(p!=NULL){
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
    return;
}


void postorder(struct Node *p){
    if(p!=NULL){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
    return;
}

int main(){
    create();
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;
    return 0;
}
