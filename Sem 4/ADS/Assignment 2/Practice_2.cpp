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
    Node* lchild;
    int id,score,height;
    Node* rchild;
}*root = NULL;


int Nodeheight(Node* p){
    int hr,hl;
    if(p && p->lchild){
        hl = p->lchild->height;
    }
    else hl = 0;

    if(p && p->rchild){
        hr = p->rchild->height;
    }
    else hr = 0;

    if(hl>hr) return hl+1;
    else return hr+1;
}

int BalanceFactor(Node* p){
    int hr,hl;
    if(p && p->lchild){
        hl = p->lchild->height;
    }
    else hl = 0;

    if(p && p->rchild){
        hr = p->rchild->height;
    }
    else hr = 0;

    return hl-hr;
}

Node* LLrotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    p->lchild = plr->rchild;
    plr->rchild = p;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);

    if(root == p)
        root = pl;
    return pl;
}

Node* LRrotation(Node* p){
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    p->lchild = plr->rchild;
    pl->rchild = plr->lchild;
    plr->lchild = pl;
    plr->rchild = p;

    p->height = Nodeheight(p);
    pl->height = Nodeheight(pl);
    plr->height = Nodeheight(plr);

    if(root == p)
        root = plr;
    return plr;
}

Node* RRrotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);

    if(root == p)
        root = pr;
    return pr;
}

Node* RLrotation(Node* p){
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;
    prl->rchild = pr;
    prl->lchild = p;


    p->height = Nodeheight(p);
    pr->height = Nodeheight(pr);
    prl->height = Nodeheight(prl);
    if(root == p)
        root = prl;
    return prl;
}

Node* Rinsert(Node* t,int k, int v){
    Node* p;
    if(t == NULL){
        p = new Node;
        p->id = k;
        p->score = v;
        p->height = 1;
        p->rchild = p->rchild = NULL;
        if(t == root){
            root = p;
            return root;
        }
        return p;
    }
    else if(k < t->id){
        t->lchild = Rinsert(t->lchild, k, v);
    }
    else if(k > t->id){
        t->rchild = Rinsert(t->rchild, k, v);
    }
    else if(k == t->id){
        return NULL;
    }
    

    p->height = Nodeheight(p);
    int pn = BalanceFactor(p);
    int pl = BalanceFactor(p->lchild);
    int pr = BalanceFactor(p->rchild);
    
    if(pn == 2 && pl == 1){
        return LLrotation(p);
    }
    else if(pn == 2 && pl == -1){
        return LRrotation(p);
    }
    else if(pn == -2 && pl == -1){
        return RRrotation(p);
    }
    else if(pn == -2 && pl == 1){
        return RLrotation(p);
    }
}

Node* pred(Node* p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}


Node* succ(Node* p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

Node* Rdelete(Node* t, int k){
    Node* p;
    if(t == NULL) return NULL;
    if(k < t->id){
        t->lchild = Rdelete(t->lchild, k);
    }
    else if(k > t->id){
        t->rchild = Rdelete(t->rchild, k);
    }
    else{
        if(t->lchild == NULL && t->rchild == NULL){
            delete t;
            return NULL;
        }

        if(Nodeheight(t->lchild) > Nodeheight(t->rchild)){
            p = pred(t->lchild);
            t->id = p->id;
            t->score = p->score;
            t->lchild = Rdelete(t->lchild, p->id);
        }
        else{
            p = succ(t->rchild);
            t->id = p->id;
            t->score = p->score;
            t->rchild = Rdelete(t->rchild, p->id);
        }
    }

    t->height = Nodeheight(t);
    int tn = BalanceFactor(t);
    int tl = BalanceFactor(t->lchild);
    int tr = BalanceFactor(t->rchild);
    
    if(tn == 2 && tl == 1){
        return LLrotation(t);
    }
    else if(tn == 2 && tl == -1){
        return LRrotation(t);
    }
    else if(tn == -2 && tl == -1){
        return RRrotation(t);
    }
    else if(tn == -2 && tl == 1){
        return RLrotation(t);
    }
    return t;
}


void inorder(Node* t){
    if(t){
        inorder(t->lchild);
        cout<<"ID: "<<t->id<<"\tScore: "<<t->score<<endl;
        inorder(t->rchild);
    }
}
int main(){
    
    return 0;
} 