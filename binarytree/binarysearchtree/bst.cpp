#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) { 
    Node* n = new Node;
    n->key = key;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insert(Node* root, int key) {
    if (root == nullptr) 
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

bool search(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->key) return true;
        if (key < root->key) root = root->left;
        else                 root = root->right;
    }
    return false;
}

Node* findMin(Node* root) { 
    while (root->left != nullptr) 
        root = root->left;
    return root;
}

Node* removeNode(Node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->key) {
        root->left = removeNode(root->left, key);
    } else if (key > root->key) {
        root->right = removeNode(root->right, key);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        }
        else if (root->right == nullptr) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }
        Node* minNode = findMin(root->right);
        root->key = minNode->key;
        root->right = removeNode(root->right, minNode->key);
    }
    return root;
}

void print(Node* root) {
    if (!root) return;
    print(root->left);
    cout << root->key << " ";
    print(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);
    root = insert(root, 1);
    root = insert(root, 3);

    cout << "Search 3 -> " << (search(root, 3) ? "FOUND" : "NOT FOUND") << endl;

    root = removeNode(root, 2);

    print(root);

    return 0;
}
