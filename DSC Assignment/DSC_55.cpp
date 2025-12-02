// DSC_055_question.cpp
// 55. Reverse a String using Stack

#include <bits/stdc++.h>
using namespace std;
string reverseWithStack(const string& s){
    stack<char> st;
    for(char c: s) st.push(c);
    string r;
    while(!st.empty()){ r.push_back(st.top()); st.pop(); }
    return r;
}
int main(){
    cout<<reverseWithStack("Hello World")<<"\n";
    return 0;
}
