#include <bits/stdc++.h>
using namespace std;

struct Node {
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

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {
        Node* cur = st.top();
        st.pop();

        cout << cur->val << " ";

        if (cur->right) st.push(cur->right);
        if (cur->left)  st.push(cur->left);
    }
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