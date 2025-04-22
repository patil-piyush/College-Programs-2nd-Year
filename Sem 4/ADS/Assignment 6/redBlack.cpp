#include <iostream>
#include <string>
using namespace std;

enum Color { RED, BLACK };

struct Directory {
    string name;
    Directory* left;
    Directory* right;
    Directory* parent;
    Color color;

    Directory(string n = "") {
        name = n;
        left = right = parent = NULL;
        color = RED;
    }
};

class DirectoryTree {
private:
    Directory* root;
    Directory* NIL;

    void rotateLeft(Directory* x) {
        Directory* y = x->right;
        x->right = y->left;
        if (y->left != NIL)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rotateRight(Directory* x) {
        Directory* y = x->left;
        x->left = y->right;
        if (y->right != NIL)
            y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == NIL)
            root = y;
        else if (x == x->parent->right)
            x->parent->right = y;
        else
            x->parent->left = y;
        y->right = x;
        x->parent = y;
    }

    void fixInsert(Directory* z) {
        while (z->parent->color == RED) {
            Directory* gp = z->parent->parent;
            if (z->parent == gp->left) {
                Directory* y = gp->right;
                //uncle exits with red color
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->right) {    // rotations
                        z = z->parent;
                        rotateLeft(z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateRight(gp);
                }
            } else {                               //reverse
                Directory* y = gp->left;
                if (y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    gp->color = RED;
                    z = gp;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rotateRight(z);
                    }
                    z->parent->color = BLACK;
                    gp->color = RED;
                    rotateLeft(gp);
                }
            }
        }
        root->color = BLACK;
    }

    void inorder(Directory* node) {
        if (node != NIL) {
            inorder(node->left);
            cout << node->name << " (" << (node->color == RED ? "RED" : "BLACK") << ")\n";
            inorder(node->right);
        }
    }

    Directory* search(Directory* node, string name) {
        if (node == NIL || name == node->name)
            return node;
        if (name < node->name)
            return search(node->left, name);
        return search(node->right, name);
    }

    Directory* minimum(Directory* node) {
        while (node->left != NIL)
            node = node->left;
        return node;
    }

    void transplant(Directory* u, Directory* v) {
        if (u->parent == NIL)
            root = v;
        else if (u == u->parent->left)
            u->parent->left = v;
        else
            u->parent->right = v;
        v->parent = u->parent;
    }

    void fixDelete(Directory* x) {
        while (x != root && x->color == BLACK) {
            if (x == x->parent->left) {
                Directory* w = x->parent->right;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateLeft(x->parent);
                    w = x->parent->right;
                }
                if (w->left->color == BLACK && w->right->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->right->color == BLACK) {
                        w->left->color = BLACK;
                        w->color = RED;
                        rotateRight(w);
                        w = x->parent->right;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->right->color = BLACK;
                    rotateLeft(x->parent);
                    x = root;
                }
            } else {
                Directory* w = x->parent->left;
                if (w->color == RED) {
                    w->color = BLACK;
                    x->parent->color = RED;
                    rotateRight(x->parent);
                    w = x->parent->left;
                }
                if (w->right->color == BLACK && w->left->color == BLACK) {
                    w->color = RED;
                    x = x->parent;
                } else {
                    if (w->left->color == BLACK) {
                        w->right->color = BLACK;
                        w->color = RED;
                        rotateLeft(w);
                        w = x->parent->left;
                    }
                    w->color = x->parent->color;
                    x->parent->color = BLACK;
                    w->left->color = BLACK;
                    rotateRight(x->parent);
                    x = root;
                }
            }
        }
        x->color = BLACK;
    }

public:
    DirectoryTree() {
        NIL = new Directory();
        NIL->left = NIL->right = NIL->parent = NIL;
        NIL->color = BLACK;
        root = NIL;
    }

    void insertDirectory(string name) {
        Directory* z = new Directory(name);
        z->left = z->right = z->parent = NIL;
        Directory* y = NIL;
        Directory* x = root;
        while (x != NIL) {
            y = x;
            if (z->name < x->name)
                x = x->left;
            else
                x = x->right;
        }
        z->parent = y;
        if (y == NIL)
            root = z;
        else if (z->name < y->name)
            y->left = z;
        else
            y->right = z;
        z->color = RED;
        fixInsert(z);
    }

    void deleteDirectory(string name) {
        Directory* z = search(root, name);
        if (z == NIL) {
            cout << "Directory not found.\n";
            return;
        }

        Directory* y = z;
        Directory* x;
        Color yOriginalColor = y->color;

        if (z->left == NIL) {
            x = z->right;
            transplant(z, z->right);
        } else if (z->right == NIL) {
            x = z->left;
            transplant(z, z->left);
        } else {
            y = minimum(z->right);
            yOriginalColor = y->color;
            x = y->right;
            if (y->parent == z) {
                x->parent = y;
            } else {
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
            y->color = z->color;
        }
        delete z;
        if (yOriginalColor == BLACK)
            fixDelete(x);
    }

    void displayDirectories() {
        inorder(root);
    }
};

int main() {
    DirectoryTree dt;
    int choice;
    string name;

    while (true) {
        cout << "\n1. Insert Directory\n2. Delete Directory\n3. Display Directory Tree\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore newline from previous input

        switch (choice) {
            case 1:
                cout << "Enter directory name to insert: ";
                getline(cin, name);
                dt.insertDirectory(name);
                break;
            case 2:
                cout << "Enter directory name to delete: ";
                getline(cin, name);
                dt.deleteDirectory(name);
                break;
            case 3:
                cout << "Directory Tree:\n";
                dt.displayDirectories();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}