// DSC_029_question.cpp
// 29. Check if a linked list is a circular linked list.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

bool isCircular(Node* head) {
    if (!head) return false;
    Node* slow = head; Node* fast = head->next;
    while (fast && fast->next) {
        if (slow == fast) return true;
        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}

int main() {
    Node* a = new Node(1);
    a->next = new Node(2);
    a->next->next = new Node(3);
    // make circular for test:
    a->next->next->next = a; // comment this line to test non-circular
    cout << (isCircular(a) ? "Circular\n" : "Not circular\n");
    return 0;
}
