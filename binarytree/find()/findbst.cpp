#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
};

bool find(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->val)
            return true;
        else if (key < root->val)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

Node* makeNode(int v) {
    Node* n = new Node;
    n->val = v;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

Node* insert(Node* root, int key) {
    if (!root) return makeNode(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);

    return root;
}
int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 12);
    root = insert(root, 20);

    cout << "12?" << "" << " - " << (find(root, 12) ? "FOUND" : "NOT FOUND") << endl;
    cout << "7?" << "" << " - " << (find(root, 7) ? "FOUND" : "NOT FOUND") << endl;
}
