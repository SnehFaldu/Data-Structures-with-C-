// DSC_064_question.cpp
// 64. Merge Overlapping Intervals

#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> mergeIntervals(vector<pair<int,int>> a){
    if(a.empty()) return {};
    sort(a.begin(), a.end());
    vector<pair<int,int>> res; res.push_back(a[0]);
    for(size_t i=1;i<a.size();++i){
        auto &last = res.back();
        if(a[i].first <= last.second) last.second = max(last.second, a[i].second);
        else res.push_back(a[i]);
    }
    return res;
}
int main(){
    vector<pair<int,int>> v{{1,3},{2,6},{8,10},{15,18}};
    for(auto&p:mergeIntervals(v)) cout<<"["<<p.first<<","<<p.second<<"] ";
    cout<<"\n";
    return 0;
}
