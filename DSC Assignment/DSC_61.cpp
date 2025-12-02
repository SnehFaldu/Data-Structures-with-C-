// DSC_061_question.cpp
// 61. Implement a method to insert an element at its bottom without using any other data structure.

#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& st, int x){
    if(st.empty()){ st.push(x); return; }
    int top = st.top(); st.pop();
    insertAtBottom(st, x);
    st.push(top);
}

int main(){
    stack<int> st; for(int i=1;i<=3;++i) st.push(i); // top=3
    insertAtBottom(st, 0);
    while(!st.empty()){ cout<<st.top()<<" "; st.pop(); } // prints 3 2 1 0
    cout<<"\n";
    return 0;
}
