#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

Node* makeNode(int v) {
    Node* n = new Node;
    n->val = v;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

void preorder(Node* root) {
    if (root == nullptr) return;

    cout << root->val << " ";  
    preorder(root->left);     
    preorder(root->right);      
}

int main() {
    Node* root = makeNode(1);
    root->left = makeNode(2);
    root->right = makeNode(3);
    root->left->left = makeNode(4);
    root->left->right = makeNode(5);

    preorder(root); 
    return 0;
}
