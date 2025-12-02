// DSC_081_question.cpp
// 81. First negative integer in every window of size "k"

#include <bits/stdc++.h>
using namespace std;

vector<int> firstNegativeInWindow(const vector<int>& a, int k){
    deque<int> dq;
    vector<int> res;
    for(int i=0;i<a.size();++i){
        if(!dq.empty() && dq.front() <= i-k) dq.pop_front();
        if(a[i]<0) dq.push_back(i);
        if(i>=k-1){
            res.push_back(dq.empty()?0:a[dq.front()]);
        }
    }
    return res;
}

int main(){
    vector<int> a = {12, -1, -7, 8, -15, 30, 16, 28};
    for(int x: firstNegativeInWindow(a, 3)) cout<<x<<" ";
    cout<<"\n";
}
