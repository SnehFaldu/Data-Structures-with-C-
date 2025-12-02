// DSC_045_question.cpp
// 45. Count triplets in a sorted Doubly Linked List whose sum is equal to given value X.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

int countTriplets(Node* head, int X){
    if(!head) return 0;
    // get tail
    Node* tail=head; while(tail->next) tail=tail->next;
    int count=0;
    for(Node* a=head; a!=nullptr; a=a->next){
        Node* l = a->next;
        Node* r = tail;
        while(l && r && l!=r && r->next!=l){
            int sum = a->v + l->v + r->v;
            if(sum==X){ count++; l=l->next; r=r->prev; }
            else if(sum < X) l = l->next;
            else r = r->prev;
        }
    }
    return count;
}

int main(){
    Node* a=new Node(1); Node* b=new Node(2); Node* c=new Node(4); Node* d=new Node(5); Node* e=new Node(6);
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d;
    cout<<"Triplets count for sum=10: "<<countTriplets(a,10)<<"\n"; // e.g., 1+4+5, etc.
    return 0;
}
