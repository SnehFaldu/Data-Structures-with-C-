// DSC_097_question.cpp
// 97. Balanced Parenthesis problem: generate all balanced parentheses for n pairs (backtracking)

#include <bits/stdc++.h>
using namespace std;
void gen(int open,int close,string &cur, vector<string>& out){
    if(open==0 && close==0){ out.push_back(cur); return; }
    if(open>0){ cur.push_back('('); gen(open-1, close, cur, out); cur.pop_back(); }
    if(close>open){ cur.push_back(')'); gen(open, close-1, cur, out); cur.pop_back(); }
}
int main(){
    int n=3; vector<string> out; string cur;
    gen(n,n,cur,out);
    for(auto &s: out) cout<<s<<"\n";
}
