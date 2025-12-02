// DSC_053_question.cpp
// 53. Implement "N" stacks in an Array (using next array method).

#include <bits/stdc++.h>
using namespace std;
struct NStacks {
    int nStacks, cap;
    vector<int> arr, top, next;
    int freeIdx;
    NStacks(int k,int capacity): nStacks(k), cap(capacity), arr(capacity), top(k, -1), next(capacity) {
        for(int i=0;i<cap;i++) next[i]=i+1;
        next[cap-1] = -1;
        freeIdx=0;
    }
    void push(int sn, int val){
        if(freeIdx==-1) throw runtime_error("overflow");
        int idx = freeIdx;
        freeIdx = next[idx];
        arr[idx] = val;
        next[idx] = top[sn];
        top[sn] = idx;
    }
    void pop(int sn){
        if(top[sn]==-1) throw runtime_error("underflow");
        int idx = top[sn];
        top[sn] = next[idx];
        next[idx] = freeIdx;
        freeIdx = idx;
    }
    int peek(int sn){
        if(top[sn]==-1) throw runtime_error("empty");
        return arr[top[sn]];
    }
};

int main(){
    NStacks s(3, 10);
    s.push(0, 10); s.push(1, 20); s.push(2, 30);
    cout<<s.peek(1)<<"\n";
    return 0;
}
