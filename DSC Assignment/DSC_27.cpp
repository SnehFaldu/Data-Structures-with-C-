// DSC_027_question.cpp
// 27. Quicksort for Linked Lists. [Very Important]
// We'll implement quicksort by partitioning around pivot and recursing.
// Note: for linked lists mergesort is usually preferred. This is educational.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

// Append node to tail and update tail reference.
void appendNode(Node*& head, Node*& tail, Node* node) {
    if (!head) head = tail = node;
    else { tail->next = node; tail = node; }
    tail->next = nullptr;
}

Node* quickSortRec(Node* head) {
    if (!head || !head->next) return head;
    // choose pivot as head
    int pivot = head->v;
    Node *lessH=nullptr, *lessT=nullptr;
    Node *eqH=nullptr, *eqT=nullptr;
    Node *gtH=nullptr, *gtT=nullptr;

    Node* cur = head;
    while (cur) {
        if (cur->v < pivot) appendNode(lessH, lessT, new Node(cur->v));
        else if (cur->v == pivot) appendNode(eqH, eqT, new Node(cur->v));
        else appendNode(gtH, gtT, new Node(cur->v));
        cur = cur->next;
    }
    lessH = quickSortRec(lessH);
    gtH = quickSortRec(gtH);

    // concatenate lessH + eqH + gtH
    Node dummy(0); Node* tail = &dummy;
    if (lessH) { tail->next = lessH; while (tail->next) tail = tail->next; }
    if (eqH) { tail->next = eqH; while (tail->next) tail = tail->next; }
    if (gtH) { tail->next = gtH; }
    return dummy.next;
}

void print(Node* h) { while(h){ cout<<h->v<<" "; h=h->next; } cout<<"\n"; }

int main() {
    Node* head = new Node(3);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    cout << "Before: "; print(head);
    head = quickSortRec(head);
    cout << "After quicksort: "; print(head);
    return 0;
}
