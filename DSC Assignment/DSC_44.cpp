// DSC_044_question.cpp
// 44. Find pairs with a given sum in a DLL (assume DLL is sorted).

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* prev; Node* next; Node(int x):v(x),prev(nullptr),next(nullptr){} };

vector<pair<int,int>> findPairs(Node* head, int target){
    vector<pair<int,int>> res;
    if(!head) return res;
    Node* l = head;
    Node* r = head;
    while(r->next) r = r->next;
    while(l != r && r->next != l){
        int s = l->v + r->v;
        if(s==target){ res.emplace_back(l->v,r->v); l=l->next; r=r->prev; }
        else if(s < target) l = l->next;
        else r = r->prev;
    }
    return res;
}

int main(){
    // list: 1 2 4 5 6
    Node* a=new Node(1); Node* b=new Node(2); Node* c=new Node(4); Node* d=new Node(5); Node* e=new Node(6);
    a->next=b; b->prev=a; b->next=c; c->prev=b; c->next=d; d->prev=c; d->next=e; e->prev=d;
    auto pairs = findPairs(a, 7);
    for(auto &p: pairs) cout<<p.first<<" "<<p.second<<"\n";
    return 0;
}
