// DSC_099_question.cpp
// 99. Count All Palindromic Subsequence in a given String (DP, counts non-empty palindromic subsequences)
// Note: counts can be large; here simple DP O(n^2).

#include <bits/stdc++.h>
using namespace std;
long long countPalSubseq(const string& s){
    int n=s.size();
    vector<vector<long long>> dp(n, vector<long long>(n,0));
    for(int i=n-1;i>=0;--i){
        dp[i][i]=1;
        for(int j=i+1;j<n;++j){
            if(s[i]==s[j]) dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            else dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
        }
    }
    return dp[0][n-1];
}
int main(){ cout<<countPalSubseq("aaa")<<"\n"; } // multiple subsequences
