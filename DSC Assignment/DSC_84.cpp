// DSC_084_question.cpp
// 84. Minimum sum of squares of character counts in a string after removing k characters.

#include <bits/stdc++.h>
using namespace std;
long long minSumSquares(string s, int k){
    vector<int> freq(26,0);
    for(char c: s) freq[c-'a']++;
    priority_queue<int> pq;
    for(int f: freq) if(f>0) pq.push(f);
    while(k-- && !pq.empty()){
        int t = pq.top(); pq.pop();
        if(--t>0) pq.push(t);
    }
    long long res=0;
    while(!pq.empty()){ long long v=pq.top(); pq.pop(); res += v*v; }
    return res;
}

int main(){
    cout<<minSumSquares("aabbccc", 2)<<"\n";
}
