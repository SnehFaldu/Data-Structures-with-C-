// DSC_082_question.cpp
// 82. Check if all levels of two trees are anagrams or not.

#include <bits/stdc++.h>
using namespace std;
struct Node{ int v; Node* l,*r; Node(int x):v(x),l(nullptr),r(nullptr){} };

bool areLevelsAnagrams(Node* a, Node* b){
    if(!a && !b) return true;
    queue<Node*> qa,qb; qa.push(a); qb.push(b);
    while(!qa.empty() && !qb.empty()){
        int na=qa.size(), nb=qb.size();
        if(na!=nb) return false;
        vector<int> va, vb;
        for(int i=0;i<na;++i){
            Node* pa=qa.front(); qa.pop();
            Node* pb=qb.front(); qb.pop();
            va.push_back(pa->v); vb.push_back(pb->v);
            if(pa->l) qa.push(pa->l); if(pa->r) qa.push(pa->r);
            if(pb->l) qb.push(pb->l); if(pb->r) qb.push(pb->r);
        }
        sort(va.begin(),va.end()); sort(vb.begin(),vb.end());
        if(va!=vb) return false;
    }
    return qa.empty() && qb.empty();
}

int main(){
    Node* A=new Node(1); A->l=new Node(3); A->r=new Node(2);
    Node* B=new Node(1); B->l=new Node(2); B->r=new Node(3);
    cout<<(areLevelsAnagrams(A,B)?"Yes\n":"No\n");
}
