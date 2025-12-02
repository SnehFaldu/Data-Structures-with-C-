// DSC_022_question.cpp
// 22. Add “1” to a number represented as a Linked List.

#include <bits/stdc++.h>
using namespace std;

struct Node { int d; Node* next; Node(int x): d(x), next(nullptr) {} };

// Reverse list helper.
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    while (head) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

Node* addOne(Node* head) {
    head = reverseList(head);
    Node* cur = head;
    int carry = 1;
    Node* prev = nullptr;
    while (cur && carry) {
        int sum = cur->d + carry;
        cur->d = sum % 10;
        carry = sum / 10;
        prev = cur;
        cur = cur->next;
    }
    if (carry) prev->next = new Node(carry);
    return reverseList(head);
}

void printNum(Node* head) {
    while (head) { cout << head->d; head = head->next; }
    cout << "\n";
}

int main() {
    // number 129 -> list 1->2->9
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(9);
    cout << "Before: "; printNum(head);
    head = addOne(head);
    cout << "After adding 1: "; printNum(head); // 130
    return 0;
}
