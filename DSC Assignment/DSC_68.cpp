// DSC_068_question.cpp
// 68. Implement Stack using Queue

#include <bits/stdc++.h>
using namespace std;
struct StackUsingQueue {
    queue<int> q;
    void push(int x){ q.push(x); int n=q.size(); while(--n) { q.push(q.front()); q.pop(); } }
    void pop(){ if(!q.empty()) q.pop(); }
    int top(){ return q.front(); }
    bool empty(){ return q.empty(); }
};
int main(){
    StackUsingQueue s; s.push(1); s.push(2); s.push(3);
    cout<<s.top()<<"\n"; s.pop(); cout<<s.top()<<"\n";
    return 0;
}
