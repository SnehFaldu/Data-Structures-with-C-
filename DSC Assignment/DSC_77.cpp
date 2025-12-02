// DSC_077_question.cpp
// 77. Interleave the first half of the queue with second half

#include <bits/stdc++.h>
using namespace std;
void interleave(queue<int>& q){
    int n = q.size();
    if(n%2!=0) throw runtime_error("requires even count");
    int half = n/2;
    stack<int> st;
    for(int i=0;i<half;i++){ st.push(q.front()); q.pop(); }
    while(!st.empty()){ q.push(st.top()); st.pop(); }
    for(int i=0;i<half;i++){ q.push(q.front()); q.pop(); }
    for(int i=0;i<half;i++){ st.push(q.front()); q.pop(); }
    while(!st.empty()){ q.push(st.top()); st.pop(); q.push(q.front()); q.pop(); }
}
int main(){
    queue<int> q; for(int i=1;i<=6;i++) q.push(i);
    interleave(q);
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); } // 1 4 2 5 3 6 (depending on approach)
    cout<<"\n";
    return 0;
}
