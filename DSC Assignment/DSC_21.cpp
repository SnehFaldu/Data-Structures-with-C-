// DSC_021_question.cpp
// 21. Write a Program to Move the last element to Front in a Linked List.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

// Move last node to front. If list empty or single node, do nothing.
void moveLastToFront(Node*& head) {
    if (!head || !head->next) return;
    Node* prev = nullptr;
    Node* cur = head;
    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }
    // cur is last, prev is second-last
    prev->next = nullptr;
    cur->next = head;
    head = cur;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << (head->next ? " -> " : "\n");
        head = head->next;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout << "Original: "; printList(head);
    moveLastToFront(head);
    cout << "After move last to front: "; printList(head);
    return 0;
}
