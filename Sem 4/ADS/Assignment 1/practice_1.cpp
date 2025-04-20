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

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    Node* lchild;
    string key;
    string value;
    Node* rchild;
}*root = NULL;

queue<Node*> q;

Node* Rinsert(Node* t, string k, string v){
    Node* p;
    if(t == NULL){
        p = new Node;
        p->key = k;
        p->value = v;
        p->lchild = p->rchild = NULL;
        if(root == t){
            root = p;
            return root;
        }
        return p;
    }
    else if(k < t->key){
        t->lchild = Rinsert(t->lchild, k, v);
    }
    else if(k > t->key){
        t->rchild = Rinsert(t->rchild, k, v);
    }
    else if(k == t->key){
        return NULL;
    }
    return t;
}

Node* Rsearch(Node* t, string k){
    if(t == NULL) return NULL;
    if(k < t->key){
        Rsearch(t->lchild,k);
    }
    else if(k > t->key){
        Rsearch(t->rchild,k);
    }
    else if(k == t->key){
        cout<<"Key Found!!\n";
        return t;
    }
    return NULL;
}

int height(Node* t){
    if(t == NULL) return 0;
    int x = height(t->lchild);
    int y = height(t->rchild);
    if (x>y)return x+1;
    else{
        return y+1;
    }
    return 0;
}

Node* pred(Node* t){
    while(t && t->rchild){
        t = t->rchild;
    }
    return t;
}

Node* succ(Node* t){
    while(t && t->lchild){
        t = t->lchild;
    }
    return t;
}

Node* Rdelete(Node* t, string k){
    if(t == NULL) return NULL;
    if(k < t->key){
        t->lchild = Rdelete(t->lchild, k);
    }
    else if(k > t->key){
        t->rchild = Rdelete(t->rchild, k);
    }
    else{
        if(t->lchild == NULL && t->rchild == NULL){
            delete t;
            return NULL;
        }

        Node* p;
        if(height(t->lchild) > height(t->rchild)){
            p = pred(t->lchild);
            t->key = p->key;
            t->value = p->value;
            t->lchild = Rdelete(t->lchild, p->key);
        }else{
            p = succ(t->rchild);
            t->key = p->key;
            t->value = p->value;
            t->rchild = Rdelete(t->rchild, p->key);
        }
    }
    return t;
}

void inorder(Node* t){
    if(t != NULL){
        inorder(t->lchild);
        cout<<"Key: "<<t->key<<"\tValue: "<<t->value<<endl;
        inorder(t->rchild);
    }
}

void levelOrder(Node* t){
    cout<<"Key: "<<t->key<<"\tValue: "<<t->value<<endl;
    q.push(t);
    while(!q.empty()){
        t = q.front();
        q.pop();
        if(t->lchild){
            cout<<"Key: "<<t->lchild->key<<"\tValue: "<<t->lchild->value<<endl;
            q.push(t->lchild);
        }
        if(t->rchild){
            cout<<"Key: "<<t->rchild->key<<"\tValue: "<<t->rchild->value<<endl;
            q.push(t->rchild);
        }
    }
}

Node* mirror(Node* t){
    if(t == NULL) return NULL;
    Node* p = new Node;
    p->key = t->key;
    p->value = t->value;
    p->lchild = mirror(t->rchild);
    p->rchild = mirror(t->lchild);
    return p;
}

Node* copy(Node* t){
    if(t == NULL) return NULL;
    Node* p = new Node;
    p->key = t->key;
    p->value = t->value;
    p->lchild = copy(t->lchild);
    p->rchild = copy(t->rchild);
    return p;
}

int main(){
    Rinsert(root, "c", "one");
    Rinsert(root, "a", "two");
    Rinsert(root, "e", "three");
    Rinsert(root, "b", "one");
    Rinsert(root, "d", "two");
    Rinsert(root, "f", "three");
    
    // Rsearch(root, "c");

    

    levelOrder(root);


    return 0;
}