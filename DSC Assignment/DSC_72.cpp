// DSC_072_question.cpp
// 72. Implement "n" queue in an array (similar to N stacks: use next array)

#include <bits/stdc++.h>
using namespace std;
struct NQueues {
    int k, cap;
    vector<int> arr, frontIdx, rearIdx, next;
    int freeIdx;
    NQueues(int k_, int cap_): k(k_), cap(cap_), arr(cap_), frontIdx(k_, -1), rearIdx(k_, -1), next(cap_) {
        for(int i=0;i<cap;i++) next[i]=i+1; next[cap-1] = -1; freeIdx=0;
    }
    void enqueue(int qi, int val){
        if(freeIdx==-1) throw runtime_error("full");
        int idx = freeIdx; freeIdx = next[idx];
        arr[idx]=val; next[idx]=-1;
        if(frontIdx[qi]==-1) frontIdx[qi]=rearIdx[qi]=idx;
        else { next[rearIdx[qi]] = idx; rearIdx[qi] = idx; }
    }
    int dequeue(int qi){
        if(frontIdx[qi]==-1) throw runtime_error("empty");
        int idx = frontIdx[qi];
        frontIdx[qi] = next[idx];
        if(frontIdx[qi]==-1) rearIdx[qi] = -1;
        next[idx] = freeIdx; freeIdx = idx;
        return arr[idx];
    }
};
int main(){
    NQueues q(3, 10);
    q.enqueue(0, 10); q.enqueue(1, 20); q.enqueue(2, 30);
    cout<<q.dequeue(0)<<"\n";
    return 0;
}
