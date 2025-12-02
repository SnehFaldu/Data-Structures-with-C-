// DSC_106_question.cpp
// 106. Find the first repeated word in string.

#include <bits/stdc++.h>
using namespace std;
string firstRepeatedWord(const string& s){
    stringstream ss(s);
    string w;
    unordered_set<string> seen;
    while(ss >> w){
        string cleaned;
        for(char c: w) if(isalnum(c)) cleaned.push_back(tolower(c));
        if(seen.count(cleaned)) return cleaned;
        seen.insert(cleaned);
    }
    return "";
}
int main(){ cout<<firstRepeatedWord("This is a test. This test is simple.")<<"\n"; }
