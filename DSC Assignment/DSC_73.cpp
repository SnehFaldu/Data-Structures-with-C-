// DSC_073_question.cpp
// 73. Implement a Circular queue

#include <bits/stdc++.h>
using namespace std;
struct CircularQueue {
    vector<int> buf; int head=0, tail=0, size_=0;
    CircularQueue(int cap): buf(cap) {}
    bool empty(){ return size_==0; }
    bool full(){ return size_==buf.size(); }
    void push(int x){ if(full()) throw runtime_error("full"); buf[tail]=x; tail=(tail+1)%buf.size(); ++size_; }
    void pop(){ if(empty()) throw runtime_error("empty"); head=(head+1)%buf.size(); --size_; }
    int front(){ if(empty()) throw runtime_error("empty"); return buf[head]; }
};
int main(){
    CircularQueue q(3); q.push(1); q.push(2); q.push(3);
    cout<<q.front()<<"\n"; q.pop(); q.push(4); cout<<q.front()<<"\n";
    return 0;
}
