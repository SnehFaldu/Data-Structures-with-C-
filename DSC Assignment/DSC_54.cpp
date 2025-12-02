// DSC_054_question.cpp
// 54. Check the expression has valid or Balanced parenthesis or not.

#include <bits/stdc++.h>
using namespace std;
bool isBalanced(const string& s){
    stack<char> st;
    for(char c: s){
        if(c=='('||c=='['||c=='{') st.push(c);
        else if(c==')'||c==']'||c=='}'){
            if(st.empty()) return false;
            char t=st.top(); st.pop();
            if((c==')' && t!='(') || (c==']' && t!='[') || (c=='}' && t!='{')) return false;
        }
    }
    return st.empty();
}
int main(){
    cout<<(isBalanced("({[]})") ? "Balanced\n" : "Not Balanced\n");
    cout<<(isBalanced("([)]") ? "Balanced\n" : "Not Balanced\n");
    return 0;
}
