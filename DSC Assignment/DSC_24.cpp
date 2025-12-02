// DSC_024_question.cpp
// 24. Intersection of two Sorted Linked List. (build a list of common elements)

#include <bits/stdc++.h>
using namespace std;
struct Node { int d; Node* next; Node(int x): d(x), next(nullptr) {} };

Node* intersectSorted(Node* a, Node* b) {
    Node dummy(0), *tail = &dummy;
    while (a && b) {
        if (a->d == b->d) {
            tail->next = new Node(a->d);
            tail = tail->next;
            a = a->next; b = b->next;
        } else if (a->d < b->d) a = a->next;
        else b = b->next;
    }
    return dummy.next;
}

void print(Node* h) { while(h){ cout<<h->d<<" "; h=h->next; } cout<<"\n"; }

int main() {
    // A: 1 2 3 4 6
    Node* A = new Node(1); A->next=new Node(2); A->next->next=new Node(3);
    A->next->next->next=new Node(4); A->next->next->next->next=new Node(6);
    // B: 2 4 6 8
    Node* B = new Node(2); B->next=new Node(4); B->next->next=new Node(6); B->next->next->next=new Node(8);
    Node* common = intersectSorted(A,B);
    cout << "Common elements: "; print(common); // 2 4 6
    return 0;
}
