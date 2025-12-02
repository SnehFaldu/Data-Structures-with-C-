// DSC_071_question.cpp
// 71. Implement Queue using two Stacks

#include <bits/stdc++.h>
using namespace std;
struct QueueUsingStacks {
    stack<int> s1, s2;
    void push(int x){ s1.push(x); }
    void pop(){ if(s2.empty()){ while(!s1.empty()){ s2.push(s1.top()); s1.pop(); } } if(!s2.empty()) s2.pop(); }
    int front(){ if(s2.empty()){ while(!s1.empty()){ s2.push(s1.top()); s1.pop(); } } return s2.top(); }
    bool empty(){ return s1.empty() && s2.empty(); }
};
int main(){
    QueueUsingStacks q; q.push(1); q.push(2); q.push(3);
    cout<<q.front()<<"\n"; q.pop(); cout<<q.front()<<"\n";
    return 0;
}
