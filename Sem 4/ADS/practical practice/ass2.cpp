/*
Implement a multiplayer game system that uses an AVL tree data structure to organize and
manage player data efficiently. The multiplayer game supports multiple players participating
simultaneously, and the AVL tree is used to store player information such as player_id and
scores (key, value pair). The system should provide following operation:
1. Player Registration
2. Leaderboard Display
3. Remove player from game
*/

#include<iostream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int id,score;
    int height;
}*root = NULL;

int NodeHeight(Node* t){
    int hl=0, hr = 0;
    if(t->left) hl = t->left->height;
    if(t->right) hr = t->right->height;

    return hl>hr? hl:hr;
}

int balanceFactor(Node* t){
    int hl=0, hr = 0;
    if(t->left) hl = t->left->height;
    if(t->right) hr = t->right->height;

    return hl-hr;
}

Node* LLRotation(Node* p){

}

Node* LRRotation(Node* p){

}

Node* RRRotation(Node* p){

}

Node* RLRotation(Node* p){

}

struct Node* Insert(Node* t,int i, int s){
    Node* p;
    if(t == NULL){
        p = new Node;
        p->id = i;
        p->score = s;
        p->left = p->right = NULL;
        p->height = 1;
        if(t == root){
            root= p;
            return root;
        }
        t =p;
        return t;
    }
    else if(i<t->id) t->left = Insert(t->left,i,s);
    else if(i>t->id) t->right = Insert(t->right,i,s);

    t->height = NodeHeight(t);

    if(balanceFactor(t) == 2 && balanceFactor(t->left) == 1){
        return LLRotation(t);
    }
    else if(balanceFactor(t) == 2 && balanceFactor(t->left) == -1){
        return LRRotation(t);
    }
    else if(balanceFactor(t) == -2 && balanceFactor(t->left) == -1){
        return RRRotation(t);
    }
    else if(balanceFactor(t) == -2 && balanceFactor(t->left) == 1){
        return RLRotation(t);
    }

    return t;
}

Node* pred(Node* p){
    while(p && p->right) p = p->right;
    return p;
}

Node* succ(Node* p){
    while(p && p->left) p = p->left;
    return p;
}

Node* Rdelete(Node* t, int i){
    if(t == NULL) return NULL;
    if(i < t->id) t->left = Rdelete(t->left,i);
    else if(i > t->id) t->right = Rdelete(t->right, i);
    else{
        if(t->left == NULL && t->right==NULL){
            delete t;
            return NULL;
        }
        Node* p;
        if(NodeHeight(t->left) > NodeHeight(t->right)){
            p = pred(t->left);
            t->id = p->id;
            t->score = p->score;
            t->left = Rdelete(t->left,p->id);
        }
        else{
            p = succ(t->right);
            t->id = p->id;
            t->score = p->score;
            t->right = Rdelete(t->right,p->id);
        }
    }

    t->height = NodeHeight(t);

    if(balanceFactor(t) == 2 && balanceFactor(t->left) == 1){
        return LLRotation(t);
    }
    else if(balanceFactor(t) == 2 && balanceFactor(t->left) == -1){
        return LRRotation(t);
    }
    else if(balanceFactor(t) == -2 && balanceFactor(t->left) == -1){
        return RRRotation(t);
    }
    else if(balanceFactor(t) == -2 && balanceFactor(t->left) == 1){
        return RLRotation(t);
    }

    return t;    
}

void inorder(Node* t){
    if(t){
        inorder(t->left);
        cout<<"Id: "<<t->id<<"\tscore: "<<t->score<<endl;
        inorder(t->right);
    }
}

int main(){
    int choice = 0;
    int i, s;
    Node *t;

    while (1)
    {
        cout << "1. Insert\n"
             << "2. Inorder\n"
             << "3. delete\n"
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
            cin >> i >> s;
            Insert(root, i, s);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            cout << "Enter the key to delete: ";
            cin >> i;
            Rdelete(root, i);
            break;
        default:
            break;
        }
    }
    return 0;    
}