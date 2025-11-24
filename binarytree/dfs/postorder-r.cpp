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
    stack<Node*> st;
    Node* cur = root;
    Node* last = nullptr;

    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        } 
        else {
            Node* top = st.top();
            if (top->right != nullptr && last != top->right) {
                cur = top->right;
            } else {
                cout << top->val << " ";
                last = top;
                st.pop();
            }
        }
    }
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
