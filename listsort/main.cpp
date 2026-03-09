#include <bits/stdc++.h>
using namespace std;

struct listNode {
    int val;
    listNode *next;
    listNode(): val(0), next(nullptr) {}
    listNode(int x): val(x), next(nullptr) {}
    listNode(int x, listNode *next): val(x), next(next) {}
};

listNode* findMiddleNode(listNode* head) {
    listNode* slow = head;
    listNode* fast = head;
    listNode* prev = nullptr;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if (prev) prev->next = nullptr;
    return slow;
}

listNode* merge(listNode* l1, listNode* l2) {
    listNode dummy(0);
    listNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

listNode* sortList(listNode* head) {
    if (!head || !head->next) return head;
    listNode* mid = findMiddleNode(head);
    listNode* left = sortList(head);
    listNode* right = sortList(mid);
    return merge(left, right);
}

void printList(listNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    listNode* head = new listNode(4);
    head->next = new listNode(2);
    head->next->next = new listNode(1);
    head->next->next->next = new listNode(3);

    head = sortList(head);
    printList(head);
}
