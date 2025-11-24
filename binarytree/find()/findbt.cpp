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

bool find(Node* root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;

    return find(root->left, key) || find(root->right, key);
}


int main() {
    Node* root = makeNode(10);
    root->left = makeNode(5);
    root->right = makeNode(20);
    root->left->left = makeNode(3);

    cout << "20?" << "" << " - " << (find(root, 20) ? "FOUND" : "NOT FOUND") << endl;
    cout << "99?" << "" << " - " << (find(root, 99) ? "FOUND" : "NOT FOUND") << endl;
}
