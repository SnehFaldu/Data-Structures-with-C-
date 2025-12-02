// DSC_087_question.cpp
// 87. Check whether a string is a valid shuffle of two given strings

#include <bits/stdc++.h>
using namespace std;
bool isValidShuffle(const string& a, const string& b, const string& s){
    int i=0,j=0;
    for(char c: s){
        if(i<a.size() && c==a[i]) ++i;
        else if(j<b.size() && c==b[j]) ++j;
        else return false;
    }
    return i==a.size() && j==b.size();
}

int main(){
    cout<<(isValidShuffle("ab","12","a1b2")?"Yes\n":"No\n");
    cout<<(isValidShuffle("ab","12","1ab2")?"Yes\n":"No\n");
}
