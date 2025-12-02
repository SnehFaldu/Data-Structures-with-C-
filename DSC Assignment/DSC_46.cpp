// DSC_046_question.cpp
// 46. Sort a "k"-sorted Doubly Linked list. [Very IMP]
// Approach: Use a min-heap of size k+1, extract and rebuild.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

Node* sortKSortedDLL(Node* head, int k){
    if(!head) return head;
    // push first k+1 nodes
    priority_queue<pair<int,Node*>, vector<pair<int,Node*>>, greater<pair<int,Node*>>> pq;
    Node* cur = head;
    for(int i=0; i<=k && cur; ++i){ pq.emplace(cur->v, cur); cur=cur->next; }
    Node* newHead = nullptr; Node* tail=nullptr;
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        Node* node = p.second;
        if(!newHead){ newHead = tail = node; tail->prev = nullptr; }
        else { tail->next = node; node->prev = tail; tail = node; }
        // push next from remaining list
        if(cur){ pq.emplace(cur->v, cur); cur = cur->next; }
    }
    tail->next = nullptr;
    return newHead;
}

void printForward(Node* h){ while(h){ cout<<h->v<<" "; h=h->next; } cout<<"\n"; }

int main(){
    // Example: k-sorted DLL: 3 1 2 6 4 5 (k=2 maybe)
    Node* a=new Node(3); Node* b=new Node(1); Node* c=new Node(2); Node* d=new Node(6); Node* e=new Node(4); Node* f=new Node(5);
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d; e->next=f; f->prev=e;
    cout<<"Before: "; printForward(a);
    Node* s = sortKSortedDLL(a, 2);
    cout<<"After: "; printForward(s);
    return 0;
}
