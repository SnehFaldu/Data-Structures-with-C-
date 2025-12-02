// DSC_047_question.cpp
// 47. Rotate Doubly Linked list by N nodes (left rotation).

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

Node* rotateDLL(Node* head, int N){
    if(!head || N==0) return head;
    // get length & tail
    Node* tail=head; int len=1;
    while(tail->next){ tail=tail->next; ++len; }
    N %= len;
    if(N==0) return head;
    Node* cur = head;
    for(int i=1;i<N;i++) cur=cur->next;
    Node* newHead = cur->next;
    cur->next = nullptr;
    newHead->prev = nullptr;
    tail->next = head;
    head->prev = tail;
    return newHead;
}

void printF(Node* h){ while(h){ cout<<h->v<<" "; h=h->next; } cout<<"\n"; }

int main(){
    Node* a=new Node(1); Node* b=new Node(2); Node* c=new Node(3); Node* d=new Node(4);
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c;
    cout<<"Before: "; printF(a);
    Node* r = rotateDLL(a, 2);
    cout<<"After rotate by 2: "; printF(r);
    return 0;
}
