// DSC_085_question.cpp
// 85. Queue based approach for first non-repeating character in a stream.

#include <bits/stdc++.h>
using namespace std;
vector<char> firstNonRepeating(const string& stream){
    vector<int> cnt(256,0);
    queue<char> q;
    vector<char> ans;
    for(char c: stream){
        cnt[(unsigned char)c]++;
        if(cnt[(unsigned char)c]==1) q.push(c);
        while(!q.empty() && cnt[(unsigned char)q.front()]>1) q.pop();
        ans.push_back(q.empty()?'#':q.front());
    }
    return ans;
}

int main(){
    for(char c: firstNonRepeating("aabc")) cout<<c<<" ";
    cout<<"\n";
}
