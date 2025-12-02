// DSC_049_question.cpp
// 49. Implement Stack from Scratch (array-backed dynamic stack).

#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct MyStack {
    vector<T> data;
    void push(const T& x){ data.push_back(x); }
    void pop(){ if(!data.empty()) data.pop_back(); }
    T top() const { if(!data.empty()) return data.back(); throw runtime_error("empty"); }
    bool empty() const { return data.empty(); }
    int size() const { return (int)data.size(); }
};

int main(){
    MyStack<int> s;
    s.push(10); s.push(20); s.push(30);
    cout<<"Top: "<<s.top()<<"\n"; s.pop();
    cout<<"Top after pop: "<<s.top()<<"\n";
    return 0;
}
