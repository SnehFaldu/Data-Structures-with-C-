// DSC_098_question.cpp
// 98. Word Break Problem (can string be segmented into dictionary words)

#include <bits/stdc++.h>
using namespace std;
bool wordBreak(const string& s, const unordered_set<string>& dict){
    int n=s.size();
    vector<bool> dp(n+1,false); dp[0]=true;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            if(dp[j] && dict.count(s.substr(j,i-j))){ dp[i]=true; break; }
        }
    }
    return dp[n];
}
int main(){
    unordered_set<string> dict={"leet","code"};
    cout<<(wordBreak("leetcode", dict)?"Yes\n":"No\n");
}
