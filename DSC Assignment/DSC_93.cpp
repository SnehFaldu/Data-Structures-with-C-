// DSC_093_question.cpp
// 93. Split the Binary string into two substring with equal 0’s and 1’s
// Count number of ways to split (prefix/suffix) where zeros and ones equal in both parts.

#include <bits/stdc++.h>
using namespace std;
int countSplits(const string& s){
    int n=s.size();
    vector<int> pref0(n), pref1(n);
    for(int i=0;i<n;++i){
        pref0[i] = (i?pref0[i-1]:0) + (s[i]=='0');
        pref1[i] = (i?pref1[i-1]:0) + (s[i]=='1');
    }
    int total0 = pref0[n-1], total1 = pref1[n-1], ans=0;
    for(int i=0;i<n-1;++i){
        if(pref0[i]==total0 - pref0[i] && pref1[i]==total1 - pref1[i]) ++ans;
    }
    return ans;
}
int main(){ cout<<countSplits("010110")<<"\n"; }
