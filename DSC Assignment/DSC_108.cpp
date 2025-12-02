// DSC_108_question.cpp
// 108. Find the longest common subsequence between two strings.

#include <bits/stdc++.h>
using namespace std;
int lcs(const string& A, const string& B){
    int n=A.size(), m=B.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
        dp[i][j] = (A[i-1]==B[j-1])? dp[i-1][j-1]+1 : max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}
int main(){ cout<<lcs("AGGTAB","GXTXAYB")<<"\n"; } // 4
