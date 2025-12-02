// DSC_105_question.cpp
// 105. Number of flips to make binary string alternate (min flips to make it 0101.. or 1010..)

#include <bits/stdc++.h>
using namespace std;
int minFlips(string s){
    int cnt1=0,cnt2=0;
    for(int i=0;i<s.size();++i){
        char expected1 = (i%2==0)?'0':'1';
        char expected2 = (i%2==0)?'1':'0';
        if(s[i]!=expected1) cnt1++;
        if(s[i]!=expected2) cnt2++;
    }
    return min(cnt1,cnt2);
}
int main(){ cout<<minFlips("0100")<<"\n"; } // 1
