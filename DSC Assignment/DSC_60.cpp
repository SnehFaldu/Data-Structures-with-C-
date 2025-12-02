// DSC_060_question.cpp
// 60. Evaluation of Postfix expression

#include <bits/stdc++.h>
using namespace std;
long long evalPostfix(const string& s){
    stack<long long> st; stringstream ss(s);
    string tok;
    while(ss>>tok){
        if(isdigit(tok[0])) st.push(stoll(tok));
        else {
            long long b=st.top(); st.pop();
            long long a=st.top(); st.pop();
            if(tok=="+") st.push(a+b);
            else if(tok=="-") st.push(a-b);
            else if(tok=="*") st.push(a*b);
            else if(tok=="/") st.push(a/b);
        }
    }
    return st.top();
}
int main(){
    cout<<evalPostfix("2 3 1 * + 9 -")<<"\n"; // 2 + 3*1 -9 = -4
    return 0;
}
