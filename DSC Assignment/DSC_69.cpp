// DSC_069_question.cpp
// 69. Implement Stack using Deque

#include <bits/stdc++.h>
using namespace std;
struct StackUsingDeque {
    deque<int> d;
    void push(int x){ d.push_back(x); }
    void pop(){ if(!d.empty()) d.pop_back(); }
    int top(){ return d.back(); }
    bool empty(){ return d.empty(); }
};
int main(){
    StackUsingDeque s; s.push(5); s.push(10);
    cout<<s.top()<<"\n"; s.pop(); cout<<s.top()<<"\n";
    return 0;
}
