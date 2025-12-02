// DSC_028_question.cpp
// 28. Find the middle Element of a linked list.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

int findMiddle(Node* head) {
    if (!head) throw runtime_error("empty list");
    Node* slow = head; Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->v;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    cout << "Middle element is: " << findMiddle(head) << "\n"; // 3
    return 0;
}
