// DSC_075_question.cpp
// 75. Reverse a Queue using recursion

#include <bits/stdc++.h>
using namespace std;
void reverseQueue(queue<int>& q){
    if(q.empty()) return;
    int x = q.front(); q.pop();
    reverseQueue(q);
    q.push(x);
}
int main(){
    queue<int> q; for(int i=1;i<=4;i++) q.push(i);
    reverseQueue(q);
    while(!q.empty()){ cout<<q.front()<<" "; q.pop(); } // 4 3 2 1
    cout<<"\n";
    return 0;
}
