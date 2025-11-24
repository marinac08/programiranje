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

void bfs(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        cout << cur->val << " ";

        if (cur->left  != nullptr) q.push(cur->left);
        if (cur->right != nullptr) q.push(cur->right);
    }
}

int main() {
    Node* root = makeNode(10);
    root->left = makeNode(5);
    root->right = makeNode(20);
    root->right->left = makeNode(15);

    bfs(root);

    return 0;
}
