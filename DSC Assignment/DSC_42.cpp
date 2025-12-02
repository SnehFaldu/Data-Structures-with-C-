// DSC_042_question.cpp
// 42. Deletion from a Circular Linked List.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x):v(x),next(nullptr){} };

Node* deleteNodeCircular(Node* head, int key){
    if(!head) return nullptr;
    // single node
    if(head->next==head){
        if(head->v==key) { delete head; return nullptr; }
        else return head;
    }
    Node *cur=head,*prev=nullptr;
    // find node to delete
    do{
        prev = cur;
        cur = cur->next;
        if(cur->v==key) break;
    } while(cur!=head);
    if(cur->v!=key) return head; // not found
    prev->next = cur->next;
    if(cur==head) head = prev->next;
    delete cur;
    return head;
}

void printCircular(Node* head){
    if(!head){ cout<<"Empty\n"; return; }
    Node* cur=head;
    do{ cout<<cur->v<<" "; cur=cur->next; } while(cur!=head);
    cout<<"\n";
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2); head->next->next=new Node(3);
    head->next->next->next = head; // circular
    cout<<"Before: "; printCircular(head);
    head = deleteNodeCircular(head, 2);
    cout<<"After delete 2: "; printCircular(head);
    head = deleteNodeCircular(head, 1);
    cout<<"After delete 1: "; printCircular(head);
    return 0;
}
