// DSC_102_question.cpp
// 102. Boyer Moore Algorithm for Pattern Searching (bad-character heuristic)

#include <bits/stdc++.h>
using namespace std;

vector<int> badCharTable(const string &pat){
    const int ALPH=256;
    vector<int> bad(ALPH, -1);
    for(int i=0;i<pat.size();++i) bad[(unsigned char)pat[i]] = i;
    return bad;
}

vector<int> boyerMooreSearch(const string &text, const string &pat){
    vector<int> res;
    int n=text.size(), m=pat.size();
    if(m==0) return res;
    auto bad = badCharTable(pat);
    int s=0;
    while(s <= n-m){
        int j = m-1;
        while(j>=0 && pat[j]==text[s+j]) --j;
        if(j<0){ res.push_back(s); s += (s+m < n) ? m - bad[(unsigned char)text[s+m]] : 1; }
        else s += max(1, j - bad[(unsigned char)text[s+j]]);
    }
    return res;
}

int main(){
    string t="ABAAABCD", p="ABC";
    auto pos = boyerMooreSearch(t,p);
    for(int x: pos) cout<<"Found at "<<x<<"\n";
}
