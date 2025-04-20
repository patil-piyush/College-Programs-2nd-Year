#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int keys[2];  // Since it's a B-tree of order 3, max 2 keys per node
    Node* children[3];  // 3 children per node
    int numKeys;
    bool leaf;

    Node(bool leaf = true) : numKeys(0), leaf(leaf) {
        for (int i = 0; i < 3; i++) children[i] = nullptr;
    }
};

class BTree {
private:
    Node* root;

    void splitChild(Node* parent, int i) {
        Node* child = parent->children[i];
        Node* newChild = new Node(child->leaf);
        newChild->numKeys = 1;
        newChild->keys[0] = child->keys[1];

        if (!child->leaf) {
            for (int j = 0; j < 2; j++)
                newChild->children[j] = child->children[j+2];
        }

        child->numKeys = 1;
        for (int j = parent->numKeys; j > i; j--) {
            parent->children[j+1] = parent->children[j];
        }
        parent->children[i+1] = newChild;

        for (int j = parent->numKeys; j > i; j--) {
            parent->keys[j] = parent->keys[j-1];
        }
        parent->keys[i] = child->keys[0];
        parent->numKeys++;
    }

    void insertNonFull(Node* node, int key) {
        int i = node->numKeys - 1;

        if (node->leaf) {
            while (i >= 0 && key < node->keys[i]) {
                node->keys[i+1] = node->keys[i];
                i--;
            }
            node->keys[i+1] = key;
            node->numKeys++;
        } else {
            while (i >= 0 && key < node->keys[i]) i--;
            i++;

            if (node->children[i]->numKeys == 2) {
                splitChild(node, i);
                if (key > node->keys[i]) i++;
            }
            insertNonFull(node->children[i], key);
        }
    }

    void levelOrder(Node* root) {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for (int i = 0; i < curr->numKeys; i++)
                cout << curr->keys[i] << " ";
            cout << "| ";
            for (int i = 0; i <= curr->numKeys; i++) {
                if (curr->children[i]) q.push(curr->children[i]);
            }
        }
    }

    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) return node;

        int i = 0;
        while (i < node->numKeys && key > node->keys[i]) i++;

        if (i < node->numKeys && key == node->keys[i]) {
            if (node->leaf) {
                for (int j = i; j < node->numKeys - 1; j++) {
                    node->keys[j] = node->keys[j+1];
                }
                node->numKeys--;
            } else {
                Node* pred = node->children[i];
                Node* succ = node->children[i+1];
                if (pred->numKeys >= 1) {
                    int predKey = pred->keys[pred->numKeys-1];
                    node->keys[i] = predKey;
                    deleteNode(pred, predKey);
                } else if (succ->numKeys >= 1) {
                    int succKey = succ->keys[0];
                    node->keys[i] = succKey;
                    deleteNode(succ, succKey);
                } else {
                    merge(node, i);
                    deleteNode(pred, key);
                }
            }
        } else {
            if (node->leaf) return node;
            deleteNode(node->children[i], key);
        }
        return node;
    }

    void merge(Node* parent, int index) {
        Node* child1 = parent->children[index];
        Node* child2 = parent->children[index+1];

        child1->keys[1] = parent->keys[index];
        for (int i = 0; i < child2->numKeys; i++) {
            child1->keys[i+2] = child2->keys[i];
        }
        for (int i = 0; i <= child2->numKeys; i++) {
            child1->children[i+2] = child2->children[i];
        }
        for (int i = index; i < parent->numKeys - 1; i++) {
            parent->keys[i] = parent->keys[i+1];
        }
        for (int i = index+1; i < parent->numKeys; i++) {
            parent->children[i] = parent->children[i+1];
        }
        parent->numKeys--;
        child1->numKeys += child2->numKeys + 1;
        delete child2;
    }

public:
    BTree() : root(new Node(true)) {}

    void insert(int key) {
        if (root->numKeys == 2) {
            Node* newNode = new Node(false);
            newNode->children[0] = root;
            splitChild(newNode, 0);
            root = newNode;
        }
        insertNonFull(root, key);
    }

    void levelOrderDisplay() {
        levelOrder(root);
        cout << endl;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }
};

int main() {
    BTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(15);
    tree.insert(30);
    tree.insert(25);

    cout << "Level order traversal: ";
    tree.levelOrderDisplay();

    tree.deleteKey(6);
    tree.deleteKey(20);

    cout << "Level order after deletions: ";
    tree.levelOrderDisplay();

    return 0;
}
