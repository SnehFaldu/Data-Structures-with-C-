// DSC_043_question.cpp
// 43. Reverse a Doubly Linked list.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

Node* reverseDLL(Node* head){
    Node* cur=head;
    Node* newHead=nullptr;
    while(cur){
        swap(cur->prev, cur->next);
        newHead = cur;
        cur = cur->prev; // because we swapped
    }
    return newHead;
}

void printForward(Node* h){ while(h){ cout<<h->v<<" "; h=h->next; } cout<<"\n"; }

int main(){
    Node* a=new Node(1);
    Node* b=new Node(2); a->next=b; b->prev=a;
    Node* c=new Node(3); b->next=c; c->prev=b;
    cout<<"Before: "; printForward(a);
    Node* r = reverseDLL(a);
    cout<<"After: "; printForward(r);
    return 0;
}
