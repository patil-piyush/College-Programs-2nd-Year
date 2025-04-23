#include <iostream>
#include <string>
using namespace std;

enum Color
{
    RED,
    BLACK
};

class directory
{
public:
    string name;
    directory *left, *right, *parent;
    Color color;
    directory(string a)
    {
        name = a;
        left = right = parent = NULL;
        color = RED;
    }
};

class fileSystem
{
private:
    directory *root;
    directory *Nil;

    void leftRotation(directory *x)
    {
        directory *y = x->right;
        x->right = y->left;
        if (y->left != Nil)
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

    void rightRotation(directory *x)
    {
        directory *y = x->left;
        x->left = y->right;
        if (y->right != Nil)
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
        while (z->parent && z->parent->color == RED)
        {
            if (z->parent == z->parent->parent->left)
            {
                directory *y = z->parent->parent->right;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    y->color = BLACK;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->right)
                    {
                        z = z->parent;
                        leftRotation(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotation(z->parent->parent);
                }
            }
            else
            {
                directory *y = z->parent->parent->left;
                if (y->color == RED)
                {
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    y->color = BLACK;
                    z = z->parent->parent;
                }
                else
                {
                    if (z == z->parent->left)
                    {
                        z = z->parent;
                        rightRotation(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    leftRotation(z->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }

    void Inorder(directory *root)
    {
        if (root != Nil)
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

    directory *deleteDirectory(directory *root, string a)
    {
        if (root == Nil)
            return Nil;
        if (a < root->name)
        {
            root->left = deleteDirectory(root->left, a);
        }
        else if (a > root->name)
        {
            root->right = deleteDirectory(root->right, a);
        }
        else
        {
            if (root->left == Nil && root->right == Nil)
            {
                delete root;
                return Nil;
            }
            else if (root->left == Nil || root->right == Nil)
            {
                directory *child = (root->left != Nil) ? root->left : root->right;
                delete root;
                return child;
            }
            else
            {
                directory *p = succ(root->right);
                root->name = p->name;
                root->right = deleteDirectory(root->right, p->name);
            }
        }
        return root;
    }

public:
    fileSystem()
    {
        Nil = new directory("Nil");
        Nil->color = BLACK;
        root = Nil;
    }
    void Insert(string a)
    {
        directory *nn = new directory(a);
        nn->right = nn->left = Nil;
        directory *y = NULL;
        directory *x = root;
        while (x != Nil)
        {
            y = x;
            if (a < x->name)
                x = x->left;
            else
                x = x->right;
        }
        nn->parent = y;
        if (y == NULL)
            root = nn;
        else if (nn->name < y->name)
            y->left = nn;
        else
            y->right = nn;
        nn->color = RED;
        InsertFix(nn);
    }

    void Display()
    {
        cout << "The file system contains following directories: \n";
        Inorder(root);
    }

    void Remove(string a)
    {
        root = deleteDirectory(root, a);
        if (root)
            cout << "directory deleted successfully!\n";
        else
            cout << "directory not found!";
    }
};

int main()
{
    fileSystem fs;
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