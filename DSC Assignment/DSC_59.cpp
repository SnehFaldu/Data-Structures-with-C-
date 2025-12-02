// DSC_059_question.cpp// 59. Arithmetic Expression evaluation (support + - * / and parentheses)
// Shunting-yard to postfix then evaluate.

#include <bits/stdc++.h>
using namespace std;

int prec(char op){ if(op=='+'||op=='-') return 1; if(op=='*'||op=='/') return 2; return 0; }
string toPostfix(const string& s){
    string out; stack<char> ops;
    for(size_t i=0;i<s.size();++i){
        char c=s[i];
        if(isspace(c)) continue;
        if(isdigit(c)){
            while(i<s.size() && isdigit(s[i])) out.push_back(s[i++]);
            out.push_back(' ');
            --i;
        } else if(c=='(') ops.push(c);
        else if(c==')'){ while(!ops.empty() && ops.top()!='('){ out.push_back(ops.top()); out.push_back(' '); ops.pop(); } if(!ops.empty()) ops.pop(); }
        else { while(!ops.empty() && prec(ops.top())>=prec(c)){ out.push_back(ops.top()); out.push_back(' '); ops.pop(); } ops.push(c); }
    }
    while(!ops.empty()){ out.push_back(ops.top()); out.push_back(' '); ops.pop(); }
    return out;
}

long long evalPostfix(const string& p){
    stack<long long> st; stringstream ss(p);
    string token;
    while(ss >> token){
        if(isdigit(token[0])){
            st.push(stoll(token));
        } else {
            long long b=st.top(); st.pop();
            long long a=st.top(); st.pop();
            if(token[0]=='+') st.push(a+b);
            else if(token[0]=='-') st.push(a-b);
            else if(token[0]=='*') st.push(a*b);
            else if(token[0]=='/') st.push(a/b);
        }
    }
    return st.top();
}

int main(){
    string expr = "3 + 4 * (2 - 1)";
    string pf = toPostfix(expr);
    cout<<expr<<" = "<<evalPostfix(pf)<<"\n";
    return 0;
}
