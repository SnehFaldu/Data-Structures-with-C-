// DSC_041_question.cpp
// 41. Write a Program to check whether the Singly Linked list is a palindrome or not.

#include <bits/stdc++.h>
using namespace std;
struct Node { int v; Node* next; Node(int x):v(x),next(nullptr){} };

Node* midNode(Node* head){
    Node *slow=head,*fast=head;
    while(fast && fast->next){ slow=slow->next; fast=fast->next->next; }
    return slow;
}

Node* reverseList(Node* h){
    Node* p=nullptr;
    while(h){ Node* n=h->next; h->next=p; p=h; h=n; }
    return p;
}

bool isPalindrome(Node* head){
    if(!head || !head->next) return true;
    Node* mid = midNode(head);
    Node* second = reverseList(mid);
    Node* p=head; Node* q=second;
    bool ok = true;
    while(q){ if(p->v != q->v){ ok=false; break; } p=p->next; q=q->next; }
    // restore (optional)
    reverseList(second);
    return ok;
}

int main(){
    Node* h=new Node(1); h->next=new Node(2); h->next->next=new Node(2); h->next->next->next=new Node(1);
    cout << (isPalindrome(h) ? "Palindrome\n" : "Not Palindrome\n");
    return 0;
}
