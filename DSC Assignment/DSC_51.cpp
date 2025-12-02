// DSC_051_question.cpp
// 51. Implement 2 stacks in an array (grow from both ends).

#include <bits/stdc++.h>
using namespace std;
struct TwoStacks {
    vector<int> a;
    int top1, top2;
    TwoStacks(int n=100): a(n), top1(-1), top2(n) {}
    void push1(int x){ if(top1+1==top2) throw runtime_error("overflow"); a[++top1]=x; }
    void push2(int x){ if(top2-1==top1) throw runtime_error("overflow"); a[--top2]=x; }
    void pop1(){ if(top1>=0) top1--; else throw runtime_error("underflow"); }
    void pop2(){ if(top2 < (int)a.size()) top2++; else throw runtime_error("underflow"); }
    int peek1(){ if(top1>=0) return a[top1]; else throw runtime_error("empty"); }
    int peek2(){ if(top2 < (int)a.size()) return a[top2]; else throw runtime_error("empty"); }
};

int main(){
    TwoStacks s(10);
    s.push1(1); s.push1(2); s.push2(9); s.push2(8);
    cout<<s.peek1()<<" "<<s.peek2()<<"\n";
    return 0;
}
