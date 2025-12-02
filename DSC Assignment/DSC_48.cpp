// DSC_048_question.cpp
// 48. Rotate a Doubly Linked list in group of Given Size.
// Interpreting as: for each group of size k, rotate that group left by 1 (or reverse?).
// Here: rotate each group left by k (move first node of group to end) — but common problem is reversing groups.
// I'll implement: reverse nodes in groups of size k (useful and common).

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

Node* reverseGroup(Node* head, int k){
    if(!head || k<=1) return head;
    Node* cur = head;
    Node* newHead = nullptr;
    Node* groupPrev = nullptr;
    while(cur){
        int count=0;
        Node* groupHead = cur;
        // collect k nodes
        vector<Node*> nodes;
        for(; cur && count<k; ++count){
            nodes.push_back(cur);
            cur = cur->next;
        }
        if(count == k){
            // reverse pointers within nodes
            for(int i=k-1;i>=0;--i){
                if(!newHead) newHead = nodes[i];
                if(groupPrev) { groupPrev->next = nodes[i]; nodes[i]->prev = groupPrev; }
                groupPrev = nodes[i];
            }
        } else {
            // attach remaining as is
            for(int i=0;i<nodes.size();++i){
                if(!newHead) newHead = nodes[i];
                if(groupPrev){ groupPrev->next = nodes[i]; nodes[i]->prev = groupPrev; }
                groupPrev = nodes[i];
            }
        }
    }
    if(groupPrev) groupPrev->next = nullptr;
    return newHead;
}

void printF(Node* h){ while(h){ cout<<h->v<<" "; h=h->next; } cout<<"\n"; }

int main(){
    Node* a=new Node(1); Node* b=new Node(2); Node* c=new Node(3); Node* d=new Node(4); Node* e=new Node(5);
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d;
    cout<<"Before: "; printF(a);
    Node* r=reverseGroup(a, 2);
    cout<<"After reversing in groups of 2: "; printF(r);
    return 0;
}
