// DSC_026_question.cpp
// 26. Merge Sort For Linked lists. [Very Important]

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

Node* mergeTwo(Node* a, Node* b) {
    Node dummy(0), *t = &dummy;
    while (a && b) {
        if (a->v < b->v) { t->next = a; a = a->next; }
        else { t->next = b; b = b->next; }
        t = t->next;
    }
    t->next = a ? a : b;
    return dummy.next;
}

Node* getMid(Node* head) {
    if (!head) return head;
    Node* slow = head; Node* fast = head->next;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node* mid = getMid(head);
    Node* right = mid->next;
    mid->next = nullptr;
    Node* leftSorted = mergeSort(head);
    Node* rightSorted = mergeSort(right);
    return mergeTwo(leftSorted, rightSorted);
}

void print(Node* h) { while(h){ cout << h->v << " "; h = h->next; } cout << "\n"; }

int main() {
    Node* head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    cout << "Before: "; print(head);
    head = mergeSort(head);
    cout << "After merge sort: "; print(head);
    return 0;
}
