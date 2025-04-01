#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    string key, value;
    TreeNode *left, *right;
    TreeNode(string k, string v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

class DictionaryBST {
private:
    TreeNode* root;
    
    TreeNode* insert(TreeNode* node, string key, string value) {
        if (!node) return new TreeNode(key, value);
        if (key < node->key) node->left = insert(node->left, key, value);
        else if (key > node->key) node->right = insert(node->right, key, value);
        else node->value = value;
        return node;
    }
    
    TreeNode* search(TreeNode* node, string key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }
    
    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
    }
    
    TreeNode* deleteNode(TreeNode* node, string key) {
        if (!node) return node;
        if (key < node->key) node->left = deleteNode(node->left, key);
        else if (key > node->key) node->right = deleteNode(node->right, key);
        else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            TreeNode* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->key);
        }
        return node;
    }
    
    void inorder(TreeNode* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << ": " << node->value << endl;
            inorder(node->right);
        }
    }
    
    TreeNode* mirror(TreeNode* node) {
        if (node) {
            swap(node->left, node->right);
            mirror(node->left);
            mirror(node->right);
        }
        return node;
    }
    
    TreeNode* copy(TreeNode* node) {
        if (!node) return nullptr;
        TreeNode* newNode = new TreeNode(node->key, node->value);
        newNode->left = copy(node->left);
        newNode->right = copy(node->right);
        return newNode;
    }
    
    void levelOrder(TreeNode* node) {
        if (!node) return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front(); q.pop();
                cout << temp->key << ": " << temp->value << " | ";
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            cout << endl;
        }
    }
    
public:
    DictionaryBST() : root(nullptr) {}
    
    void insert(string key, string value) { root = insert(root, key, value); }
    
    string search(string key) {
        TreeNode* res = search(root, key);
        return res ? res->value : "Not Found";
    }
    
    void deleteKey(string key) { root = deleteNode(root, key); }
    
    void display() { inorder(root); }
    
    void mirrorImage() { root = mirror(root); }
    
    DictionaryBST copyDictionary() {
        DictionaryBST newDict;
        newDict.root = copy(root);
        return newDict;
    }
    
    void levelOrderDisplay() { levelOrder(root); }
};

int main() {
    DictionaryBST dict;
    dict.insert("apple", "A fruit");
    dict.insert("banana", "A yellow fruit");
    dict.insert("cherry", "A red fruit");
    
    cout << "Inorder Traversal:" << endl;
    dict.display();
    
    cout << "Search 'banana': " << dict.search("banana") << endl;
    
    dict.deleteKey("banana");
    cout << "After deletion, Inorder Traversal:" << endl;
    dict.display();
    
    dict.mirrorImage();
    cout << "Mirror Inorder Traversal:" << endl;
    dict.display();
    
    cout << "Level Order Traversal:" << endl;
    dict.levelOrderDisplay();
    
    return 0;
}
