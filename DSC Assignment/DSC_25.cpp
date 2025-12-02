// DSC_025_question.cpp
// 25. Intersection Point of two Linked Lists. (find node where they merge by pointer)

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x): v(x), next(nullptr) {} };

// returns the intersection node pointer or nullptr
Node* getIntersection(Node* A, Node* B) {
    if(!A || !B) return nullptr;
    Node* p = A; Node* q = B;
    // When p reaches end, switch to B; when q reaches end, switch to A.
    // They will meet at intersection or both become nullptr.
    while (p != q) {
        p = p ? p->next : B;
        q = q ? q->next : A;
    }
    return p;
}

int main() {
    // Build lists: A: 1->2->3\
    //                     7->8
    //             B:    4->5/
    Node* common = new Node(7); common->next = new Node(8);

    Node* A = new Node(1); A->next = new Node(2); A->next->next = new Node(3);
    A->next->next->next = common;

    Node* B = new Node(4); B->next = new Node(5);
    B->next->next = common;

    Node* inter = getIntersection(A,B);
    if (inter) cout << "Intersection at node with value: " << inter->v << "\n";
    else cout << "No intersection\n";
    return 0;
}
