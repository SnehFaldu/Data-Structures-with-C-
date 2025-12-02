// DSC_109_question.cpp
// 109. Program to generate all possible valid IP addresses from given string.

#include <bits/stdc++.h>
using namespace std;
bool valid(const string &s){
    if(s.empty() || s.size()>3) return false;
    if(s.size()>1 && s[0]=='0') return false;
    int val = stoi(s);
    return val>=0 && val<=255;
}
vector<string> restoreIP(const string &s){
    vector<string> res;
    int n=s.size();
    for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) for(int k=1;k<=3;k++){
        int l = n - (i+j+k);
        if(l>=1 && l<=3){
            string a=s.substr(0,i), b=s.substr(i,j), c=s.substr(i+j,k), d=s.substr(i+j+k,l);
            if(valid(a)&&valid(b)&&valid(c)&&valid(d)) res.push_back(a+"."+b+"."+c+"."+d);
        }
    }
    return res;
}
int main(){
    for(auto &ip: restoreIP("25525511135")) cout<<ip<<"\n";
}
