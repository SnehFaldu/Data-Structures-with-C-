// DSC_066_question.cpp
// 66. Length of the Longest Valid Substring of parentheses

#include <bits/stdc++.h>
using namespace std;
int longestValid(const string& s){
    stack<int> st; st.push(-1); int best=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='(') st.push(i);
        else {
            st.pop();
            if(st.empty()) st.push(i);
            else best = max(best, i - st.top());
        }
    }
    return best;
}
int main(){
    cout<<longestValid(")()())")<<"\n"; // 4
    return 0;
}
