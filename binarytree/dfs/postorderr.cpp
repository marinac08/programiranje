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

void postorder(Node* root) {
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    Node* root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);

    postorder(root);

    return 0;
}
