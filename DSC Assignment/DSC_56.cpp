// DSC_056_question.cpp
// 56. Design a Stack that supports getMin() in O(1) time and O(1) extra space.
// Trick: store difference values; keep current min separately.

#include <bits/stdc++.h>
using namespace std;
struct MinStack {
    long long minVal;
    vector<long long> st;
    bool empty(){ return st.empty(); }
    void push(long long x){
        if(st.empty()){ st.push_back(x); minVal = x; }
        else{
            if(x >= minVal) st.push_back(x);
            else { st.push_back(2*x - minVal); minVal = x; } // encoded
        }
    }
    void pop(){
        if(st.empty()) throw runtime_error("empty");
        long long t = st.back(); st.pop_back();
        if(t < minVal) minVal = 2*minVal - t;
    }
    long long top(){
        long long t = st.back();
        if(t < minVal) return minVal;
        else return t;
    }
    long long getMin(){ if(st.empty()) throw runtime_error("empty"); return minVal; }
};

int main(){
    MinStack s; s.push(3); s.push(5); cout<<s.getMin()<<"\n"; s.push(2); s.push(1); cout<<s.getMin()<<"\n";
    s.pop(); cout<<s.getMin()<<"\n";
    return 0;
}
