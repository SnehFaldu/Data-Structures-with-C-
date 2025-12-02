// DSC_091_question.cpp
// 91. Print all subsequences of a string (recursive, excluding empty)

#include <bits/stdc++.h>
using namespace std;
void subseq(const string& s, int idx, string cur, vector<string>& out){
    if(idx==s.size()){ if(!cur.empty()) out.push_back(cur); return; }
    subseq(s, idx+1, cur, out);
    subseq(s, idx+1, cur + s[idx], out);
}
int main(){
    vector<string> out;
    subseq("abc", 0, "", out);
    for(auto &t: out) cout<<t<<"\n";
}
