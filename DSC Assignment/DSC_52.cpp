// DSC_052_question.cpp
// 52. Find the middle element of a stack
// Approach: maintain two stacks or use linked-list with middle pointer. Here simple: use vector.

#include <bits/stdc++.h>
using namespace std;
int middleOfStack(vector<int>& st){
    if(st.empty()) throw runtime_error("empty");
    return st[(st.size()-1)/2];
}

int main(){
    vector<int> st = {1,2,3,4,5}; // bottom->top
    cout<<"Middle element: "<<middleOfStack(st)<<"\n"; // prints 3
    return 0;
}
