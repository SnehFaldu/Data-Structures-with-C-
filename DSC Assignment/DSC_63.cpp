// DSC_063_question.cpp
// 63. Sort a Stack using recursion (ascending, smallest on top)

#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int>& s, int x){
    if(s.empty() || x > s.top()){ s.push(x); return; }
    int t = s.top(); s.pop();
    sortedInsert(s,x);
    s.push(t);
}

void sortStack(stack<int>& s){
    if(s.empty()) return;
    int t = s.top(); s.pop();
    sortStack(s);
    sortedInsert(s, t);
}

int main(){
    stack<int> s; for(int x: vector<int>{3,1,4,2}) s.push(x);
    sortStack(s);
    while(!s.empty()){ cout<<s.top()<<" "; s.pop(); } // prints 4 3 2 1 (largest on top)
    cout<<"\n";
    return 0;
}
