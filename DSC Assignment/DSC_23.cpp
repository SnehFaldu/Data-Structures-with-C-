
// 23. Add two numbers represented by linked lists.

#include <bits/stdc++.h>
using namespace std;
struct Node { int d; Node* next; Node(int x): d(x), next(nullptr) {} };

Node* reverseList(Node* h) {
    Node* p=nullptr;
    while (h) { Node* n=h->next; h->next=p; p=h; h=n; }
    return p;
}

Node* addLists(Node* a, Node* b) {
    a = reverseList(a);
    b = reverseList(b);
    Node* head = nullptr; Node* tail=nullptr;
    int carry=0;
    while (a || b || carry) {
        int sum = carry + (a? a->d:0) + (b? b->d:0);
        Node* node = new Node(sum%10);
        carry = sum/10;
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
        if (a) a=a->next; if (b) b=b->next;
    }
    return reverseList(head);
}

void printList(Node* h) { while(h){ cout<<h->d; h=h->next; } cout<<"\n"; }

int main() {
    // 243 + 564 = 807 (lists stored most-significant first)
    Node* a = new Node(2); a->next = new Node(4); a->next->next = new Node(3);
    Node* b = new Node(5); b->next = new Node(6); b->next->next = new Node(4);
    cout << "A: "; printList(a);
    cout << "B: "; printList(b);
    Node* sum = addLists(a,b);
    cout << "Sum: "; printList(sum);
    return 0;
}
