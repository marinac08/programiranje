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

void inorder(Node* root) {
    stack<Node*> st;
    Node* cur = root;

    while (cur != nullptr || !st.empty()) {
        while (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        }

        cur = st.top();
        st.pop();
        cout << cur->val << " ";

        cur = cur->right;
    }
}
int main() {
    Node* root = makeNode(4);
    root->left = makeNode(2);
    root->right = makeNode(6);
    root->left->left = makeNode(1);
    root->left->right = makeNode(3);
    root->right->left = makeNode(5);
    root->right->right = makeNode(7);

    inorder(root);
    return 0;
}
