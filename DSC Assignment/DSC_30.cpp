// DSC_030_question.cpp
// 30. Split a Circular linked list into two halves.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

// Given head of circular list, split into two circular lists.
// Returns pair(head1, head2)
pair<Node*,Node*> splitCircular(Node* head) {
    if (!head || head->next == head) return {head, nullptr};
    Node* slow = head; Node* fast = head;
    // use tortoise-hare; when fast completes loop, slow at mid
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // For even nodes, move fast one step to point to last node
    if (fast->next->next == head) fast = fast->next;
    Node* head1 = head;
    Node* head2 = slow->next;
    fast->next = head2; // last node points to head2
    slow->next = head1; // mid node points to head1
    return {head1, head2};
}

void printCircular(Node* head) {
    if(!head) { cout<<"Empty\n"; return; }
    Node* cur = head;
    do { cout<<cur->v<<" "; cur = cur->next; } while(cur != head);
    cout<<"\n";
}

int main() {
    // build circular list 1->2->3->4->5->(back to 1)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head; // make circular

    auto [h1, h2] = splitCircular(head);
    cout << "First half: "; printCircular(h1);
    cout << "Second half: "; printCircular(h2);
    return 0;
}
