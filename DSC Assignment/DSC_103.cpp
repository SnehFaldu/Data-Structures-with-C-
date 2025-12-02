// DSC_103_question.cpp
// 103. Converting Roman Numerals to Decimal

#include <bits/stdc++.h>
using namespace std;
int romanToInt(const string& s){
    unordered_map<char,int> mp{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int n=s.size(), res=0;
    for(int i=0;i<n;++i){
        if(i+1<n && mp[s[i]]<mp[s[i+1]]) res -= mp[s[i]];
        else res += mp[s[i]];
    }
    return res;
}
int main(){ cout<<romanToInt("MCMIV")<<"\n"; } // 1904
