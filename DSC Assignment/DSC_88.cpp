// DSC_088_question.cpp
// 88. Count and Say problem (generate nth term)

#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n){
    string s="1";
    while(--n){
        string t; int i=0;
        while(i<s.size()){
            int j=i;
            while(j<s.size() && s[j]==s[i]) ++j;
            t += to_string(j-i);
            t.push_back(s[i]);
            i=j;
        }
        s.swap(t);
    }
    return s;
}

int main(){ cout<<countAndSay(5)<<"\n"; }
