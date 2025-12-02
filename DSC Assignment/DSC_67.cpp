// DSC_067_question.cpp
// 67. Expression contains redundant bracket or not

#include <bits/stdc++.h>
using namespace std;
bool hasRedundant(const string& s){
    stack<char> st;
    for(char c: s){
        if(c==')'){
            char top = st.top(); st.pop();
            bool foundOp = false;
            while(!st.empty() && top!='('){
                if(top=='+'||top=='-'||top=='*'||top=='/') foundOp = true;
                top = st.top(); st.pop();
            }
            if(!foundOp) return true;
        } else st.push(c);
    }
    return false;
}
int main(){
    cout<<(hasRedundant("((a+b))") ? "Yes\n" : "No\n"); // Yes
    cout<<(hasRedundant("(a+(b)/c)") ? "Yes\n" : "No\n"); // Yes? (b) redundant
    return 0;
}
