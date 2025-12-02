// DSC_089_question.cpp
// 89. Longest Palindromic Substring (expand around center)

#include <bits/stdc++.h>
using namespace std;
string longestPalSubstr(const string& s){
    int n=s.size(), start=0, len=1;
    auto expand=[&](int l,int r){
        while(l>=0 && r<n && s[l]==s[r]){ if(r-l+1>len){ len=r-l+1; start=l; } --l; ++r; }
    };
    for(int i=0;i<n;++i){
        expand(i,i); expand(i,i+1);
    }
    return s.substr(start,len);
}

int main(){ cout<<longestPalSubstr("babad")<<"\n"; } // "bab" or "aba"
