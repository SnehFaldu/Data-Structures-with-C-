// DSC_050_question.cpp
// 50. Implement Queue from Scratch (using circular buffer).

#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct MyQueue {
    vector<T> buf;
    int head=0, tail=0, cnt=0, cap=8;
    MyQueue(){ buf.resize(cap); }
    void ensure(){ if(cnt==cap){ vector<T> nbuf(cap*2); for(int i=0;i<cnt;i++) nbuf[i]=buf[(head+i)%cap]; buf.swap(nbuf); head=0; tail=cnt; cap*=2; } }
    void push(const T& x){ ensure(); buf[tail]=x; tail=(tail+1)%cap; ++cnt; }
    void pop(){ if(cnt){ head=(head+1)%cap; --cnt; } }
    T front() const { if(cnt) return buf[head]; throw runtime_error("empty"); }
    bool empty() const { return cnt==0; }
    int size() const { return cnt; }
};

int main(){
    MyQueue<int> q;
    q.push(1); q.push(2); q.push(3);
    cout<<"Front: "<<q.front()<<"\n"; q.pop();
    cout<<"Now front: "<<q.front()<<"\n";
    return 0;
}
