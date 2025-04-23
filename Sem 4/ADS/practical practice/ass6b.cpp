#include <iostream>
using namespace std;

enum Color
{
    red,
    black
};

class directory
{
public:
    directory *left;
    directory *right;
    directory *parent;
    string name;
    Color color;
    directory(string n)
    {
        name = n;
        color = red;
        left = right = parent = NULL;
    }
};

class filesystem
{
private:
    directory *root;
    directory *NIL;

    void LeftRotation(directory *x)
    {
        directory *y = x->right;
        x->right = y->left;
        if (y->left != NIL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void RightRotation(directory *x)
    {
        directory *y = x->left;
        x->left = y->right;
        if (y->right)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NULL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    void InsertFix(directory *z)
    {
        while(z->parent && z->parent->color == red){
            if(z->parent == z->parent->parent->left){
                directory* y = z->parent->parent->right;
                if(y->color == red){
                    y->color = black;
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                }
                else{
                    if(z == z->parent->right){
                        z = z->parent;
                        LeftRotation(z);
                    }
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    RightRotation(z->parent->parent);
                }
            }
            else{
                directory* y = z->parent->parent->left;
                if(y->color == red){
                    y->color = black;
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    z = z->parent->parent;
                }
                else{
                    if(z == z->parent->left){
                        z = z->parent;
                        RightRotation(z);
                    }
                    z->parent->color = black;
                    z->parent->parent->color = red;
                    LeftRotation(z->parent->parent);
                }
            }
        }
        root->color = black;
    }

    void Inorder(directory *root)
    {
        if (root != NIL)
        {
            Inorder(root->left);
            cout << "Name: " << root->name << "\tcolor: " << root->color << endl;
            Inorder(root->right);
        }
    }

    directory *succ(directory *p)
    {
        if (p && p->left)
        {
            p = p->left;
        }
        return p;
    }

    directory *deletedirectory(directory *t, string n)
    {
        if (t == NIL)
            return NIL;
        else if (n < t->name)
            t->left = deletedirectory(t->left, n);
        else if (n > t->name)
            t->right = deletedirectory(t->right, n);
        else
        {
            if (t->right == NIL && t->left == NIL)
            {
                delete t;
                return NIL;
            }
            else if (t->right == NIL || t->left == NIL)
            {
                directory *child = t->left ? t->left : t->right;
                delete t;
                return child;
            }
            else
            {
                directory *p = succ(t->right);
                t->name = p->name;
                t->right = deletedirectory(t->right, p->name);
            }
        }
        return t;
    }

public:
    filesystem()
    {
        NIL = new directory("NIL");
        NIL->color = black;
        root = NIL;
    }

    void Insert(string n)
    {
        directory *nn = new directory(n);
        nn->left = nn->right = NIL;
        nn->color = red;
        directory *x = root;
        directory *y = NULL;
        while (x != NIL)
        {
            y = x;
            if (n < x->name)
                x = x->left;
            else if (n > x->name)
                x = x->right;
        }
        nn->parent = y;
        if (y == NULL)
            root = nn;
        else if (n < y->name)
            y->left = nn;
        else
            y->right = nn;

        InsertFix(nn);
    }
    void Display()
    {
        cout << "The file system contains following directories: \n";
        Inorder(root);
    }

    void Remove(string a)
    {
        root = deletedirectory(root, a);
        if (root)
            cout << "directory deleted successfully!\n";
        else
            cout << "directory not found!";
    }
};

int main()
{
    filesystem fs;
    int choice;
    string name;
    do
    {
        cout << "\nFile System Menu\n";
        cout << "1. Insert Directory\n";
        cout << "2. Delete Directory\n";
        cout << "3. Display File System\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter directory name: ";
            cin >> name;
            fs.Insert(name);
            break;
        case 2:
            cout << "Enter directory name to delete: ";
            cin >> name;
            fs.Remove(name);
            break;
        case 3:
            fs.Display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, try again!\n";
        }
    } while (choice != 4);
    return 0;
}