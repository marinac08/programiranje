#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* makeNode(int v) {
    return new Node(v);
}

int sum(Node* root) {
    if (root == nullptr) return 0;
    return root->val + sum(root->left) + sum(root->right);
}

int main() {
    Node* root = makeNode(5);
    root->left = makeNode(3);
    root->right = makeNode(7);
    root->left->left = makeNode(1);
    root->left->right = makeNode(4);

    cout << "Sum = " << sum(root);
}
