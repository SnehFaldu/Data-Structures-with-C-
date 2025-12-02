// DSC_062_question.cpp
// 62. Reverse a stack using recursion

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st, int x){
    if(st.empty()){ st.push(x); return; }
    int t = st.top(); st.pop(); insertAtBottom(st, x); st.push(t);
}

void reverseStack(stack<int>& st){
    if(st.empty()) return;
    int t = st.top(); st.pop();
    reverseStack(st);
    insertAtBottom(st, t);
}

int main(){
    stack<int> s; for(int i=1;i<=4;++i) s.push(i); // top 4
    reverseStack(s);
    while(!s.empty()){ cout<<s.top()<<" "; s.pop(); } // prints 1 2 3 4
    cout<<"\n";
    return 0;
}
