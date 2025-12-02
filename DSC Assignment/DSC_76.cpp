// DSC_076_question.cpp
// 76. Reverse the first “K” elements of a queue

#include <bits/stdc++.h>
using namespace std;
void reverseFirstK(queue<int>& q, int K){
    if(K<=0 || q.empty()) return;
    stack<int> st;
    for(int i=0;i<K && !q.empty(); ++i){ st.push(q.front()); q.pop(); }
    while(!st.empty()){ q.push(st.top()); st.pop(); }
    int t = q.size() - K;
    while(t--){ q.push(q.front()); q.pop(); }
}
int main(){
    queue<int> q; for(int i=1;i<=6;i++) q.push(i);
    reverseFirstK(q, 3);
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); } // 3 2 1 4 5 6
    cout<<"\n";
    return 0;
}
