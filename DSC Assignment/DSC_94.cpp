// DSC_094_question.cpp
// 94. Word Wrap Problem (minimize square cost of extra spaces) - DP O(n^2)

#include <bits/stdc++.h>
using namespace std;
const long long INF = 9e18;
long long wordWrap(const vector<int>& words, int k){
    int n=words.size();
    vector<long long> dp(n+1, INF); dp[n]=0;
    for(int i=n-1;i>=0;--i){
        int len=0;
        for(int j=i;j<n;++j){
            len += (j==i?0:1) + words[j];
            if(len > k) break;
            long long cost = (j==n-1)?0:(long long)(k - len)*(k - len);
            dp[i] = min(dp[i], cost + dp[j+1]);
        }
    }
    return dp[0];
}
int main(){ cout<<wordWrap({3,2,2,5}, 6)<<"\n"; } // example
    