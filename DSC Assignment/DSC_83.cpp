// DSC_083_question.cpp
// 83. Sum of minimum and maximum elements of all subarrays of size "k".

#include <bits/stdc++.h>
using namespace std;
long long sumMinMaxK(const vector<int>& a, int k){
    deque<int> minq, maxq;
    long long sum=0;
    for(int i=0;i<a.size();++i){
        if(!minq.empty() && minq.front()<=i-k) minq.pop_front();
        if(!maxq.empty() && maxq.front()<=i-k) maxq.pop_front();
        while(!minq.empty() && a[minq.back()]>=a[i]) minq.pop_back();
        while(!maxq.empty() && a[maxq.back()]<=a[i]) maxq.pop_back();
        minq.push_back(i); maxq.push_back(i);
        if(i>=k-1) sum += a[minq.front()] + a[maxq.front()];
    }
    return sum;
}

int main(){
    cout<<sumMinMaxK({2,5,-1,7,-3,-1,-2}, 4)<<"\n";
}
